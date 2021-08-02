/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:50:36 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/02 16:51:10 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
//Print a triangle using line function, y = xm + b || m = y2 - y1 / x2 - x1
void	print_tri(int side)
{
	int 	sides;
	float	x;
	float	y;
	float	ratio;

	sides = 0;
	x = 0;
	y = 0;
	ratio = sides / 2;

	while (sides < 3)
	{
		while (x < ratio)
		{
			y = x * sqrt(3);
			//Pixel representation
			my_mlx_pixel_put(&img, 300 + x, 100 + y, 0xFFFFFFFF);
			x += 0.1;
			color += 1;
		}
		sides++;
		while (x > -ratio)
		{
			my_mlx_pixel_put(&img, 300 + x, 100 + y, 0x00FF0000);
			x -= 0.1;
		}
		sides++;
		while (x < 0)
		{
			y = x * (-sqrt(3));
			//Pixel representation
			my_mlx_pixel_put(&img, 300 + x, 100 + y, 0xFF00FF00);
			x += 0.1;
	}
	sides++;
	}
}

//Print a circle using sin and cos. First try doing trigonometrichs without knowledge, using
//YouTube -> Code Math // great source. 
void	print_circle(float radius)
{
	float	angle;
	float	x;
	float	y;

	x = 0;
	y = 0;
	angle = 0;
	while (angle < M_PI * 2)
	{
		angle += 0.00001;
		x = radius * cos(angle);
		y = radius * sin(angle);
		//Pixel representation
		my_mlx_pixel_put(&img, 300 + x, 300 + y, 0x00FF0000);
	}
}
//Prin a Hexagon using, y = xm + b || m = ... || 
void	print_hexagon(int side)
{
	int		sides;
	float	x;
	float	x2;
	float	y;
	float	y2;
	float	ratio;

	x = 0;
	x2 = 0;
	y = 0;
	y2 = 0;
	ratio = side / 2;
	while (sides < 1)
	{
		//write the positive diagonal
		while (x2 < ratio)
		{
			y2 = x2 * sqrt(3);
			my_mlx_pixel_put(&img, 300 + x2, 100 + y2, 0xFFFFFFFF);
			my_mlx_pixel_put(&img, 300 + x2, 100 - y2, 0x00FF0000);
			x2 += 0.1;
		}
		sides++;
		//write the horizontal line
		x = x2;
		while (x < side + ratio)
		{
			my_mlx_pixel_put(&img, 300 + x, 100 + y2, 0xFF00FF00);
			my_mlx_pixel_put(&img, 300 + x, 100 - y2, 0xFFFFFFFF);
			x += 0.1;
		}
		sides++;
		//write the rest of the diagonals
		while (x2 > 0)
		{
			y2 = x2 * sqrt(3);
			my_mlx_pixel_put(&img, 300 + x, 100 + y2, 0x00FF0000);
			my_mlx_pixel_put(&img, 300 + x, 100 - y2, 0x00FF0000);
			x2 -= 0.1;
			x += 0.1;
		}
		sides++;
		//write the horizont line
	}
