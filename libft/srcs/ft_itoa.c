/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:08:18 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/09 17:39:38 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*rev(char *number)
{
	int		i;
	int		j;
	char	bank;

	i = 0;
	j = (int)ft_strlen(number) - 1;
	if (!ft_strncmp(number, "-", 1))
		i++;
	while (j > i)
	{
		bank = number[i];
		number[i++] = number[j];
		number[j--] = bank;
	}
	return (number);
}

static size_t	count_digits(long nb)
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

static char	*fill_number(char *number, long nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		number[i++] = '0';
	if (nb < 0)
	{
		number[i++] = '-';
		nb *= -1;
	}	
	while (nb != 0)
	{
		number[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	number[i] = '\0';
	return (number);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	nb_digits;
	char	*number;

	nb = (long)n;
	nb_digits = count_digits(nb);
	if (nb < 0)
		nb_digits++;
	number = (char *)malloc(sizeof(char) * (nb_digits + 1));
	if (number == NULL)
		return (NULL);
	number = fill_number(number, nb);
	return (rev(number));
}
