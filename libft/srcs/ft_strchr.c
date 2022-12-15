/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:35:09 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/09 17:41:15 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*copy;

	copy = (char *)s;
	while (*copy)
	{
		if (*copy == (unsigned char)c)
			return (copy);
		copy++;
	}
	if (*copy == (unsigned char)c)
		return (copy);
	return (NULL);
}
