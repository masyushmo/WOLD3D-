/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:26:22 by mmasyush          #+#    #+#             */
/*   Updated: 2018/10/25 17:26:23 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*from;
	char	*to;
	size_t	i;

	i = 0;
	from = (char*)src;
	to = (char*)dst;
	if (to > from)
		while ((int)len-- > 0)
			to[len] = from[len];
	else
		while (len > i)
		{
			to[i] = from[i];
			i++;
		}
	return (dst);
}
