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

void	pix_to_surf(SDL_Surface *surface, t_core *core)
{
	Uint32		*pixels;

	pixels = (Uint32 *)surface->pixels;
	if (core->win_pixX >= 0 && core->win_pixY >= 0 && \
		core->win_pixX < surface->w && core->win_pixY < surface->h)
		pixels[core->win_pixY * surface->w + core->win_pixX] = \
			pix_from_text(core->texture->wall_TEX[core->paint->tex_num], core);
}

Uint32	pix_from_text(SDL_Surface *texture, t_core *core)
{
	int		bpp;
	uint8_t *p;

	bpp = texture->format->BytesPerPixel;
	p = (uint8_t *)texture->pixels + core->paint->texY * texture->pitch +
		core->paint->texX * bpp;
	return (*(uint32_t *)p);
}

void	paint(t_core *core)
{
	paint_wall(core, core->paint);
}
