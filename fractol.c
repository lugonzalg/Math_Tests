/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:15:41 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/04 16:15:43 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_src/minilibx_opengl_20191021/mlx.h"
#include <unistd.h>
#include "handle.h"
#include <math.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"
#include <strings.h>
#include "Libft/libft.h"
#include <stdlib.h>

void	my_mlx_pixel_put(t_ptr *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	spectral_color(t_coord frac, t_ptr ptr)
{
	int	color;

	color = 16777;
	if (frac.i == 50)
		my_mlx_pixel_put(&ptr, frac.x, frac.y, 0x000000);
	else
		my_mlx_pixel_put(&ptr, frac.x, frac.y, frac.i * (color * ptr.color));
}

void	mandelbrot(t_ptr ptr, t_coord *frac)
{
	frac->i = -1;
	frac->aa = 0.0;
	frac->bb = 0.0;
	frac->a = scl_range(ptr.prp, frac->x, ptr.max_x, ptr.min_x);
	frac->b = -scl_range(ptr.prp, frac->y, ptr.max_y, ptr.min_y);
	if (ptr.set)
	{
		frac->tmp_a = frac->a;
		frac->tmp_b = frac->b;
	}
	else
	{
		frac->tmp_a = ptr.pos_a;
		frac->tmp_b = ptr.pos_b;
	}
	while (++frac->i < 50)
	{
		frac->aa = (frac->a * frac->a) - (frac->b * frac->b);
		frac->bb = 2 * frac->a * frac->b;
		frac->a = frac->aa + frac->tmp_a;
		frac->b = frac->bb + frac->tmp_b;
		if (frac->aa + frac->bb > 16.0 || frac->aa + frac->bb < -16.0)
			break ;
	}
}

void	fractal_set(t_ptr ptr)
{
	t_coord	frac;

	init_frac(&frac);
	while (++frac.x < ptr.prp)
	{
		frac.y = -1;
		while (++frac.y < ptr.prp)
		{
			mandelbrot(ptr, &frac);
			spectral_color(frac, ptr);
		}
	}
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_ptr	ptr;

	if (process_start(argv, argc, &ptr))
	{
		init_mlx(&ptr);
		fractal_set(ptr);
		mlx_hook(ptr.win, 2, 1L << 0, move, &ptr);
		mlx_hook(ptr.win, 4, 1L << 1, mouse, &ptr);
		mlx_loop(ptr.mlx);
	}
	else
		warning();
	return (1);
}

//https://harm-smits.github.io/42docs/libs/minilibx/events.html
//https://www.youtube.com/watch?v=6z7GQewK-Ks
