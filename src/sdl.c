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
	if (!(core->rect = ft_memalloc(sizeof(SDL_Rect))))
		stop("\033[22;31mERROR: failed to create surface");
		core->rect->h = W_Y;
		core->rect->w = W_X;
		core->rect->x = 0;
		core->rect->y = 0;
	create_surface(core);
}

void	create_surface(t_core *core)
{
	Uint32	rmask;
	Uint32	gmask;
	Uint32	bmask;
	Uint32	amask;

	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		rmask = 0xFF000000;
		gmask = 0x00FF0000;
		bmask = 0x0000FF00;
		amask = 0x000000FF;
	}
	else
	{
		rmask = 0x000000FF;
		gmask = 0x0000FF00;
		bmask = 0x00FF0000;
		amask = 0xFF000000;
	}
	core->rect->x = 0;
	core->rect->y = 0;
	core->surface = SDL_CreateRGBSurface(0, W_X, \
		W_Y, 32, rmask, gmask, bmask, amask);
	if (core->surface == NULL)
		stop("\033[22;31mERROR: failed to create surface");
}

SDL_Surface		*load_texture(char *path, t_core *core)
{
	SDL_Surface		*temp;
	SDL_Surface		*texture;

	temp = SDL_LoadBMP(path);
	if (temp == NULL)
	{
		ft_putstr("Error while loading a texture file\n");
		exit(1);
	}
	texture = SDL_ConvertSurfaceFormat(temp, core->surface->format->format, 0);
	SDL_FreeSurface(temp);
	return (texture);
}

void	display_core(t_core *core)
{
	SDL_DestroyTexture(core->tex);
	SDL_RenderClear(core->rend);
	core->tex = SDL_CreateTextureFromSurface(core->rend,
		core->surface);
	SDL_RenderCopy(core->rend, core->tex, NULL, core->rect);
	SDL_RenderPresent(core->rend);
}
