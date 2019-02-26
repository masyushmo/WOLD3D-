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

void	texture_init(t_texture *texture, t_core *core)
{
	if (!(texture->wall_TEX = ft_memalloc(sizeof(SDL_Surface) * WALL_TEXTS)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->wall_TEX[0] = load_texture("./textures/wall/Stone1.bmp", core);
	texture->wall_TEX[1] = load_texture("./textures/wall/Purple1.bmp", core);
	texture->wall_TEX[2] = load_texture("./textures/wall/Red13.bmp", core);
	texture->wall_TEX[3] = load_texture("./textures/wall/Orange23.bmp", core);
	texture->wall_TEX[4] = load_texture("./textures/wall/Mil2.bmp", core);
	texture->wall_TEX[5] = load_texture("./textures/wall/Brown21.bmp", core);
	texture->wall_TEX[6] = load_texture("./textures/wall/Blue9.bmp", core);
	texture->wall_TEX[7] = load_texture("./textures/wall/Blue17.bmp", core);
}

void	player_init(t_player *player)
{
	player->coordX = 2;
	player->coordY = 2;
	player->dirX = -1;
	player->dirY = 0;
	player->planX = 0;
	player->planY = 0.66;
	player->speedMOVE= 0.1;
	player->speedROT = 0.1;
}

void	rays_init(t_player *player, t_ray *ray)
{
	ray->rayX = player->coordX;
	ray->rayY = player->coordY;
	ray->rayDirX = player->dirX + player->planX * ray->winX;
	ray->rayDirY = player->dirY + player->planY * ray->winX;
	ray->mapX = (int)ray->rayX;
	ray->mapY = (int)ray->rayY;
}

void	dda_init(t_dda *dda, t_ray *ray)
{
	dda->deltaX = sqrt(1 + (ray->rayDirY * ray->rayDirY) /
		(ray->rayDirX * ray->rayDirX));
	dda->deltaY = sqrt(1 + (ray->rayDirX * ray->rayDirX) /
		(ray->rayDirY * ray->rayDirY));
	dda->wall_hitt = 0;
	if (ray->rayDirX < 0)
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
	if (!(core->keys = ft_memalloc(sizeof(t_keys))))
		stop("\033[22;31mERROR: failed to malloc struct");
}
