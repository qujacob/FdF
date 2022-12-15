/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:35 by qujacob           #+#    #+#             */
/*   Updated: 2022/01/25 18:09:20 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_tab *tab)
{
	tab->camera->zoom = ft_min(tab->win_w / tab->size_x / 2,
			tab->win_h / tab->size_y / 2);
	tab->camera->move_x = 0;
	tab->camera->move_y = 0;
	tab->camera->z_booster = 1;
	tab->img.color = 0x00FFFFFF;
	draw_map(tab);
}

void	change_color(t_tab *tab, int key)
{
	if (key == ONE)
		tab->img.color = 0x00FFFFFF;
	else if (key == TWO)
		tab->img.color = 0x00355C7D;
	else if (key == THREE)
		tab->img.color = 0x006C5B7B;
	else if (key == FOUR)
		tab->img.color = 0x00C06C84;
	else if (key == FIVE)
		tab->img.color = 0x00A36E50;
	draw_map(tab);
}
