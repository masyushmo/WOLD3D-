/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:00:48 by mmasyush          #+#    #+#             */
/*   Updated: 2018/10/31 16:00:48 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*con;
	size_t	len;
	size_t	a;
	size_t	b;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	len = a + b;
	con = (char*)malloc(sizeof(*con) * (len + 1));
	if (con == NULL)
		return (NULL);
	ft_strcpy(con, s1);
	ft_strcat(con, s2);
	return (con);
}
