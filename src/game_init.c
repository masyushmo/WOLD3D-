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

void structs_init(t_core *core)
{
	if (!(core->player = ft_memalloc(sizeof(t_player))))
		stop("\033[22;31mERROR: failed to malloc struct");
	if (!(core->ray = ft_memalloc(sizeof(t_ray))))
		stop("\033[22;31mERROR: failed to malloc struct");
	if (!(core->dda = ft_memalloc(sizeof(t_dda))))
		stop("\033[22;31mERROR: failed to malloc struct");
}

void player_init(t_player *player)
{
	player->coordX = 22;
	player->coordY = 12;
	player->dirX = -1;
	player->dirY = 0;
	player->planX = 0;
	player->planY = 0.66;
	player->oldscr = 0;
	player->newscr = 0;
}

void rays_init(t_player *player, t_ray *ray)
{
	ray->rayX = player->coordX;/* ray coord */
	ray->rayY = player->coordY;
	ray->rayDirX = player->dirX + player->planX * ray->winX;/* ray direction */
	ray->rayDirY = player->dirY + player->planY * ray->winX;
}

void dda_init(t_dda *dda, t_ray *ray)
{
	dda->deltaX = abs(1 / ray->rayDirX);/*calc distance to next int x,y */
	dda->deltaY = abs(1 / ray->rayDirY);
	dda->wall_hitt = 0;
	if (ray->rayDirX < 0) /* calc distance to x,y square side(aka int x,y) */
	{
		dda->stepSideX = -1;
		dda->sideX = (ray->rayX - ray->mapX) * dda->deltaX;
	}
	else
	{
		dda->stepSideX = 1;
		dda->sideX = (ray->mapX + 1.0 - ray->rayX) * dda->deltaX;
	}
	if (ray->rayY < 0)
	{
		dda->stepSideY = -1;
		dda->sideY = (ray->rayY - ray->mapY) * dda->deltaY;
	}
	else
	{
		dda->stepSideY = 1;
		dda->sideY = (ray->mapY + 1.0 - ray->rayY) * dda->deltaY;
	}
}