/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:16:05 by qujacob           #+#    #+#             */
/*   Updated: 2022/01/25 18:28:08 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	select_action(int key, t_tab *tab)
{
	if (key == ESC || key == QUIT)
		quit(tab);
	if (key == L_ARROW || key == R_ARROW || \
			key == U_ARROW || key == D_ARROW)
		move(tab, key);
	if (key == Z_PLUS || key == Z_MINUS)
		size_boost(tab, key);
	if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom(tab, key);
	if (key == ONE || key == TWO || key == THREE || \
			key == FOUR || key == FIVE)
		change_color(tab, key);
	if (key == DEL)
		reset(tab);
	return (0);
}

int	quit(t_tab	*tab)
{
	if (tab->mlx_ptr)
	{
		if (tab->win_ptr)
			mlx_destroy_window(tab->mlx_ptr, tab->win_ptr);
		mlx_destroy_display(tab->mlx_ptr);
		free(tab->mlx_ptr);
	}
	free_message(tab, "Goodbye !\n", 0);
	return (1);
}

void	zoom(t_tab *tab, int key)
{
	if (key == ZOOM_IN)
		tab->camera->zoom++;
	else if (key == ZOOM_OUT)
		tab->camera->zoom--;
	if (tab->camera->zoom < 1)
		tab->camera->zoom = 1;
	if (tab->camera->zoom > 100)
		tab->camera->zoom = 100;
	draw_map(tab);
}

void	move(t_tab *tab, int key)
{
	if (key == L_ARROW)
		tab->camera->move_x += 10;
	else if (key == R_ARROW)
		tab->camera->move_x -= 10;
	else if (key == U_ARROW)
		tab->camera->move_y += 10;
	else if (key == D_ARROW)
		tab->camera->move_y -= 10;
	draw_map(tab);
}

void	size_boost(t_tab *tab, int key)
{
	if (key == Z_PLUS)
		tab->camera->z_booster -= 0.1;
	else if (key == Z_MINUS)
		tab->camera->z_booster += 0.1;
	if (tab->camera->z_booster < 0.1)
		tab->camera->z_booster = 0.1;
	if (tab->camera->z_booster > 10)
		tab->camera->z_booster = 10;
	draw_map(tab);
}
