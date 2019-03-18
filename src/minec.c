/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:55:39 by mmasyush          #+#    #+#             */
/*   Updated: 2019/03/06 13:55:39 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	minecraft(t_core *core)
{
	wall_min(core->texture, core);
	f_c_min(core->texture, core);
	load_sound_min(core->sound);
}

void	wall_min(t_texture *texture, t_core *core)
{
	if (!(texture->wall_tex = ft_memalloc(sizeof(SDL_Surface) * WTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->wall_tex[0] = load_tex("./textures/minec/cobble.bmp", core);
	texture->wall_tex[1] = load_tex("./textures/minec/diamond.bmp", core);
	texture->wall_tex[2] = load_tex("./textures/minec/gold.bmp", core);
	texture->wall_tex[3] = load_tex("./textures/minec/stone.bmp", core);
	texture->wall_tex[4] = load_tex("./textures/minec/wood.bmp", core);
	texture->wall_tex[5] = load_tex("./textures/minec/pill.bmp", core);
	texture->wall_tex[6] = load_tex("./textures/minec/pill2.bmp", core);
	texture->wall_tex[7] = load_tex("./textures/minec/obsid.bmp", core);
	texture->wall_tex[8] = load_tex("./textures/minec/dirt.bmp", core);
	if (!(texture->wall_tey = ft_memalloc(sizeof(SDL_Surface) * WTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->wall_tey[0] = load_tex("./textures/minec/cobbleD.bmp", core);
	texture->wall_tey[1] = load_tex("./textures/minec/diamondD.bmp", core);
	texture->wall_tey[2] = load_tex("./textures/minec/goldD.bmp", core);
	texture->wall_tey[3] = load_tex("./textures/minec/stoneD.bmp", core);
	texture->wall_tey[4] = load_tex("./textures/minec/woodD.bmp", core);
	texture->wall_tey[5] = load_tex("./textures/minec/pillD.bmp", core);
	texture->wall_tey[6] = load_tex("./textures/minec/pill2D.bmp", core);
	texture->wall_tey[7] = load_tex("./textures/minec/obsidD.bmp", core);
	texture->wall_tey[8] = load_tex("./textures/minec/dirtD.bmp", core);
}

void	f_c_min(t_texture *texture, t_core *core)
{
	if (!(texture->floor_tex = ft_memalloc(sizeof(SDL_Surface) * FCTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->floor_tex[0] = load_tex("./textures/minec/grass.bmp", core);
	texture->floor_tex[1] = load_tex("./textures/minec/grass.bmp", core);
	if (!(texture->cell_tex = ft_memalloc(sizeof(SDL_Surface) * FCTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->cell_tex[0] = load_tex("./textures/minec/dirtD.bmp", core);
	texture->cell_tex[1] = load_tex("./textures/minec/dirtD.bmp", core);
}

void	load_sound_min(t_sound *sound)
{
	sound->music[0] = load_mus("./sounds/minec/Minecraft.mp3");
	sound->music[1] = load_mus("./sounds/minec/Hands.mp3");
	sound->music[2] = load_mus("./sounds/minec/Venus.mp3");
	sound->music[3] = load_mus("./sounds/minec/Equ.mp3");
	sound->music[4] = load_mus("./sounds/minec/Lull.mp3");
	sound->steps = load_sou("./sounds/minec/step.wav");
	sound->run = load_sou("./sounds/minec/run.wav");
}
