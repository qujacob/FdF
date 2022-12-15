/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:41:04 by qujacob           #+#    #+#             */
/*   Updated: 2021/12/15 18:53:25 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr_nl(const char *s)
{
	char	*copy;

	copy = (char *)s;
	while (*copy)
	{
		if (*copy == '\n')
			return (++copy);
		copy++;
	}
	return (NULL);
}

int	ft_is_nl(const char *s)
{
	char	*copy;

	if (!s)
		return (0);
	copy = (char *)s;
	while (*copy)
	{
		if (*copy == '\n')
			return (1);
		copy++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*final;
	size_t	size;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	final = (char *)malloc(sizeof(char) * (size + 1));
	if (final == NULL)
		return (NULL);
	i = -1;
	if (s1)
	{
		while (s1[++i])
			final[i] = s1[i];
		free((char *)s1);
		s1 = NULL;
	}
	j = -1;
	while (s2 && s2[++j])
		final[i + j] = s2[j];
	final[i + j] = '\0';
	return (final);
}
