/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:41:39 by qujacob           #+#    #+#             */
/*   Updated: 2022/01/29 20:39:48 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <X11/Xlib.h>

# define ESC 65307
# define DEL 65288
# define QUIT 79708224

# define L_ARROW 65361
# define U_ARROW 65362
# define R_ARROW 65363
# define D_ARROW 65364

# define Z_PLUS 61
# define Z_MINUS 45

# define ZOOM_IN 46
# define ZOOM_OUT 44

# define ONE 49
# define TWO 50
# define THREE 51
# define FOUR 52
# define FIVE 53

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_vector;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
}	t_data;

typedef struct s_camera
{
	int		zoom;
	int		move_x;
	int		move_y;
	double	z_booster;
}	t_camera;

typedef struct s_menu
{
	int		menu_on;
	t_data	img;
}	t_menu;

typedef struct s_tab
{
	char		*filename;
	int			**map;
	int			size_x;
	int			size_y;
	char		*tmp;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_w;
	int			win_h;
	t_menu		menu;
	t_camera	*camera;
	t_data		img;
}	t_tab;

void		parse_map(t_tab *tab);

void		print_map(t_tab *tab);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_map(t_tab *tab);

t_camera	*init_camera(t_tab *tab);
t_vector	iso(t_tab *tab, int x, int y);

int			select_action(int key, t_tab *tab);
int			quit(t_tab *tab);
void		zoom(t_tab *tab, int key);
void		move(t_tab	*tab, int key);
void		size_boost(t_tab *tab, int key);
void		reset(t_tab *tab);
void		change_color(t_tab *tab, int key);
void		menu(t_tab *tab);

void		error_message(char *message, int ret);
void		free_tab(t_tab *tab);
void		free_message(t_tab *tab, char *message, int ret);
void		free_strs(char **strs);
void		properly_quit_gnl(t_tab *tab, char **strs, int r, int fd);
#endif
