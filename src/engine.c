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
		if (dda->sideY < dda->sideX)
		{
			dda->sideY += dda->deltaY;
			core->mapY += dda->stepSideY;
			dda->s = 1;
		}
		else
		{
			dda->sideX += dda->deltaX;
			core->mapX += dda->stepSideX;
			dda->s = 0;
		}
		if (core->map[core->mapX][core->mapY] > 0)
			dda->wall_hitt = 1;
	}
}

void	game_calc(t_core *core)
{
	int x;

	x = 0;
	structs_init(core);
	player_init(core->player);
	while (x < W_X)
	{
		core->ray->winX = 2 * x / (double)W_X - 1;
		rays_init(core->player, core->ray);
		core->mapX = (int)core->player->coordX;/* position in map */
		core->mapY = (int)core->player->coordY;
		dda_init(core->dda, core->ray);
		dda_alg(core->dda, core);
	}

}
