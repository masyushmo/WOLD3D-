/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expon.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:51:39 by mmasyush          #+#    #+#             */
/*   Updated: 2018/11/06 11:51:39 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_expon(double n, int pow)
{
	double	res;

	res = n;
	if (pow > 0)
		while (pow - 1)
		{
			res *= n;
			pow--;
		}
	return (res);
}
