/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:26:05 by mmasyush          #+#    #+#             */
/*   Updated: 2018/10/28 16:26:06 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*look;
	char	*need;

	i = 0;
	j = 0;
	look = (char*)haystack;
	need = (char*)needle;
	if (!*need)
		return (look);
	while (look[i])
	{
		while (need[j] == look[i + j] && (i + j) < (int)len)
		{
			if (need[j + 1] == '\0')
				return (look + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
