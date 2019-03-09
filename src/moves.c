/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:49:17 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/26 14:49:17 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	move_up(t_core *core, t_player *player)
{
	if (core->map[(int)(player->coord_y)][(int)(player->coord_x
		+ player->dir_x * ((player->speed_mov + 0.2) * player->shift))] == 0)
		player->coord_x += player->dir_x * (player->speed_mov * player->shift);
	if (core->map[(int)(player->coord_y + player->dir_y * ((player->speed_mov +
		0.2) * player->shift))][(int)(player->coord_x)] == 0)
		player->coord_y += player->dir_y * (player->speed_mov * player->shift);
	move_sound(player, core->sound);
}

void	move_down(t_core *core, t_player *player)
{
	if (core->map[(int)(player->coord_y)][(int)(player->coord_x
		- player->dir_x * ((player->speed_mov + 0.2) * player->shift))] == 0)
		player->coord_x -= player->dir_x * (player->speed_mov * player->shift);
	if (core->map[(int)(player->coord_y - player->dir_y * ((player->speed_mov +
		0.2) * player->shift))][(int)(player->coord_x)] == 0)
		player->coord_y -= player->dir_y * (player->speed_mov * player->shift);
	move_sound(player, core->sound);
}

void	move_right(t_core *core, t_player *player)
{
	if (core->map[(int)(player->coord_y)][(int)(player->coord_x
		+ player->plan_x * ((player->speed_mov + 0.2) * player->shift))] == 0)
		player->coord_x += player->plan_x * (player->speed_mov * player->shift);
	if (core->map[(int)(player->coord_y + player->plan_y * ((player->speed_mov +
		0.2) * player->shift))][(int)(player->coord_x)] == 0)
		player->coord_y += player->plan_y * (player->speed_mov * player->shift);
	move_sound(player, core->sound);
}

void	move_left(t_core *core, t_player *player)
{
	if (core->map[(int)(player->coord_y)][(int)(player->coord_x
		- player->plan_x * ((player->speed_mov + 0.2) * player->shift))] == 0)
		player->coord_x -= player->plan_x * (player->speed_mov * player->shift);
	if (core->map[(int)(player->coord_y - player->plan_y * ((player->speed_mov +
		0.2) * player->shift))][(int)(player->coord_x)] == 0)
		player->coord_y -= player->plan_y * (player->speed_mov * player->shift);
	move_sound(player, core->sound);
}

void	move_sound(t_player *player, t_sound *sound)
{
	if (player->shift == 1.5)
	{
		if (!(Mix_Playing(-1)))
			Mix_PlayChannel(-1, sound->steps, 0);
	}
	else if (!(Mix_Playing(0)))
		Mix_PlayChannel(0, sound->run, 0);
}
