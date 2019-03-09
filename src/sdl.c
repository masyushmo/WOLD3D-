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

void		create_win(t_core *core)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		stop("\033[22;31mERROR: failed to initialize SDL");
	if (!(core->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, core->w, core->h, SDL_WINDOW_RESIZABLE)))
		stop("\033[22;31mERROR: failed to create window");
	if (!(core->rend = SDL_CreateRenderer(core->win, -1, \
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		stop("\033[22;31mERROR: failed to create render");
	if (!(core->tex = SDL_CreateTexture(core->rend, SDL_PIXELFORMAT_ARGB8888, \
		SDL_TEXTUREACCESS_TARGET, core->w, core->h)))
		stop("\033[22;31mERROR: failed to create render");
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		stop("\033[22;31mERROR: failed to init music");
	core->surface = SDL_CreateRGBSurface(0, core->w, core->h, 32, 0, 0, 0, 0);
	if (core->surface == NULL)
		stop("\033[22;31mERROR: failed to create surface");
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetWindowGrab(core->win, SDL_FALSE);
	SDL_SetRelativeMouseMode(SDL_ENABLE);
}

SDL_Surface	*load_tex(char *path, t_core *core)
{
	SDL_Surface		*temp;
	SDL_Surface		*texture;

	temp = SDL_LoadBMP(path);
	if (temp == NULL)
	{
		SDL_FreeSurface(temp);
		stop("\033[22;31mERROR: failed to load texture");
	}
	texture = SDL_ConvertSurfaceFormat(temp, core->surface->format->format, 0);
	SDL_FreeSurface(temp);
	return (texture);
}

void		display_core(t_core *core)
{
	SDL_RenderClear(core->rend);
	SDL_DestroyTexture(core->tex);
	core->tex = SDL_CreateTextureFromSurface(core->rend,
		core->surface);
	SDL_RenderCopy(core->rend, core->tex, NULL, NULL);
	SDL_RenderPresent(core->rend);
}
