/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:30:06 by mmasyush          #+#    #+#             */
/*   Updated: 2019/03/08 12:30:07 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	percent(int start, int end, int current)
{
	int	pos;
	int	dis;

	pos = current - start;
	dis = end - start;
	return ((dis == 0) ? 1.0 : (pos / ((float)dis)));
}
