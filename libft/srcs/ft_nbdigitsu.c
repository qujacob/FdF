/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdigitsu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:08:30 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/29 15:09:27 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_nbdigitsu(unsigned int nb)
{
	size_t	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}
