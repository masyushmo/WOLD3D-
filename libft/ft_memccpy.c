/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:55:25 by mmasyush          #+#    #+#             */
/*   Updated: 2018/10/25 14:55:53 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n)
{
	char	*to;
	char	*from;
	size_t	i;

	i = 0;
	to = (char*)dst;
	from = (char*)src;
	while (n-- > 0)
	{
		to[i] = from[i];
		if ((unsigned char)from[i] == (unsigned char)c)
			return (dst + 1 + i);
		i++;
	}
	return (0);
}
