/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:01:34 by qujacob           #+#    #+#             */
/*   Updated: 2022/01/25 18:09:48 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tab	*init_tab(char *filename)
{
	t_tab	*tab;

	tab = (t_tab *)malloc(sizeof(t_tab));
	if (!tab)
		error_message("Error : malloc.\n", 1);
	tab->filename = filename;
	tab->map = NULL;
	tab->size_x = 0;
	tab->size_y = 0;
	tab->tmp = NULL;
	tab->mlx_ptr = NULL;
	tab->win_ptr = NULL;
	tab->win_w = 1920;
	tab->win_h = 1080;
	tab->menu.menu_on = 0;
	tab->menu.img.img = NULL;
	tab->camera = NULL;
	tab->img.img = NULL;
	tab->img.color = 0x00FFFFFF;
	return (tab);
}

void	print_map(t_tab *tab)
{
	tab->camera = init_camera(tab);
	tab->mlx_ptr = mlx_init();
	if (!(tab->mlx_ptr))
		free_message(tab, "Couldn't initialize MLX : Try again.\n", 1);
	tab->win_ptr = mlx_new_window(tab->mlx_ptr, tab->win_w, \
	tab->win_h, "FDF_42");
	mlx_hook(tab->win_ptr, KeyPress, KeyPressMask, select_action, tab);
	mlx_hook(tab->win_ptr, DestroyNotify, StructureNotifyMask, quit, tab);
	draw_map(tab);
}

int	main(int ac, char **av)
{
	t_tab	*tab;

	if (ac != 2)
		error_message("Usage : ./fdf [filename].fdf\n", 1);
	tab = init_tab(av[1]);
	parse_map(tab);
	print_map(tab);
	free_tab(tab);
	return (0);
}
