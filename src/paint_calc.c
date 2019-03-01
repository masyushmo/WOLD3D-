/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 12:57:26 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/24 12:57:26 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wallSide(t_core *core, t_paint *paint)
{
	if (core->dda->s == 0 && core->ray->rayDirX > 0)
	{
		paint->floorX = core->ray->mapX;
		paint->floorY = core->ray->mapY + paint->wallX;
	}
	else if (core->dda->s == 0 && core->ray->rayDirX < 0)
	{
		paint->floorX = core->ray->mapX + 1.0;
		paint->floorY = core->ray->mapY + paint->wallX;
	}
	else if (core->dda->s == 1 && core->ray->rayDirY > 0)
	{
		paint->floorX = core->ray->mapX + paint->wallX;
		paint->floorY = core->ray->mapY;
	}
	else
	{
		paint->floorX = core->ray->mapX + paint->wallX;
		paint->floorY = core->ray->mapY + 1.0;
	}
}

void	paint_floor(t_core *core, t_paint *paint)
{
	int	y;
	int	color;

	wallSide(core, paint);
	paint->floorWall = core->distance;
	paint->floorPlayer = 0.0;
	if (core->pEnd < 0)
		core->pEnd = core->h;
	y = core->pEnd - 1;
	while (++y < core->h)
	{
		paint->Dist = core->h / (2.0 * y - core->h);
		paint->floorW_X = (paint->Dist - paint->floorPlayer) /
			(paint->floorWall - paint->floorPlayer);
		paint->newFloorX = paint->floorW_X * paint->floorX + \
			(1.0 - paint->floorW_X) * core->player->coordX;
		paint->newFloorY = paint->floorW_X * paint->floorY + \
			(1.0 - paint->floorW_X) * core->player->coordY;
		paint->floorTexX = (int)(paint->newFloorX * 64) % 64;
		paint->floorTexY = (int)(paint->newFloorY * 64) % 64;
		color = pix_from_text(core->texture->wall_TEX[2], \
			paint->floorTexX, paint->floorTexY);
		pix_to_surf(core->surface, core->win_pixX, core->h - y, color);
		color = pix_from_text(core->texture->wall_TEX[1], \
			paint->floorTexX, paint->floorTexY);
		pix_to_surf(core->surface, core->win_pixX, y, color);
	}
}

void	paint_wall(t_core *core, t_paint *paint)
{
	int color;

	paint->tex_num = core->map[core->ray->mapY][core->ray->mapX] - 1;
	if (core->dda->s == 0)
		paint->wallX = core->player->coordY + core->distance * \
			core->ray->rayDirY;
	else
		paint->wallX = core->player->coordX + core->distance * \
			core->ray->rayDirX;
	paint->wallX -= floorl(paint->wallX);
	paint->texX = (int)(paint->wallX * (double)64);
	if (core->dda->s == 0 && core->ray->rayDirX > 0)
		paint->texX = 64 - paint->texX - 1;
	if (core->dda->s == 1 && core->ray->rayDirY < 0)
		paint->texX = 64 - paint->texX - 1;
	core->win_pixY = core->pStart;
	while (++core->win_pixY < core->pEnd)
	{
		paint->dormamu = core->win_pixY * 256 - core->h * 128 + \
			core->wall_h * 128;
		paint->texY = ((paint->dormamu * 64) / core->wall_h / 256);
		if (core->dda->s == 1)
			color = pix_from_text(core->texture->wall_TEY[0], \
				paint->texX, paint->texY);
		else
			color = pix_from_text(core->texture->wall_TEX[core->paint->tex_num], \
				paint->texX, paint->texY);
		pix_to_surf(core->surface, core->win_pixX, core->win_pixY, color);
	}
}