/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:42:01 by mmasyush          #+#    #+#             */
/*   Updated: 2018/10/31 15:42:02 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!s)
		return (0);
	i = 0;
	sub = (char*)malloc(sizeof(*sub) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (len-- > 0)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
