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

void	paint_wall(t_core *core, t_paint *paint)
{
	paint->tex_num = core->map[core->ray->mapX][core->ray->mapY] - 1;
	if (core->dda->s == 0)
		paint->wallX = core->ray->rayY + core->ray->distance * \
			core->ray->rayDirY;
	else
		paint->wallX = core->ray->rayX + core->ray->distance * \
			core->ray->rayDirX;
	paint->wallX -= floor(paint->wallX);
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
		pix_to_surf(core->surface, core);
	}
}
