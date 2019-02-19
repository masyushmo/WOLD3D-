/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:44:07 by mmasyush          #+#    #+#             */
/*   Updated: 2018/11/06 13:44:07 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchan(char *s, char a, char b)
{
	char	ch;
	char	*new;

	new = s;
	ch = a;
	while (*new != '\0')
	{
		if (*new == ch)
			*new = b;
		new++;
	}
	return (new);
}
