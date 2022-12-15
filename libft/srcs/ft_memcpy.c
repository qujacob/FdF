/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:21:39 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/09 17:41:22 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*copy;
	unsigned char	*copy2;

	copy = (unsigned char *)dst;
	copy2 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (n-- > 0)
		*copy++ = *copy2++;
	return (dst);
}
