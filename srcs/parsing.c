/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:11:10 by qujacob           #+#    #+#             */
/*   Updated: 2022/01/29 20:34:47 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_file(t_tab *tab)
{
	int		fd;
	char	*needle;

	needle = ft_strstr(tab->filename, ".fdf");
	if (!needle || ft_strcmp(needle, ".fdf"))
		free_message(tab, "Error : Invalid map name.\n", 1);
	fd = open(tab->filename, O_RDWR);
	if (fd == -1)
		free_message(tab, "Error : File doesn't exist.\n", 1);
	return (fd);
}

int	count_y(t_tab *tab)
{
	int		fd;
	int		count;
	int		r;

	fd = open_file(tab);
	count = 0;
	r = 1;
	while (r > 0)
	{
		r = get_next_line(fd, &(tab->tmp));
		if (r < 0)
			free_message(tab, "Error : gnl\n", 1);
		else if (r == 0)
		{
			free(tab->tmp);
			break ;
		}
		count++;
		free(tab->tmp);
	}
	close(fd);
	return (count);
}

void	fill_map_i(t_tab *tab, int i, int r, int fd)
{
	char	**strs;
	int		is_rectangle;
	int		j;

	strs = ft_split(tab->tmp, ' ');
	free(tab->tmp);
	is_rectangle = 0;
	while (strs[is_rectangle])
		is_rectangle++;
	if (i != 0 && is_rectangle != tab->size_x)
	{
		properly_quit_gnl(tab, strs, r, fd);
	}
	tab->size_x = is_rectangle;
	tab->map[i] = (int *)malloc(sizeof(int) * tab->size_x);
	if (!(tab->map[i]))
		free_message(tab, "Error : malloc\n", 1);
	j = -1;
	while (++j < tab->size_x)
		tab->map[i][j] = ft_atoi(strs[j]);
	free_strs(strs);
	tab->size_y++;
}

void	parse_map(t_tab *tab)
{
	int		fd;
	int		i;
	int		r;

	fd = open_file(tab);
	tab->size_y = count_y(tab);
	if (!(tab->size_y))
		free_message(tab, "Error : Empty map\n", 1);
	tab->map = (int **)malloc(sizeof(int *) * tab->size_y);
	if (!tab->map)
		free_message(tab, "Error : malloc\n", 1);
	i = -1;
	r = 1;
	tab->size_y = 0;
	while (r > 0)
	{
		r = get_next_line(fd, &(tab->tmp));
		if (r < 0)
			free_message(tab, "Error : gnl\n", 1);
		else if (r == 0)
			break ;
		fill_map_i(tab, ++i, r, fd);
	}
	free(tab->tmp);
	close(fd);
}
