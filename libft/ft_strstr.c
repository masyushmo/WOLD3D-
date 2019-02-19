/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:34:13 by mmasyush          #+#    #+#             */
/*   Updated: 2018/10/28 13:34:14 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
		while (need[j] == look[i + j])
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
