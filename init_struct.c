/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:22:11 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/10 13:22:12 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "handle.h"
#include "../mlx_src/minilibx_opengl_20191021/mlx.h"

void	init_frac(t_coord *frac)
{
	frac->x = -1;
	frac->y = -1;
	frac->a = 1.0;
	frac->b = 1.0;
	frac->aa = 0.0;
	frac->bb = 0.0;
	frac->i = 0;
}

void	init_mlx(t_ptr *ptr)
{
	ptr->color = 1;
	ptr->max_x = 2.0;
	ptr->max_y = 2.0;
	ptr->min_x = -2.0;
	ptr->min_y = -2.0;
	ptr->prp = 500;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 500, 500, "Fract'ol 0.1");
	ptr->img = mlx_new_image(ptr->mlx, 500, 500);
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel,
			&ptr->line_length, &ptr->endian);
}
