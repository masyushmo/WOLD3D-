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
}

void		clean_addon(t_core *core)
{
	int i;

	i = -1;
	while (++i < 5)
		Mix_FreeMusic(core->sound->music[i]);
	i = -1;
	if (core->name == 1)
		while (++i < 7)
			Mix_FreeChunk(core->sound->lcrip[i]);
	SDL_FreeSurface(core->texture->pause);
	Mix_FreeChunk(core->sound->steps);
	Mix_FreeChunk(core->sound->run);
	SDL_FreeSurface(core->surface);
	SDL_DestroyTexture(core->tex);
	SDL_DestroyRenderer(core->rend);
	SDL_DestroyWindow(core->win);
	SDL_Quit();
}

void		clean(t_core *core)
{
	int i;

	i = -1;
	while (++i < WTN)
	{
		SDL_FreeSurface(core->texture->wall_tex[i]);
		SDL_FreeSurface(core->texture->wall_tey[i]);
	}
	free(core->texture->wall_tex);
	free(core->texture->wall_tey);
	i = -1;
	while (++i < 2)
	{
		SDL_FreeSurface(core->texture->floor_tex[i]);
		SDL_FreeSurface(core->texture->cell_tex[i]);
	}
	free(core->texture->floor_tex);
	free(core->texture->cell_tex);
	free(core->texture);
	clean_addon(core);
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

void		display_core(t_core *core, SDL_Surface *surface)
{
	SDL_RenderClear(core->rend);
	SDL_DestroyTexture(core->tex);
	core->tex = SDL_CreateTextureFromSurface(core->rend, surface);
	SDL_RenderCopy(core->rend, core->tex, NULL, NULL);
	SDL_RenderPresent(core->rend);
}
