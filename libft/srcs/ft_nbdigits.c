/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:44:44 by qujacob           #+#    #+#             */
/*   Updated: 2021/09/25 15:30:24 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_nbdigits(int nb)
{
	size_t	count;

	if (nb == 0)
		return (1);
	count = 0;
	if (nb < 0)
		nb *= -1;
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}
