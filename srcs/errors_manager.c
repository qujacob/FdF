/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:24:16 by qujacob           #+#    #+#             */
/*   Updated: 2022/01/29 20:42:39 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_message(char *message, int ret)
{
	ft_putstr_fd(message, 2);
	exit(ret);
}

void	free_message(t_tab *tab, char *message, int ret)
{
	free_tab(tab);
	error_message(message, ret);
}

void	free_tab(t_tab *tab)
{
	int	i;

	i = -1;
	if (tab->map)
	{
		while (++i < tab->size_y)
			if (tab->map[i])
				free(tab->map[i]);
		free(tab->map);
	}
	if (tab->camera)
		free(tab->camera);
	free(tab);
}

void	free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

void	properly_quit_gnl(t_tab *tab, char **strs, int r, int fd)
{
	while (r > 0)
	{
		r = get_next_line(fd, &(tab->tmp));
		free(tab->tmp);
	}
	free_strs(strs);
	free_message(tab, "Error : Map isn't a rectangle.\n", 1);
}
