/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:45:41 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 23:01:45 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_specifiers(t_print *print, va_list arg, int *counter)
{
	// improve return of print functions
	// need to ignore non-required specifiers and jump arg
	// ex: alguem enviou um double 'f' para imprimir. Devo ignora-lo e seguir com o programa
	if (print->specifier == '%')
		ft_print_char(print, '%', counter);
	else if (print->specifier == 'c')
		ft_print_char(print, va_arg(arg, int), counter);
	else if (print->specifier == 's')
		return (ft_print_string(print, va_arg(arg, char *), counter));
	else if (print->specifier == 'd' || print->specifier == 'i')
		return (ft_print_integer(print, va_arg(arg, int), counter));
	else if (print->specifier == 'u')
		return (ft_print_u_integer(print, va_arg(arg, unsigned int), counter));
	else if (print->specifier == 'p')
		printf("Found p specifier");
	else if (print->specifier == 'x')
		printf("Found x specifier");
	else if (print->specifier == 'X')
		printf("Found X specifier");
	return (1);
}

void	ft_print_padding(t_print *print, int *counter)
{
	int	i;

	i = -1;
	while (++i < (print->width - print->precision))
		*counter += write(1, " ", 1);
}

int	ft_print_char(t_print *print, int nbr, int *counter)
{
	if (print->specifier == '%')
		*counter += write(1, &nbr, 1);
	else if (print->specifier == 'c')
	{
		print->precision = 1;
		if (!print->left_justify)
		{
			ft_print_padding(print, counter);
			*counter += write(1, &nbr, 1);
		}
		else
		{
			*counter += write(1, &nbr, 1);
			ft_print_padding(print, counter);
		}
	}
	return (*counter);
}

int	ft_print_string(t_print *print, char *str, int *counter)
{
	int	str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (!print->do_pres || (print->do_pres && print->precision > str_len))
		print->precision = str_len;
	if (print->width > 0 && print->width < str_len)
		print->width = str_len;
	if (!print->left_justify)
	{
		ft_print_padding(print, counter);
		*counter += write(1, str, print->precision);
	}
	else
	{
		*counter += write(1, str, print->precision);
		ft_print_padding(print, counter);
	}
	return (*counter);
}

int	ft_print_integer(t_print *print, int nbr, int *counter)
{
	char	*str;
	int		str_len;

	str = ft_itoa(nbr);
	str_len = ft_strlen(str);
	print->precision = str_len;
	*counter += write(1, str, str_len);
	free(str);
	return (*counter);
}

int	ft_print_u_integer(t_print *print, unsigned int nbr, int *counter)
{
	char	*str;
	int		str_len;

	str = ft_utoa(nbr);
	str_len = ft_strlen(str);
	print->precision = str_len;
	*counter += write(1, str, str_len);
	free(str);
	return (*counter);
}
