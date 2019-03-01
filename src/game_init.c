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
	player->coordX = 2;
	player->coordY = 2;
	player->dirX = 1;
	player->dirY = 0;
	player->planX = 0;
	player->planY = 0.75;
	player->speedMOVE= 0.1;
	player->speedROT = 0.1;
}

void	rays_init(t_player *player, t_ray *ray, t_core *core)
{
	ray->winX = 2 * core->win_pixX / (double)core->w - 1.0;
	ray->rayX = player->coordX;
	ray->rayY = player->coordY;
	ray->rayDirX = player->dirX + player->planX * ray->winX;
	ray->rayDirY = player->dirY + player->planY * ray->winX;
	ray->mapX = (int)player->coordX;
	ray->mapY = (int)player->coordY;
}

void	dda_init(t_dda *dda, t_ray *ray, t_player *player)
{
	dda->deltaX = fabs(1 / ray->rayDirX);
	dda->deltaY = fabs(1 / ray->rayDirY);
	dda->wall_hitt = 0;
	if (ray->rayDirX < 0)
	{
		dda->stepSideX = -1;
		dda->sideX = (player->coordX - ray->mapX) * dda->deltaX;
	}
	else
	{
		dda->stepSideX = 1;
		dda->sideX = (ray->mapX + 1.0 - player->coordX) * dda->deltaX;
	}
	if (ray->rayDirY < 0)
	{
		dda->stepSideY = -1;
		dda->sideY = (player->coordY - ray->mapY) * dda->deltaY;
	}
	else
	{
		dda->stepSideY = 1;
		dda->sideY = (ray->mapY + 1.0 - player->coordY) * dda->deltaY;
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
}
