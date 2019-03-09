/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:37:04 by mmasyush          #+#    #+#             */
/*   Updated: 2019/03/08 12:37:04 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		line_point(int start, int end, double p)
{
	return ((int)(start + (end - start) * p));
}
