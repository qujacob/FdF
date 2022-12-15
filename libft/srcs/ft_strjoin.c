/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:22:18 by qujacob           #+#    #+#             */
/*   Updated: 2021/12/03 16:43:11 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	final = (char *)malloc(sizeof(char) * (size + 1));
	if (final == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		final[i] = s1[i];
	j = -1;
	while (s2[++j])
		final[i + j] = s2[j];
	final[i + j] = '\0';
	return (final);
}
