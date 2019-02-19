/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:01:18 by mmasyush          #+#    #+#             */
/*   Updated: 2018/10/28 13:01:19 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	char	ch;
	int		i;
	int		j;
	int		o;

	j = -1;
	i = 0;
	o = (int)ft_strlen(s);
	src = (char*)s;
	ch = (char)c;
	if (ch == '\0')
		return (&src[o++]);
	while (src[i])
	{
		if (src[i] == ch)
			j = i;
		i++;
	}
	if (!(j == -1))
		return (&src[j]);
	else
		return (0);
}
