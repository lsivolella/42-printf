/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:45:41 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/06 16:59:01 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_specifiers(t_print *print, va_list arg, int *counter)
{
	// remove returns for mandatory delivery?
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

int	ft_print_c(t_print *print, int nbr, int *counter)
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

int	ft_print_s(t_print *print, char *str, int *counter)
{
	int	str_len;

	if (!str)
	{
		str = "(null)";
		if (print->do_pres && print->precision < 6)
			print->precision = 0;
	}
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

int	ft_print_di(int nbr, int *counter)
{
	t_int	*num;
	char	*str;
	int		str_len;

	num = (t_int *)malloc(sizeof(t_int));
	num->positive = nbr >= 0;
	if (nbr < 0)
		num->value = -(unsigned long long int)nbr;
	else
		num->value = (unsigned long long int)nbr;
	str = ft_utoa(num, DECIMAL);
	str_len = ft_strlen(str);
	if (!num->positive)
		*counter += write(1, "-", 1);
	*counter += write(1, str, str_len);
	free(str);
	free(num);
	return (*counter);
}

int	ft_print_uxX(unsigned int nbr, int *counter, char *base)
{
	t_int	*num;
	char	*str;
	int		str_len;

	num = (t_int *)malloc(sizeof(t_int));
	num->positive = TRUE;
	num->value = nbr;
	str = ft_utoa(num, base);
	str_len = ft_strlen(str);
	*counter += write(1, str, str_len);
	free(str);
	free(num);
	return (*counter);
}

int	ft_print_p(unsigned long int nbr, int *counter)
{
	t_int	*num;
	char	*str;
	int		str_len;

	if (!nbr)
	{
		*counter += write(1, "(nil)", 5);
		return (*counter);
	}
	num = (t_int *)malloc(sizeof(t_int));
	num->positive = TRUE;
	num->value = nbr;
	str = ft_utoa(num, L_HEXA);
	str_len = ft_strlen(str);
	*counter += write(1, "0x", 2);
	*counter += write(1, str, str_len);
	free(str);
	free(num);
	return (*counter);
}
