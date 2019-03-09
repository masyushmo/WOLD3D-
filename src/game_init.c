/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:42:54 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/14 10:42:55 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	player_init(t_player *player)
{
	player->coord_x = 1.5;
	player->coord_y = 1.5;
	player->dir_x = 1;
	player->dir_y = 0;
	player->plan_x = 0;
	player->plan_y = 0.90;
	player->speed_mov = 0.05;
	player->speed_rot = 0.05;
	player->shift = 1.5;
}

void	rays_init(t_player *player, t_ray *ray, t_core *core)
{
	ray->win_corx = 2 * core->win_x / (double)core->w - 1.0;
	ray->raydir_x = player->dir_x + player->plan_x * ray->win_corx;
	ray->raydir_y = player->dir_y + player->plan_y * ray->win_corx;
	ray->map_x = (int)player->coord_x;
	ray->map_y = (int)player->coord_y;
}

void	dda_init(t_dda *dda, t_ray *ray, t_player *player)
{
	dda->delta_x = fabs(1 / ray->raydir_x);
	dda->delta_y = fabs(1 / ray->raydir_y);
	dda->wall_hitt = 0;
	if (ray->raydir_x < 0)
	{
		dda->stepside_x = -1;
		dda->side_x = (player->coord_x - ray->map_x) * dda->delta_x;
	}
	else
	{
		dda->stepside_x = 1;
		dda->side_x = (ray->map_x + 1.0 - player->coord_x) * dda->delta_x;
	}
	if (ray->raydir_y < 0)
	{
		dda->stepside_y = -1;
		dda->side_y = (player->coord_y - ray->map_y) * dda->delta_y;
	}
	else
	{
		dda->stepside_y = 1;
		dda->side_y = (ray->map_y + 1.0 - player->coord_y) * dda->delta_y;
	}
}

void	structs_init(t_core *core)
{
	if (!(core->player = ft_memalloc(sizeof(t_player))))
		stop("\033[22;31mERROR: failed to malloc struct");
	if (!(core->ray = ft_memalloc(sizeof(t_ray))))
		stop("\033[22;31mERROR: failed to malloc struct");
	if (!(core->dda = ft_memalloc(sizeof(t_dda))))
		stop("\033[22;31mERROR: failed to malloc struct");
	if (!(core->paint = ft_memalloc(sizeof(t_paint))))
		stop("\033[22;31mERROR: failed to malloc struct");
	if (!(core->texture = ft_memalloc(sizeof(t_texture))))
		stop("\033[22;31mERROR: failed to malloc struct");
	if (!(core->sound = ft_memalloc(sizeof(t_sound))))
		stop("\033[22;31mERROR: failed to malloc struct");
}

void	core_init(t_core *core)
{
	core->quit = 0;
	core->w = W_X;
	core->h = W_Y;
	core->fog_dis = 5;
	structs_init(core);
	create_win(core);
	player_init(core->player);
	load_level(core->texture, core);
	core->sound->mus_n = 0;
	core->paint->shade = DARK;
}
