/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:18:35 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/14 16:18:37 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	create_win(t_core *core)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		stop("\033[22;31mERROR: failed to initialize SDL");
	if (!(core->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, W_X, W_Y, SDL_WINDOW_RESIZABLE)))
		stop("\033[22;31mERROR: failed to create window");
	if (!(core->rend = SDL_CreateRenderer(core->win, -1, \
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		stop("\033[22;31mERROR: failed to create render");
	if (!(core->tex = SDL_CreateTexture(core->rend, SDL_PIXELFORMAT_ARGB32,
		SDL_TEXTUREACCESS_TARGET, W_X, W_Y)))
		stop("\033[22;31mERROR: failed to create render");
	int tmp = 0;
	while (tmp == 0)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				tmp = 1;
			if (EXIT)
				tmp = 1;
		}
	}
}