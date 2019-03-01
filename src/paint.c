/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:04:55 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/21 12:04:55 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	pix_to_surf(SDL_Surface *surface, int x, int y, const int color)
{
	Uint32 *pixels;
	
	pixels = (Uint32 *)surface->pixels;
    pixels[( y * surface->w ) + x] = color;
}

Uint32	pix_from_text(SDL_Surface *texture, int x, int y)
{
	Uint32 *ptr;
	
	ptr = (Uint32 *)texture->pixels;
    return ptr[( y * texture->w ) + x];
}

void	paint(t_core *core)
{
	paint_wall(core, core->paint);
	paint_floor(core, core->paint);
}
