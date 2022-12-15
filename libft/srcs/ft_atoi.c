/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:56:03 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/09 17:39:43 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	test_overflow(int count, int neg)
{
	if (count > 10 && neg < 0)
		return (0);
	if (count > 10 && neg > 0)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	res;
	int	count;

	while (ft_isspace(*str))
		str++;
	neg = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	res = 0;
	count = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str++ - '0';
		count++;
	}
	if (test_overflow(count, neg) <= 0)
		return (test_overflow(count, neg));
	return (res * neg);
}
