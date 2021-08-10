/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:31:44 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/10 13:31:45 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

double	ft_abs(double num)
{
	if (num < 0)
		num = -num;
	return (num);
}

double	scl_range(int size, int to_scl, double max_range, double min_range)
{
	double	abs_scl;
	double	scld;

	abs_scl = max_range - min_range;
	if (max_range < 0)
		max_range *= -1;
	else if (max_range >= 0)
		max_range *= -1;
	scld = max_range + ((abs_scl / size) * to_scl);
	return (scld);
}
