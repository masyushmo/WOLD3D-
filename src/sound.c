/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:44:18 by mmasyush          #+#    #+#             */
/*   Updated: 2019/03/06 10:44:18 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		play_music(t_sound *sound, int n)
{
	if (!(Mix_PlayingMusic()))
		Mix_PlayMusic(sound->music[n], -1);
	else if (Mix_PausedMusic())
		Mix_ResumeMusic();
	else
		Mix_PauseMusic();
}

void		switch_music(t_sound *sound, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_m)
			play_music(sound, sound->mus_n);
		else if (event.key.keysym.sym == GREATER && sound->mus_n < 4)
		{
			Mix_HaltMusic();
			sound->mus_n += 1;
			play_music(sound, sound->mus_n);
		}
		else if (event.key.keysym.sym == LESER && sound->mus_n > 0)
		{
			Mix_HaltMusic();
			sound->mus_n -= 1;
			play_music(sound, sound->mus_n);
		}
	}
}

void		spec_chunks(t_core *core)
{
	if (core->name == 1)
	{
		if ((int)(core->player->coord_x) == 5 && \
			(int)(core->player->coord_y) == 18 && (!(Mix_Playing(1))))
			Mix_PlayChannel(1, core->sound->lcrip[0], 0);
		if ((int)(core->player->coord_x) == 4 && \
			(int)(core->player->coord_y) == 7 && (!(Mix_Playing(1))))
			Mix_PlayChannel(1, core->sound->lcrip[1], 0);
		if ((int)(core->player->coord_x) == 13 && \
			(int)(core->player->coord_y) == 8 && (!(Mix_Playing(1))))
			Mix_PlayChannel(1, core->sound->lcrip[2], 0);
		if ((int)(core->player->coord_x) == 8 && \
			(int)(core->player->coord_y) == 13 && (!(Mix_Playing(1))))
			Mix_PlayChannel(1, core->sound->lcrip[3], 0);
		if ((int)(core->player->coord_x) == 15 && \
			(int)(core->player->coord_y) == 18 && (!(Mix_Playing(1))))
			Mix_PlayChannel(1, core->sound->lcrip[4], 0);
		if ((int)(core->player->coord_x) == 11 && \
		(int)(core->player->coord_y) == 16 && (!(Mix_Playing(1))))
			Mix_PlayChannel(1, core->sound->lcrip[5], 0);
		if ((int)(core->player->coord_x) == 21 && \
		(int)(core->player->coord_y) == 15 && (!(Mix_Playing(1))))
			Mix_PlayChannel(1, core->sound->lcrip[6], 0);
	}
}

Mix_Music	*load_mus(char *path)
{
	Mix_Music *load;

	load = Mix_LoadMUS(path);
	if (load == NULL)
		stop("\033[22;31mERROR: failed to load music");
	return (load);
}

Mix_Chunk	*load_sou(char *path)
{
	Mix_Chunk *load;

	load = Mix_LoadWAV(path);
	if (load == NULL)
		stop("\033[22;31mERROR: failed to load music");
	return (load);
}
