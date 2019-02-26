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

void	rotateLEFT(t_core *core, t_player *player)
{
	double saveDIR;
	double savePL;
	
	saveDIR = player->dirX;
	savePL = player->planX;
	player->dirX = player->dirX * cos(player->speedROT) - \
		player->dirY * sin(player->speedROT);
	player->dirY = saveDIR * sin(player->speedROT) + \
		player->dirY * cos(player->speedROT);
	player->planX = player->planX * cos(player->speedROT) - \
		player->planY * sin(player->speedROT);
	player->planY = savePL * sin(player->speedROT) + \
		player->planY * cos(player->speedROT);
}

void	rotateRIGHT(t_core *core, t_player *player)
{
	double saveDIR;
	double savePL;
	
	saveDIR = player->dirX;
	savePL = player->planX;
	player->dirX = player->dirX * cos(-player->speedROT) - \
		player->dirY * sin(-player->speedROT);
	player->dirY = saveDIR * sin(-player->speedROT) + \
		player->dirY * cos(-player->speedROT);
	player->planX = player->planX * cos(-player->speedROT) - \
		player->planY * sin(-player->speedROT);
	player->planY = savePL * sin(-player->speedROT) + \
		player->planY * cos(-player->speedROT);
}

void	keyses(t_core *core)
{
	SDL_Event	event;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || EXIT)
			core->keys->exit = 1;
	}
	if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W])
		moveUP(core, core->player);
	if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S])
		moveDOWN(core, core->player);
	if (state[SDL_SCANCODE_A])
		moveLEFT(core, core->player);
	if (state[SDL_SCANCODE_D])
		moveRIGHT(core, core->player);
	if (state[SDL_SCANCODE_LEFT])
		rotateLEFT(core, core->player);
	if (state[SDL_SCANCODE_RIGHT])
		rotateRIGHT(core, core->player);
}