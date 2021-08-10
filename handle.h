/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:06:46 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/10 13:07:25 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H

# include <stdio.h>

typedef struct s_coord {
	int		i;
	int		x;
	int		y;
	double	a;
	double	aa;
	double	b;
	double	bb;
	double	tmp_a;
	double	tmp_b;
}	t_coord;

typedef struct s_ptr {
	double	pos_a;
	double	pos_b;
	void	*win;
	void	*mlx;
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	int		prp;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		set :1;
	double	abs_x;
	double	abs_y;
	int		color;
}	t_ptr;

void	warning(void);
void	warning_2(void);
void	warning_3(int n);
int		process_start(char **argv, int argc, t_ptr *ptr);
void	init_frac(t_coord *frac);
void	init_mlx(t_ptr *ptr);
int		mouse(int button, int x, int y, t_ptr *ptr);
int		move(int keycode, t_ptr *ptr);
double	ft_abs(double num);
void	fractal_set(t_ptr ptr);
double	scl_range(int size, int to_scl, double max_range, double min_range);
#endif

//void	(*set)(struct s_ptr ptr, struct s_coord *frac);
