/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:23:43 by qujacob           #+#    #+#             */
/*   Updated: 2021/09/25 14:26:14 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*copy;

	copy = *lst;
	while (copy)
	{
		copy = (*lst)->next;
		free(*lst);
		*lst = copy;
	}
}
