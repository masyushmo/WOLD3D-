/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:45:57 by mmasyush          #+#    #+#             */
/*   Updated: 2018/10/31 17:45:58 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bgining(const char *s)
{
	int	bg;
	int i;

	bg = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		bg++;
		i++;
	}
	return (bg);
}

static int	ending(const char *s)
{
	int end;
	int len;

	end = 0;
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
	{
		end++;
		len--;
	}
	return (end);
}

char		*ft_strtrim(char const *s)
{
	char	*newbie;
	size_t	newlen;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	j = bgining(s);
	newbie = NULL;
	if (ft_strlen(s) - bgining(s) <= 0)
		newlen = 0;
	else
		newlen = ft_strlen(s) - bgining(s) - ending(s);
	newbie = (char*)malloc(sizeof(char) * (newlen + 1));
	if (newbie == NULL)
		return (NULL);
	while (newlen-- > 0)
		newbie[i++] = s[j++];
	newbie[i] = '\0';
	return (newbie);
}
