/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:55:23 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/28 19:55:23 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	load_level(t_texture *texture, t_core *core)
{
	texture->pause = IMG_Load("./textures/pause.png");
	if (core->name == 1)
		labrint(core);
	else if (core->name == 2)
		minecraft(core);
	else
	{
		wall_tex(texture, core);
		f_c_tex(texture, core);
		load_sound(core->sound);
	}
}

void	wall_tex(t_texture *texture, t_core *core)
{
	if (!(texture->wall_tex = ft_memalloc(sizeof(SDL_Surface) * WTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->wall_tex[0] = load_tex("./textures/sample/WALL1.bmp", core);
	texture->wall_tex[1] = load_tex("./textures/sample/WALL2.bmp", core);
	texture->wall_tex[2] = load_tex("./textures/sample/WALL3.bmp", core);
	texture->wall_tex[3] = load_tex("./textures/sample/WALL4.bmp", core);
	texture->wall_tex[4] = load_tex("./textures/sample/WALL5.bmp", core);
	texture->wall_tex[5] = load_tex("./textures/sample/WALL6.bmp", core);
	texture->wall_tex[6] = load_tex("./textures/sample/WALL7.bmp", core);
	texture->wall_tex[7] = load_tex("./textures/sample/WALL8.bmp", core);
	texture->wall_tex[8] = load_tex("./textures/sample/WALL9.bmp", core);
	if (!(texture->wall_tey = ft_memalloc(sizeof(SDL_Surface) * WTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->wall_tey[0] = load_tex("./textures/sample/WALL1D.bmp", core);
	texture->wall_tey[1] = load_tex("./textures/sample/WALL2D.bmp", core);
	texture->wall_tey[2] = load_tex("./textures/sample/WALL3D.bmp", core);
	texture->wall_tey[3] = load_tex("./textures/sample/WALL4D.bmp", core);
	texture->wall_tey[4] = load_tex("./textures/sample/WALL5D.bmp", core);
	texture->wall_tey[5] = load_tex("./textures/sample/WALL6D.bmp", core);
	texture->wall_tey[6] = load_tex("./textures/sample/WALL7D.bmp", core);
	texture->wall_tey[7] = load_tex("./textures/sample/WALL8D.bmp", core);
	texture->wall_tey[8] = load_tex("./textures/sample/WALL9D.bmp", core);
}

void	f_c_tex(t_texture *texture, t_core *core)
{
	if (!(texture->floor_tex = ft_memalloc(sizeof(SDL_Surface) * FCTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->floor_tex[0] = load_tex("./textures/sample/FLOOR.bmp", core);
	texture->floor_tex[1] = load_tex("./textures/sample/FLOORD.bmp", core);
	if (!(texture->cell_tex = ft_memalloc(sizeof(SDL_Surface) * FCTN)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->cell_tex[0] = load_tex("./textures/sample/CELL.bmp", core);
	texture->cell_tex[1] = load_tex("./textures/sample/CELL2.bmp", core);
}

void	load_sound(t_sound *sound)
{
	sound->music[0] = load_mus("./sounds/sample/Before.mp3");
	sound->music[1] = load_mus("./sounds/sample/Po.mp3");
	sound->music[2] = load_mus("./sounds/sample/FunkYou.mp3");
	sound->music[3] = load_mus("./sounds/sample/wolf.mp3");
	sound->music[4] = load_mus("./sounds/sample/Prototype.mp3");
	sound->steps = load_sou("./sounds/sample/step.wav");
	sound->run = load_sou("./sounds/sample/run.wav");
}

int		set_sample(t_core *core, t_paint *paint)
{
	int	tcolor;

	tcolor = 0x000000;
	if (core->dda->s == 0 && core->ray->raydir_x > 0)
		tcolor = pix_from_text(core->texture->wall_tex[6], \
			paint->tex_x, paint->tex_y);
	else if (core->dda->s == 0 && core->ray->raydir_x < 0)
		tcolor = pix_from_text(core->texture->wall_tex[4], \
			paint->tex_x, paint->tex_y);
	else if (core->dda->s == 1 && core->ray->raydir_y < 0)
		tcolor = pix_from_text(core->texture->wall_tey[3], \
			paint->tex_x, paint->tex_y);
	else if (core->dda->s == 1 && core->ray->raydir_y > 0)
		tcolor = pix_from_text(core->texture->wall_tey[5], \
			paint->tex_x, paint->tex_y);
	return (tcolor);
}
