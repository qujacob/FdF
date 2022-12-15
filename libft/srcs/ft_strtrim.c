/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:31:49 by qujacob           #+#    #+#             */
/*   Updated: 2021/07/09 17:41:47 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	size;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	size = ft_strlen(&s1[i]);
	if (size != 0)
		while (s1[i + size - 1] && ft_strchr(set, s1[i + size - 1]))
			size--;
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, &s1[i], size + 1);
	s2[size] = '\0';
	return (s2);
}
