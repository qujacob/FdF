/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:16:23 by qujacob           #+#    #+#             */
/*   Updated: 2022/01/25 18:09:05 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*init_camera(t_tab	*tab)
{
	t_camera	*c;

	c = (t_camera *)malloc(sizeof(t_camera));
	if (!c)
		free_message(tab, "Free Error.\n", 1);
	c->zoom = ft_min(tab->win_w / tab->size_x / 2,
			tab->win_h / tab->size_y / 2);
	c->move_x = 0;
	c->move_y = 0;
	c->z_booster = 1;
	return (c);
}

t_vector	iso(t_tab *tab, int x, int y)
{
	t_vector	v;

	v.z = tab->map[y][x] / tab->camera->z_booster;
	x *= tab->camera->zoom;
	y *= tab->camera->zoom;
	v.x = (x - y) * cos(0.523599);
	v.y = -(v.z) + (x + y) * sin(0.523599);
	v.x += (tab->win_w - tab->size_x) / 2 + tab->camera->move_x;
	v.y += (tab->win_h / tab->size_y) / 2 + tab->camera->move_y;
	return (v);
}
