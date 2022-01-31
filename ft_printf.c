/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:18:27 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/01/31 20:17:14 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_print(t_print *print)
{
	print->left_justify = false;
	print->zero_padding = false;
	print->explicit_sign = false;
	print->hash = false;
	print->width = -1;
	print->precision = -1;
	print->specifier = '0';
}

void	ft_get_flag_size(t_print *print, va_list arg, const char *str, int *pos)
{
	// HANDLE ARGUMENT IS 0 -> WHAT HAPPENS WHEN WIDTH OR PRECISION ARE 0??
	if (str[*pos] == PRECISION)
	{
		(*pos)++;
		if (str[*pos] == STAR)
			print->precision = va_arg(arg, int);
		else if (ft_find_char(DECIMAL, str[*pos]))
		{
			print->precision = ft_atoi(str, pos);
			(*pos)--;
		}
	}
	else
	{
		if (str[*pos] == STAR)
			print->width = va_arg(arg, int);
		else if (ft_find_char(DECIMAL, str[*pos]))
		{
			print->width = ft_atoi(str, pos);
			(*pos)--;
		}
	}
}

void	ft_handle_flags(t_print *print, va_list arg, const char *str, int *pos)
{
	while (!ft_find_char(SPECIFIERS, str[*pos]) && str[*pos])
	{
		if (str[*pos] == MINUS)
			print->left_justify = true;
		else if (str[*pos] == ZERO)
			print->zero_padding = true;
		else if (str[*pos] == PRECISION
			|| ft_find_char(DECIMAL, str[*pos])
			|| str[*pos] == STAR)
			ft_get_flag_size(print, arg, str, pos);
		else if (str[*pos] == HASH)
			print->hash = true;
		else if (str[*pos] == SPACE)
			print->empty_space = true;
		else if (str[*pos] == PLUS)
			print->explicit_sign = true;
		(*pos)++;
		if (str[*pos] == PERCENT)
			print->specifier = PERCENT;
	}
}

int	ft_print_arg(va_list arg, const char *str, int *counter, int *pos)
{
	t_print	*print;

	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	ft_initialize_print(print);
	ft_handle_flags(print, arg, str, pos);
	// ft_handle_specifier_print -> coordinates printing
	print_struct(*print);
	free(print);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			counter;
	int			pos;

	counter = 0;
	pos = -1;
	va_start(arg, format);
	while (format[++pos])
	{
		if (format[pos] != PERCENT)
			counter += write(1, &format[pos], 1);
		else
		{
			pos++;
			if (ft_print_arg(arg, format, &counter, &pos) < 0)
				return (-1);
		}
	}
	va_end(arg);
	return (counter);
}
