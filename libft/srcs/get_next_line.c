/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:41:11 by qujacob           #+#    #+#             */
/*   Updated: 2021/12/15 18:51:05 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_free(char **s, int ret_val)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
	return (ret_val);
}

static char	*ft_before_nl(char *buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	tmp[i] = '\0';
	while (--i >= 0)
		tmp[i] = buffer[i];
	return (tmp);
}

static char	*ft_init(char *buffer, char **save, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || fd >= 1024 || 1024 < 1 || read(fd, NULL, 0))
		return (NULL);
	while (i < 1024 + 1)
		buffer[i++] = '\0';
	if (!(*save))
		*save = ft_strdup("");
	return (*save);
}

static char	*ft_cut_save(char *save)
{
	char	*tmp;

	tmp = ft_strdup(ft_strchr_nl(save));
	if (!tmp)
		return (NULL);
	free(save);
	save = NULL;
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buffer[1024 + 1];
	int			size;

	if (!ft_init(buffer, &save, fd))
		return (-1);
	size = 1;
	while (!ft_is_nl(buffer) && !ft_is_nl(save) && size)
	{
		size = read(fd, buffer, 1024);
		if (size > -1)
			buffer[size] = '\0';
		if (size <= 0)
		{
			if (size == 0)
				*line = ft_strdup(save);
			return (ft_free(&save, size));
		}
		save = ft_strjoin_gnl(save, buffer);
	}
	*line = ft_before_nl(save);
	save = ft_cut_save(save);
	if (!(*line) || !save)
		return (ft_free(&save, -1));
	return (1);
}
