/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:45:41 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/06 17:23:34 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_specifiers(t_print *print, va_list arg, int *counter)
{
	if (print->specifier == '%')
		ft_print_c(print, '%', counter);
	else if (print->specifier == 'c')
		ft_print_c(print, va_arg(arg, int), counter);
	else if (print->specifier == 's')
		return (ft_print_s(print, va_arg(arg, char *), counter));
	else if (print->specifier == 'd' || print->specifier == 'i')
		return (ft_print_di(va_arg(arg, int), counter));
	else if (print->specifier == 'u')
		return (ft_print_uxX(va_arg(arg, unsigned int), counter, DECIMAL));
	else if (print->specifier == 'p')
		return (ft_print_p(va_arg(arg, unsigned long int), counter));
	else if (print->specifier == 'x')
		return (ft_print_uxX(va_arg(arg, unsigned int), counter, L_HEXA));
	else if (print->specifier == 'X')
		return (ft_print_uxX(va_arg(arg, unsigned int), counter, U_HEXA));
	return (1);
}

void	ft_print_padding(t_print *print, int *counter)
{
	int	i;

	i = -1;
	while (++i < (print->width - print->precision))
		*counter += write(1, " ", 1);
}
