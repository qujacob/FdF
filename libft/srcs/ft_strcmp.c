/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:48:37 by qujacob           #+#    #+#             */
/*   Updated: 2021/09/25 15:39:38 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*copy1;
	unsigned char	*copy2;

	copy1 = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	while (*copy1 || *copy2)
	{
		if (*copy1 != *copy2)
			return (*copy1 - *copy2);
		copy1++;
		copy2++;
	}
	return (0);
}
