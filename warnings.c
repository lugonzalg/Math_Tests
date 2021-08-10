/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warnings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:11:08 by lugonzal          #+#    #+#             */
/*Updated: 2021/08/08 17:11:37 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <string.h>

void	warning_3(int n)
{
	ft_printf("\033[0;31m");
	ft_printf("\n ///////////////////////////[WARNING!]///////////////////////");
	ft_printf("\n \t\t\tUSELESS PARAM ->\033[0;33m %d\033[0m\t\t\t", n);
	ft_printf("\033[0m");
	ft_printf("\n Even you are curius about thos size's,");
	ft_printf("there is nothing interesting");
	ft_printf("\n to see, please, remember that julia fractals");
	ft_printf("work in betwen 2.0 and -2.0.");
	ft_printf("\n \n Se you on next successful try, \033[0;33m2.0 && -2.0!\033[0m");
	ft_printf("\033[0;31m ");
	ft_printf("\n////////////////////////////////////////////////////////////\n");
	ft_printf("\033[0m");
}

int	warning_2(void)
{
	ft_printf("\033[0;31m");
	ft_printf("\n ///////////////////////////[WARNING!]///////////////////////");
	ft_printf("\n \t\t\t%s\t\t\t", strerror(22));
	ft_printf("\033[0m");
	ft_printf("\nYou are trying to use an invalid input for the julia set.");
	ft_printf("\nPlease, retry it just using numeric parameters");
	ft_printf("\nJulia set fractals work in between 2.0 and -2.0");
	ft_printf("\033[0;33m ");
	ft_printf("\n\nFor example -> julia 1.2 0.3");
	ft_printf("\033[0m");
	ft_printf("\033[0;31m ");
	ft_printf("\n////////////////////////////////////////////////////////////");
	ft_printf("\033[0m");
	return (0);
}

void	warning(void)
{
	ft_printf("\033[0;31m");
	ft_printf("\n ///////////////////////////[WARNING!]///////////////////////");
	ft_printf("\n \t\t\t%s\t\t\t", strerror(22));
	ft_printf("\033[0m");
	ft_printf("\n You are trying to run this program without");
	ft_printf("any parameter input");
	ft_printf("\n Please, rerun this program using accepted parameters ");
	ft_printf("\n \n Such as: ");
	ft_printf("\n\n \tmandelbrot \033[0;32m(ONLY FRACTAL");
	ft_printf("NAME AS PARAMETER)\033[0m");
	ft_printf("\n \tjulia \033[0;32m(FRACTAL NAME AND IT´S VALUES\033[0m");
	ft_printf("\t\033[0;33mI.E -> fracta.a Julia [1.2] [0.5] \033[0m");
	ft_printf("\n \n Thank you for your attention, see you in a");
	ft_printf("succesfull retry");
	ft_printf("\033[0;31m ");
	ft_printf("\n////////////////////////////////////////////////////////////");
	ft_printf("\033[0m");
}
