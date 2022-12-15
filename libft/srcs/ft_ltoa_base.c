/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:18:56 by qujacob           #+#    #+#             */
/*   Updated: 2021/08/28 15:06:35 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static int	count_digits(long nb, char *base)
{
	if (nb == 0)
		return (1);
	else
		return (1 + count_digits(nb / ft_strlen(base), base));
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	bank;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		bank = str[i];
		str[i] = str[j];
		str[j] = bank;
		i++;
		j--;
	}
	return (str);
}

char	*ft_ltoa_base(long nb, char *base)
{
	int				nb_digits;
	char			*final_nbr;
	int				i;
	long long int	nbr;

	nbr = nb;
	if (nbr == 0)
		return (ft_strdup("0"));
	nb_digits = count_digits(nbr, base);
	final_nbr = (char *)malloc(sizeof(char) * (nb_digits + 1));
	if (!final_nbr)
		return (NULL);
	i = -1;
	while (++i < nb_digits - 1)
	{
		final_nbr[i] = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base);
	}
	final_nbr[i] = '\0';
	return (ft_strrev(final_nbr));
}
