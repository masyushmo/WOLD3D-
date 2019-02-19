/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:38:23 by mmasyush          #+#    #+#             */
/*   Updated: 2018/11/10 15:59:35 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	temp = malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	temp = f(lst);
	new = temp;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = malloc(sizeof(t_list));
		temp->next = f(lst);
		temp = temp->next;
	}
	return (new);
}
