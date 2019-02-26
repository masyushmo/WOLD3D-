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
# define WALL_TEXTS 8
# define EXIT (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)

typedef struct		s_player
{
	double			coordX;
	double			coordY;
	double			dirX;
	double			dirY;
	double			planX;
	double			planY;
	double			speedROT;
	double			speedMOVE;
}					t_player;

typedef struct		s_ray
{
	double			rayX;
	double			rayY;
	double			winX; 
	double			rayDirX;
	double			rayDirY;
	double			distance;
	int				mapX;
	int				mapY;
}					t_ray;

typedef struct		s_dda
{
	double			sideX;
	double			sideY;
	double			deltaX;
	double			deltaY;
	int				stepSideX; 
	int				stepSideY;
	int				wall_hitt;
	int				s;
}					t_dda;

typedef struct		s_paint
{
	int				tex_num;
	int				texX;
	int				texY;
	int				dormamu;
	int				color;
	double			wallX;
}					t_paint;

typedef struct		s_texture
{
	SDL_Surface		**wall_TEX;
	SDL_Surface		*flor_TEX;
	SDL_Surface		*cel_TET;
	SDL_Surface		**weapon;
	SDL_Surface		**enemys;
}					t_texture;

typedef struct		s_keys
{
	char			key[SDL_NUM_SCANCODES];
	char 			exit;
}					t_keys;

typedef struct		s_core
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*tex;
	SDL_Rect		*rect;
	SDL_Surface		*surface;
	int				tixe;
	int				win_pixX;
	int				win_pixY;
	int				w;
	int				h;
	int				map_width;
	int				map_height;
	int				**map;
	int				**buff;
	double			distance;
	int				wall_h;
	int				pStart;
	int				pEnd;
	t_player		*player;
	t_ray			*ray;
	t_dda			*dda;
	t_paint			*paint;
	t_texture		*texture;
	t_keys 			*keys;
}					t_core;

/*
**main.c
*/
int					main(int argc, char **argv);
int					stop(char *str);
void				start(t_core *core);
/*
**sdl.c
*/
void				create_win(t_core *core);
void				create_surface(t_core *core);
void				display_core(t_core *core);
SDL_Surface			*load_texture(char *path, t_core *core);
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
void				rays_init(t_player *player, t_ray *ray);
void				dda_init(t_dda *dda, t_ray *ray);
void				structs_init(t_core *core);
void				texture_init(t_texture *texture, t_core *core);
/*
**engine.c
*/
void				game_loop(t_core *core);
void				game_calc(t_core *core);
void				dda_alg(t_dda *dda, t_core *core);
void				rays_calc(t_core *core);
/*
**paint.c
*/
Uint32				pix_from_text(SDL_Surface *texture, t_core *core);
void				pix_to_surf(SDL_Surface *surf, t_core *core);
void				paint(t_core *core);
/*
**paint_calc.c
*/
void				paint_wall(t_core *core, t_paint *paint);
/*
**keys .c
*/
void				keyses(t_core *core);
void				rotateLEFT(t_core *core, t_player *player);
void				rotateRIGHT(t_core *core, t_player *player);
/*
**moves .c
*/
void				moveUP(t_core *core, t_player *player);
void				moveDOWN(t_core *core, t_player *player);
void				moveLEFT(t_core *core, t_player *player);
void				moveRIGHT(t_core *core, t_player *player);

#endif