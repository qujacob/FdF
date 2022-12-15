/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:44:19 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/09 17:40:08 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*copy;
	unsigned char	*copy2;

	copy = (unsigned char *)dst;
	copy2 = (unsigned char *)src;
	if (n == 0 || dst == src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = copy2[i];
		if (copy2[i] == (unsigned char)c)
			return (&copy[i] + 1);
		i++;
	}
	return (NULL);
}
