/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:37:19 by mmasyush          #+#    #+#             */
/*   Updated: 2018/10/28 12:37:21 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;
	char	ch;

	src = (char*)s;
	ch = c;
	while (*src != ch)
	{
		if (*src == '\0')
			return (0);
		src++;
	}
	return (src);
}
