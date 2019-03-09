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

void	wall_side(t_core *core, t_paint *paint)
{
	if (core->dda->s == 0 && core->ray->raydir_x > 0)
	{
		paint->floor_x = core->ray->map_x;
		paint->floor_y = core->ray->map_y + paint->wall_x;
	}
	else if (core->dda->s == 0 && core->ray->raydir_x < 0)
	{
		paint->floor_x = core->ray->map_x + 1.0;
		paint->floor_y = core->ray->map_y + paint->wall_x;
	}
	else if (core->dda->s == 1 && core->ray->raydir_y > 0)
	{
		paint->floor_x = core->ray->map_x + paint->wall_x;
		paint->floor_y = core->ray->map_y;
	}
	else
	{
		paint->floor_x = core->ray->map_x + paint->wall_x;
		paint->floor_y = core->ray->map_y + 1.0;
	}
}

void	paint_floor_add(t_core *core, t_paint *paint, int y)
{
	int	color;

	if ((((int)(paint->newfloor_x) + (int)(paint->newfloor_y)) % 2) == 0)
		color = pix_from_text(core->texture->floor_tex[0], \
			paint->floortex_x, paint->floortex_y);
	else
		color = pix_from_text(core->texture->floor_tex[1], \
			paint->floortex_x, paint->floortex_y);
	if (paint->shade != 1)
		color = color_value(color, paint->shade, \
			(core->dark > 1 ? 1 : core->dark));
	pix_to_surf(core->surface, core->win_x, y, color);
	if ((((int)(paint->newfloor_x + paint->newfloor_y)) % 2) != 0)
		color = pix_from_text(core->texture->cell_tex[0], \
		paint->floortex_x, paint->floortex_y);
	else
		color = pix_from_text(core->texture->cell_tex[1], \
			paint->floortex_x, paint->floortex_y);
	if (paint->shade != 1)
		color = color_value(color, paint->shade, \
			(core->dark > 1 ? 1 : core->dark));
	pix_to_surf(core->surface, core->win_x, core->h - y, color);
}

void	paint_wall_add(t_core *core, t_paint *paint)
{
	int color;

	color = 0x0000FF;
	if (core->name == 0)
		color = set_sample(core, core->paint);
	else
	{
		if (core->dda->s == 1)
			color = pix_from_text(core->texture->wall_tex \
				[core->paint->tex_num], paint->tex_x, paint->tex_y);
		else
			color = pix_from_text(core->texture->wall_tey \
				[core->paint->tex_num], paint->tex_x, paint->tex_y);
	}
	if (paint->shade != 1)
		color = color_value(color, paint->shade, \
			(core->dark > 1 ? 1 : core->dark));
	pix_to_surf(core->surface, core->win_x, core->win_y, color);
}

void	paint_floor(t_core *core, t_paint *paint)
{
	int	y;

	wall_side(core, paint);
	paint->floor_wall = core->distance;
	paint->floor_player = 0.0;
	if (core->end < 0)
		core->end = core->h;
	y = core->end - 1;
	while (++y < core->h)
	{
		paint->fl_dist = core->h / (2.0 * y - core->h);
		core->dark = (core->paint->fl_dist / core->fog_dis);
		paint->floor_width = (paint->fl_dist - paint->floor_player) /
			(paint->floor_wall - paint->floor_player);
		paint->newfloor_x = paint->floor_width * paint->floor_x + \
			(1.0 - paint->floor_width) * core->player->coord_x;
		paint->newfloor_y = paint->floor_width * paint->floor_y + \
			(1.0 - paint->floor_width) * core->player->coord_y;
		paint->floortex_x = (int)(paint->newfloor_x * 64) % 64;
		paint->floortex_y = (int)(paint->newfloor_y * 64) % 64;
		paint_floor_add(core, core->paint, y);
	}
}

void	paint_wall(t_core *core, t_paint *paint)
{
	paint->tex_num = core->map[core->ray->map_y][core->ray->map_x] - 1;
	if (core->dda->s == 0)
		paint->wall_x = core->player->coord_y + core->distance * \
			core->ray->raydir_y;
	else
		paint->wall_x = core->player->coord_x + core->distance * \
			core->ray->raydir_x;
	paint->wall_x -= floorl(paint->wall_x);
	paint->tex_x = (int)(paint->wall_x * (double)64);
	if (core->dda->s == 0 && core->ray->raydir_x > 0)
		paint->tex_x = 64 - paint->tex_x - 1;
	if (core->dda->s == 1 && core->ray->raydir_y < 0)
		paint->tex_x = 64 - paint->tex_x - 1;
	core->win_y = core->start;
	core->dark = (core->distance / core->fog_dis);
	while (++core->win_y < core->end)
	{
		paint->dormamu = core->win_y * 256 - core->h * 128 + \
		core->wall_h * 128;
		paint->tex_y = ((paint->dormamu * 64) / core->wall_h / 256);
		paint_wall_add(core, paint);
	}
}
