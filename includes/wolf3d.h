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
# define EXIT (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)

typedef struct		s_player
{
	double			coordX;
	double			coordY;
	double			dirX;
	double			dirY;
	double			planX;
	double			planY;
	double			newscr;
	double			oldscr;
}					t_player;

typedef struct		s_ray
{
	double			rayX;
	double			rayY;
	double			winX; 
	double			rayDirX;
	double			rayDirY;
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

typedef struct		s_core
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*tex;
	int				map_width;
	int				map_height;
	int				**map;
	int				mapX;
	int				mapY;
	t_player		*player;
	t_ray			*ray;
	t_dda			*dda;
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
/*
**engine.c
*/
void				game_calc(t_core *core);
void				dda_alg(t_dda *dda, t_core *core);

#endif