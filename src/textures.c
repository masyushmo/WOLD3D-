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

void	texture_init(t_texture *texture, t_core *core)
{
	wall_Xtex(texture, core);
	wall_Ytex(texture, core);
}

void	wall_Xtex(t_texture *texture, t_core *core)
{
	if (!(texture->wall_TEX = ft_memalloc(sizeof(SDL_Surface) * WALL_TEXTS)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->wall_TEX[0] = load_texture("./textures/wall/WALL74.bmp", core);
	texture->wall_TEX[1] = load_texture("./textures/wall/Stone.bmp", core);
	texture->wall_TEX[2] = load_texture("./textures/wall/WALL0.bmp", core);
	texture->wall_TEX[3] = load_texture("./textures/wall/Brown7.bmp", core);
	texture->wall_TEX[4] = load_texture("./textures/wall/WALL74.bmp", core);
	texture->wall_TEX[5] = load_texture("./textures/wall/WALL74.bmp", core);
	texture->wall_TEX[6] = load_texture("./textures/wall/WALL74.bmp", core);
	texture->wall_TEX[7] = load_texture("./textures/wall/WALL74.bmp", core);
	texture->wall_TEX[8] = load_texture("./textures/wall/WALL74.bmp", core);
}

void	wall_Ytex(t_texture *texture, t_core *core)
{
	if (!(texture->wall_TEY = ft_memalloc(sizeof(SDL_Surface) * WALL_TEXTS)))
		stop("\033[22;31mERROR: failed to malloc textures");
	texture->wall_TEY[0] = load_texture("./textures/wall/WALL74D.bmp", core);
	texture->wall_TEY[1] = load_texture("./textures/wall/Blue9.bmp", core);
	texture->wall_TEY[2] = load_texture("./textures/wall/Blue17.bmp", core);
	texture->wall_TEY[3] = load_texture("./textures/wall/WALL74D.bmp", core);
	texture->wall_TEY[4] = load_texture("./textures/wall/WALL74D.bmp", core);
	texture->wall_TEY[5] = load_texture("./textures/wall/WALL74D.bmp", core);
	texture->wall_TEY[6] = load_texture("./textures/wall/WALL74D.bmp", core);
	texture->wall_TEY[7] = load_texture("./textures/wall/WALL74D.bmp", core);
}