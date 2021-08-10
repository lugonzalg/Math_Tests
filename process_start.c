/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:45:30 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/10 12:45:34 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "handle.h"
#include "Libft/libft.h"
#include <stdlib.h>

static int	ft_isdigit_double(int c)
{
	if (c == '-')
		return (1);
	if ((c < 48 || c > 57) && c != '.')
		return (0);
	return (1);
}

static int	check_neg(int *neg, char c)
{
	if (c == '-')
	{
		*neg = -1;
		return (1);
	}
	return (0);
}

static double	ft_atoi_double(const char *str)
{
	double	out;
	int		neg_decimal[2];

	neg_decimal[0] = 0;
	neg_decimal[1] = 1;
	out = 0.0;
	if (check_neg(&neg_decimal[1], *str))
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			str++;
			neg_decimal[0] = 10;
		}
		if (!neg_decimal[0] && ft_isdigit_double(*str))
			out = out * 10 + (*str - '0');
		else if (neg_decimal[0] && ft_isdigit_double(*str))
		{
			out = out + ((double)(*str - '0') / neg_decimal[0]);
			neg_decimal[0] *= 10;
		}
		str++;
	}
	return (out * neg_decimal[1]);
}

static char	check_digit(char *str)
{
	int		neg_decimal[2];
	double	n;

	neg_decimal[0] = 0;
	neg_decimal[1] = 0;
	n = ft_atoi_double(str);
	if (n > 2.0 || n < -2.0)
		warning_3(n);
	while (*str)
	{
		if (!ft_isdigit_double(*str))
			return (1);
		if (*str == '.')
			neg_decimal[0]++;
		if (*str == '-')
			neg_decimal[1]++;
		if (neg_decimal[0] > 1 || neg_decimal[1] > 1)
			return (1);
		if (*str == '.' && *(str + 1) == 0)
			return (1);
		str++;
	}
	return (0);
}

int	process_start(char **argv, int argc, t_ptr *ptr)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		ptr->set = 1;
		return (1);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (check_digit(argv[2]) || check_digit(argv[3]))
		{
			warning_2();
			exit(0);
		}
		ptr->pos_a = ft_atoi_double(argv[2]);
		ptr->pos_b = ft_atoi_double(argv[3]);
		ptr->set = 0;
		return (1);
	}
	return (0);
}
