/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:26:18 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/14 10:26:19 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	dda_alg(t_dda *dda, t_core *core)
{
	while (dda->wall_hitt == 0)
	{
		if (dda->side_x < dda->side_y)
		{
			dda->side_x += dda->delta_x;
			core->ray->map_x += dda->stepside_x;
			dda->s = 0;
		}
		else
		{
			dda->side_y += dda->delta_y;
			core->ray->map_y += dda->stepside_y;
			dda->s = 1;
		}
		if (core->map[core->ray->map_y][core->ray->map_x] > 0)
			dda->wall_hitt = 1;
	}
}

void	rays_calc(t_core *core)
{
	if (core->dda->s == 0)
		core->distance = (core->ray->map_x - core->player->coord_x + \
			(1 - core->dda->stepside_x) / 2) / core->ray->raydir_x;
	else
		core->distance = (core->ray->map_y - core->player->coord_y + \
			(1 - core->dda->stepside_y) / 2) / core->ray->raydir_y;
}

void	game_calc(t_core *core)
{
	core->win_x = -1;
	while (++core->win_x < core->w)
	{
		rays_init(core->player, core->ray, core);
		dda_init(core->dda, core->ray, core->player);
		dda_alg(core->dda, core);
		rays_calc(core);
		core->wall_h = (int)(core->h / core->distance);
		core->start = -core->wall_h / 2 + core->h / 2;
		if (core->start < 0)
			core->start = 0;
		core->end = core->wall_h / 2 + core->h / 2;
		if (core->end >= core->h)
			core->end = core->h - 1;
		paint(core);
	}
}

void	set_coord(t_core *core, t_player *player)
{
	if ((core->map[(int)player->coord_y][(int)player->coord_x]) != 0)
		while ((int)player->coord_x <= core->map_width - 1)
		{
			player->coord_x += 1.0;
			if ((core->map[(int)player->coord_y][(int)player->coord_x]) == 0)
				break ;
		}
	if ((int)player->coord_x == core->map_width)
		stop("\033[22;31mERROR: bad map!\n");
}

void	game_loop(t_core *core)
{
	core_init(core);
	set_coord(core, core->player);
	while (!(core->quit))
	{
		keyses(core);
		mouse(core);
		if (SDL_MUSTLOCK(core->surface))
			SDL_LockSurface(core->surface);
		game_calc(core);
		if (SDL_MUSTLOCK(core->surface))
			SDL_UnlockSurface(core->surface);
		spec_chunks(core);
		display_core(core);
	}
}
