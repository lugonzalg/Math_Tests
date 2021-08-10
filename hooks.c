/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:27:19 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/10 13:28:05 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "handle.h"
#include "../mlx_src/minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>

static int	move_2(int keycode, t_ptr *ptr)
{
	if (keycode == 123)
	{
		ptr->max_x += ptr->abs_x * 24;
		ptr->min_x += ptr->abs_x * 24;
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit (0);
	}
	if (keycode >= 18 && keycode < 28)
		ptr->color = keycode - 17;
	return (1);
}

int	move(int keycode, t_ptr *ptr)
{
	ptr->abs_x = (ptr->max_x - ptr->min_x) / 500;
	ptr->abs_y = (ptr->max_y - ptr->min_y) / 500;
	if (keycode == 126)
	{
		ptr->max_y += ptr->abs_y * 24;
		ptr->min_y += ptr->abs_y * 24;
	}
	else if (keycode == 125)
	{
		ptr->max_y -= ptr->abs_y * 24;
		ptr->min_y -= ptr->abs_y * 24;
	}
	else if (keycode == 124)
	{
		ptr->max_x -= ptr->abs_x * 24;
		ptr->min_x -= ptr->abs_x * 24;
	}
	else if (keycode == 123 || keycode == 53 || keycode > 17)
		move_2(keycode, ptr);
	fractal_set(*ptr);
	return (1);
}	

static void	increase(t_ptr *ptr, int x, int y)
{
	double	x_coord;
	double	y_coord;

	x_coord = -scl_range(ptr->prp, x, ptr->max_x, ptr->min_x);
	y_coord = -scl_range(ptr->prp, y, ptr->max_y, ptr->min_y);
	if (y_coord - (ptr->max_y - (ptr->max_y - ptr->min_y) / 2) >= 0)
	{
		ptr->max_y += ptr->abs_y * 24;
		ptr->min_y += ptr->abs_y * 24;
	}
	else if ((y_coord - ptr->max_y - (ptr->max_y - ptr->min_y) / 2) < 0)
	{
		ptr->max_y -= ptr->abs_y * 24;
		ptr->min_y -= ptr->abs_y * 24;
	}
	if (x_coord - (ptr->max_x - (ptr->max_x - ptr->min_x) / 2) >= 0)
	{
		ptr->max_x += ptr->abs_x * 24;
		ptr->min_x += ptr->abs_x * 24;
	}
	else if ((x_coord - ptr->max_x - (ptr->max_x - ptr->min_x) / 2) < 0)
	{
		ptr->max_x -= ptr->abs_x * 24;
		ptr->min_x -= ptr->abs_x * 24;
	}
}

static void	mouse_2(int button, int x, int y, t_ptr *ptr)
{
	double	x_coord;
	double	y_coord;

	ptr->abs_x = (ptr->max_x - ptr->min_x) / 500;
	ptr->abs_y = (ptr->max_y - ptr->min_y) / 500;
	x_coord = -scl_range(ptr->prp, x, ptr->max_x, ptr->min_x);
	y_coord = -scl_range(ptr->prp, y, ptr->max_y, ptr->min_y);
	if (button == 5)
	{
		ptr->max_x += ptr->abs_x * 24;
		ptr->min_x -= ptr->abs_x * 24;
		ptr->max_y += ptr->abs_y * 24;
		ptr->min_y -= ptr->abs_y * 24;
		increase(ptr, x, y);
	}
}

int	mouse(int button, int x, int y, t_ptr *ptr)
{
	double	x_coord;
	double	y_coord;

	ptr->abs_x = (ptr->max_x - ptr->min_x) / 500;
	ptr->abs_y = (ptr->max_y - ptr->min_y) / 500;
	x_coord = -scl_range(ptr->prp, x, ptr->max_x, ptr->min_x);
	y_coord = -scl_range(ptr->prp, y, ptr->max_y, ptr->min_y);
	if (button == 4)
	{
		ptr->max_x -= ft_abs(ptr->abs_x) * 24;
		ptr->min_x += ft_abs(ptr->abs_x) * 24;
		ptr->max_y -= ft_abs(ptr->abs_y) * 24;
		ptr->min_y += ft_abs(ptr->abs_y) * 24;
		increase(ptr, x, y);
	}
	else if (button == 5)
		mouse_2(button, x, y, ptr);
	fractal_set(*ptr);
	return (1);
}
