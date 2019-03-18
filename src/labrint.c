/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labrint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:14:05 by mmasyush          #+#    #+#             */
/*   Updated: 2019/03/01 15:14:05 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	labrint(t_core *core)
{
	wall_lab(core->texture, core);
	f_c_lab(core->texture, core);
	load_sound_lab(core->sound);
}

void	wall_lab(t_texture *texture, t_core *core)
{
	if (!(texture->wall_tex = ft_memalloc(sizeof(SDL_Surface) * WTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->wall_tex[0] = load_tex("./textures/labrint/WALL1.bmp", core);
	texture->wall_tex[1] = load_tex("./textures/labrint/WALL2.bmp", core);
	texture->wall_tex[2] = load_tex("./textures/labrint/WALL3.bmp", core);
	texture->wall_tex[3] = load_tex("./textures/labrint/WIN.bmp", core);
	texture->wall_tex[4] = load_tex("./textures/labrint/WALL4.bmp", core);
	texture->wall_tex[5] = load_tex("./textures/labrint/WALL5.bmp", core);
	texture->wall_tex[6] = load_tex("./textures/labrint/WALL6.bmp", core);
	texture->wall_tex[7] = load_tex("./textures/labrint/WALL7.bmp", core);
	texture->wall_tex[8] = load_tex("./textures/labrint/WALL8.bmp", core);
	if (!(texture->wall_tey = ft_memalloc(sizeof(SDL_Surface) * WTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->wall_tey[0] = load_tex("./textures/labrint/WALL1D.bmp", core);
	texture->wall_tey[1] = load_tex("./textures/labrint/WALL2D.bmp", core);
	texture->wall_tey[2] = load_tex("./textures/labrint/WALL3D.bmp", core);
	texture->wall_tey[3] = load_tex("./textures/labrint/WIND.bmp", core);
	texture->wall_tey[4] = load_tex("./textures/labrint/WALL4D.bmp", core);
	texture->wall_tey[5] = load_tex("./textures/labrint/WALL5D.bmp", core);
	texture->wall_tey[6] = load_tex("./textures/labrint/WALL6D.bmp", core);
	texture->wall_tey[7] = load_tex("./textures/labrint/WALL7D.bmp", core);
	texture->wall_tey[8] = load_tex("./textures/labrint/WALL8D.bmp", core);
}

void	f_c_lab(t_texture *texture, t_core *core)
{
	if (!(texture->floor_tex = ft_memalloc(sizeof(SDL_Surface) * FCTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->floor_tex[0] = load_tex("./textures/labrint/FLOOR.bmp", core);
	texture->floor_tex[1] = load_tex("./textures/labrint/FLOOR2.bmp", core);
	if (!(texture->cell_tex = ft_memalloc(sizeof(SDL_Surface) * FCTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->cell_tex[0] = load_tex("./textures/labrint/CELL.bmp", core);
	texture->cell_tex[1] = load_tex("./textures/labrint/CELL2.bmp", core);
}

void	load_sound_lab(t_sound *sound)
{
	sound->music[0] = load_mus("./sounds/labr/Wondering.mp3");
	sound->music[1] = load_mus("./sounds/labr/Sus.mp3");
	sound->music[2] = load_mus("./sounds/labr/Enemy.mp3");
	sound->music[3] = load_mus("./sounds/labr/12.mp3");
	sound->music[4] = load_mus("./sounds/labr/Dungeons.mp3");
	sound->steps = load_sou("./sounds/labr/step.wav");
	sound->run = load_sou("./sounds/labr/run.wav");
	sound->lcrip[0] = load_sou("./sounds/labr/arr1.wav");
	sound->lcrip[1] = load_sou("./sounds/labr/arr2.wav");
	sound->lcrip[2] = load_sou("./sounds/labr/arr3.wav");
	sound->lcrip[3] = load_sou("./sounds/labr/arr4.wav");
	sound->lcrip[4] = load_sou("./sounds/labr/arr5.wav");
	sound->lcrip[5] = load_sou("./sounds/labr/win.wav");
	sound->lcrip[6] = load_sou("./sounds/labr/arr6.wav");
}
