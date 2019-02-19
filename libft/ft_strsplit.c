/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:10:17 by mmasyush          #+#    #+#             */
/*   Updated: 2018/11/01 14:10:18 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**spl;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s || !(spl = (char**)malloc(sizeof(spl) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] != '\0' && s[i + len] != c)
				len++;
			spl[j++] = ft_strsub(s, i, len);
			i += len;
		}
	}
	spl[j] = 0;
	return (spl);
}
