/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:08:27 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/29 16:15:16 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_digits(int nb, char *base)
{
	if (nb == 0)
		return (1);
	else
		return (1 + count_digits(nb / ft_strlen(base), base));
}

static void	is_negative(int negative, char *final_nbr, int *i)
{
	if (negative == 1)
		final_nbr[*i++] = '-';
}

char	*ft_itoa_base(int nb, char *base)
{
	int		nb_digits;
	char	*final_nbr;
	int		i;
	int		negative;
	long	nbr;

	nbr = (long)nb;
	nb_digits = count_digits(nbr, base);
	final_nbr = (char *)malloc(sizeof(char) * (nb_digits + 1));
	if (!final_nbr)
		return (NULL);
	if (nbr < 0)
	{
		negative = 1;
		nbr *= -1;
	}
	i = -1;
	while (++i < nb_digits - 1)
	{
		final_nbr[i] = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base);
	}
	is_negative(negative, final_nbr, &i);
	final_nbr[i] = '\0';
	return (final_nbr);
}
