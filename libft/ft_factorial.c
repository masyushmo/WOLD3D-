/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:15:30 by mmasyush          #+#    #+#             */
/*   Updated: 2018/11/06 11:15:31 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_factorial(unsigned long long nb)
{
	unsigned long long	i;

	i = 1;
	if (nb == 0)
		return (1);
	if (nb)
	{
		while (nb > 0 && nb < 21)
		{
			i *= nb;
			nb--;
		}
		return (i);
	}
	return (0);
}
