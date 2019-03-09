/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:48:17 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/11 12:48:17 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <math.h>
# include <fcntl.h>
# define W_X 1280
# define W_Y 720
# define DARK 0x000000
# define FOG 0xD8D5D1
# define EXIT (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)

typedef struct		s_player
{
	double			coord_x;
	double			coord_y;
	double			dir_x;
	double			dir_y;
	double			plan_x;
	double			plan_y;
	double			speed_rot;
	double			speed_mov;
	double			shift;
}					t_player;

typedef struct		s_ray
{
	double			win_corx;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
}					t_ray;

typedef struct		s_dda
{
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	int				stepside_x;
	int				stepside_y;
	int				wall_hitt;
	int				s;
}					t_dda;

typedef struct		s_paint
{
	int				tex_num;
	int				tex_x;
	int				tex_y;
	int				dormamu;
	int				color;
	int				floortex_x;
	int				floortex_y;
	int				shade;
	double			wall_x;
	double			floor_x;
	double			floor_y;
	double			floor_wall;
	double			floor_player;
	double			fl_dist;
	double			newfloor_x;
	double			newfloor_y;
	double			floor_width;
}					t_paint;

typedef struct		s_texture
{
	SDL_Surface		**wall_tex;
	SDL_Surface		**wall_tey;
	SDL_Surface		**floor_tex;
	SDL_Surface		**cell_tex;
	SDL_Surface		**sky_tex;
}					t_texture;

typedef struct		s_sound
{
	Mix_Music		*music[5];
	Mix_Chunk		*steps;
	Mix_Chunk		*run;
	Mix_Chunk		*lcrip[7];
	int				mus_n;
}					t_sound;

typedef struct		s_gun
{
	SDL_Rect		rect;
	int				frame_w;
	int				frame_h;
	int				tx_w;
	int				tx_h;
}					t_gun;

typedef struct		s_core
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*tex;
	SDL_Rect		*rect;
	SDL_Surface		*surface;
	int				win_x;
	int				win_y;
	int				w;
	int				h;
	int				map_width;
	int				map_height;
	int				**map;
	double			distance;
	int				wall_h;
	int				start;
	int				end;
	int				name;
	double			dark;
	int				fog_dis;
	char			quit;
	t_player		*player;
	t_ray			*ray;
	t_dda			*dda;
	t_paint			*paint;
	t_texture		*texture;
	t_sound			*sound;
}					t_core;

/*
**main.c
*/
int					main(int argc, char **argv);
int					stop(char *str);
void				chose(t_core *core, char *name);
/*
**sdl.c
*/
void				create_win(t_core *core);
void				display_core(t_core *core);
SDL_Surface			*load_tex(char *path, t_core *core);
void				sdl_clean(t_core *core);
/*
**read.c
*/
int					read_map(t_core *core, char *file);
int					count(t_core *core, int fd);
int					check(char *line);
int					map(t_core *core, int fd);
int					check_map(t_core *core);
/*
**game_init.c
*/
void				player_init(t_player *player);
void				rays_init(t_player *player, t_ray *ray, t_core *core);
void				dda_init(t_dda *dda, t_ray *ray, t_player *player);
void				structs_init(t_core *core);
void				core_init(t_core *core);
/*
**engine.c
*/
void				game_loop(t_core *core);
void				game_calc(t_core *core);
void				dda_alg(t_dda *dda, t_core *core);
void				rays_calc(t_core *core);
void				set_coord(t_core *core, t_player *player);
/*
**paint.c
*/
int					color_value(Uint32 start, Uint32 end, float per);
Uint32				pix_from_text(SDL_Surface *texture, int x, int y);
void				pix_to_surf(SDL_Surface *surface, \
						int x, int y, Uint32 color);
void				paint(t_core *core);
/*
**paint_calc.c
*/
void				paint_wall(t_core *core, t_paint *paint);
void				paint_floor(t_core *core, t_paint *paint);
void				wall_side(t_core *core, t_paint *paint);
void				paint_floor_add(t_core *core, t_paint *paint, int y);
void				paint_wall_add(t_core *core, t_paint *paint);
/*
**keys.c
*/
void				keyses(t_core *core);
void				keyses_addon(t_core *core, const Uint8 *state);
void				rotate_left(t_player *player);
void				rotate_right(t_player *player);
void				mouse(t_core *core);
/*
**moves.c
*/
void				move_up(t_core *core, t_player *player);
void				move_down(t_core *core, t_player *player);
void				move_left(t_core *core, t_player *player);
void				move_right(t_core *core, t_player *player);
void				move_sound(t_player *player, t_sound *sound);
/*
**textures.c
*/
void				load_level(t_texture *texture, t_core *core);
void				f_c_tex(t_texture *texture, t_core *core);
void				wall_tex(t_texture *texture, t_core *core);
void				load_sound(t_sound *sound);
int					set_sample(t_core *core, t_paint *paint);
/*
**maps
*/
void				labrint(t_core *core);
void				wall_lab(t_texture *texture, t_core *core);
void				f_c_lab(t_texture *texture, t_core *core);
void				load_sound_lab(t_sound *sound);
void				minecraft(t_core *core);
void				wall_min(t_texture *texture, t_core *core);
void				f_c_min(t_texture *texture, t_core *core);
void				load_sound_min(t_sound *sound);
/*
**sound.c
*/
void				play_music(t_sound *sound, int n);
void				switch_music(t_sound *sound, const Uint8 *state);
void				spec_chunks(t_core *core);
Mix_Music			*load_mus(char *path);
Mix_Chunk			*load_sou(char	*path);

#endif
