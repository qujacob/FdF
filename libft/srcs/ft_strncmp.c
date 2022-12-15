/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:48:37 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/09 17:41:37 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*copy1;
	unsigned char	*copy2;

	copy1 = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	while ((*copy1 || *copy2) && n-- > 0)
	{
		if (*copy1 != *copy2)
			return (*copy1 - *copy2);
		copy1++;
		copy2++;
	}
	return (0);
}
