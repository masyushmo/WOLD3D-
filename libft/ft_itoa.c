/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:13:33 by mmasyush          #+#    #+#             */
/*   Updated: 2018/11/04 11:13:33 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	temp;

	len = size(n);
	temp = n;
	if (n < 0)
	{
		temp = -n;
		len++;
	}
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[--len] = temp % 10 + '0';
	while (temp /= 10)
		str[--len] = temp % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
