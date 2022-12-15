/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:46:46 by qujacob           #+#    #+#             */
/*   Updated: 2022/01/25 18:09:37 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
	(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	is_smaller(int small, int big)
{
	if (small < big)
		return (1);
	return (-1);
}

void	bresenham(t_tab *tab, t_vector f, t_vector l)
{
	t_vector	d;
	t_vector	s;
	int			error[2];

	d.x = abs(l.x - f.x);
	d.y = abs(l.y - f.y);
	s.x = is_smaller(f.x, l.x);
	s.y = is_smaller(f.y, l.y);
	error[0] = d.x - d.y;
	while (f.x != l.x || f.y != l.y)
	{
		if (f.x >= 0 && f.x < tab->win_w && f.y >= 0 && f.y < tab->win_h)
			my_mlx_pixel_put(&(tab->img), f.x, f.y, tab->img.color);
		error[1] = error[0] * 2;
		if (error[1] > -(d.y))
		{
			error[0] -= d.y;
			f.x += s.x;
		}
		if (error[1] < d.x)
		{
			error[0] += d.x;
			f.y += s.y;
		}
	}
}

void	draw_map(t_tab *tab)
{
	int		i;
	int		j;

	tab->img.img = mlx_new_image(tab->mlx_ptr, tab->win_w, tab->win_h);
	tab->img.addr = mlx_get_data_addr(tab->img.img, &(tab->img.bits_per_pixel), \
	&(tab->img.line_length), &(tab->img.endian));
	j = -1;
	while (++j < tab->size_y)
	{
		i = -1;
		while (++i < tab->size_x)
		{
			if (i < tab->size_x - 1)
				bresenham(tab, iso(tab, i, j), iso(tab, i + 1, j));
			if (j < tab->size_y - 1)
				bresenham(tab, iso(tab, i, j), iso(tab, i, j + 1));
		}
	}
	mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr, tab->img.img, 0, 0);
	mlx_destroy_image(tab->mlx_ptr, tab->img.img);
	mlx_loop(tab->mlx_ptr);
}
