/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:25:52 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/26 11:25:52 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	rotate_left(t_player *player)
{
	double save_dis;
	double save_plane;

	save_dis = player->dir_x;
	save_plane = player->plan_x;
	player->dir_x = player->dir_x * cos(-player->speed_rot * player->shift) - \
		player->dir_y * sin(-player->speed_rot * player->shift);
	player->dir_y = save_dis * sin(-player->speed_rot * player->shift) + \
		player->dir_y * cos(-player->speed_rot * player->shift);
	player->plan_x = player->plan_x * cos(-player->speed_rot * player->shift) -
		player->plan_y * sin(-player->speed_rot * player->shift);
	player->plan_y = save_plane * sin(-player->speed_rot * player->shift) + \
		player->plan_y * cos(-player->speed_rot * player->shift);
}

void	rotate_right(t_player *player)
{
	double save_dis;
	double save_plane;

	save_dis = player->dir_x;
	save_plane = player->plan_x;
	player->dir_x = player->dir_x * cos(player->speed_rot * player->shift) - \
		player->dir_y * sin(player->speed_rot * player->shift);
	player->dir_y = save_dis * sin(player->speed_rot * player->shift) + \
		player->dir_y * cos(player->speed_rot * player->shift);
	player->plan_x = player->plan_x * cos(player->speed_rot * player->shift) - \
		player->plan_y * sin(player->speed_rot * player->shift);
	player->plan_y = save_plane * sin(player->speed_rot * player->shift) + \
		player->plan_y * cos(player->speed_rot * player->shift);
}

void	keyses(t_core *core)
{
	SDL_Event	event;
	const Uint8 *state;

	state = SDL_GetKeyboardState(NULL);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || EXIT)
			core->quit = 1;
	}
	switch_music(core->sound, state);
	if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W])
		move_up(core, core->player);
	if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S])
		move_down(core, core->player);
	if (state[SDL_SCANCODE_A])
		move_left(core, core->player);
	if (state[SDL_SCANCODE_D])
		move_right(core, core->player);
	if (state[SDL_SCANCODE_LEFT])
		rotate_left(core->player);
	if (state[SDL_SCANCODE_RIGHT])
		rotate_right(core->player);
	keyses_addon(core, state);
}

void	keyses_addon(t_core *core, const Uint8 *state)
{
	if (state[SDL_SCANCODE_RIGHTBRACKET] && core->fog_dis < 20)
		core->fog_dis += 1;
	if (state[SDL_SCANCODE_LEFTBRACKET] && core->fog_dis > 1)
		core->fog_dis -= 1;
	if (state[SDL_SCANCODE_KP_1])
		core->paint->shade = DARK;
	if (state[SDL_SCANCODE_KP_2])
		core->paint->shade = FOG;
	if (state[SDL_SCANCODE_KP_0])
		core->paint->shade = 1;
	if (state[SDL_SCANCODE_LSHIFT])
		core->player->shift = 3;
	else
		core->player->shift = 1.5;
}

void	mouse(t_core *core)
{
	int	x;

	SDL_GetRelativeMouseState(&x, NULL);
	if (x < 0)
		rotate_left(core->player);
	else if (x > 0)
		rotate_right(core->player);
}
