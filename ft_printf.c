/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:18:27 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 12:59:43 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_print(t_print *print)
{
	print->flag_error = false;
	print->left_justify = false;
	print->zero_padding = false;
	print->explicit_sign = false;
	print->hash = false;
	print->width = 0;
	print->precision = 0;
	print->specifier = '0';
}

void	ft_get_flag_size(t_print *print, va_list arg, const char *str, int *pos)
{
	if (str[*pos] == PRECISION)
	{
		(*pos)++;
		if (str[*pos] == STAR)
			print->precision = va_arg(arg, int);
		else if (ft_find_char(DECIMAL, str[*pos]) || ft_isalpha(str[*pos]))
		{
			print->precision = ft_atoi_print(print ,str, pos);
			(*pos)--;
		}
		else if (str[*pos] == MINUS || str[*pos] == PLUS)
			print->flag_error = true;
	}
	else
	{
		if (str[*pos] == STAR)
			print->width = va_arg(arg, int);
		else if (ft_find_char(DECIMAL, str[*pos]))
		{
			print->width = ft_atoi_print(print, str, pos);
			(*pos)--;
		}
	}
	ft_treat_width(print);
}

void	ft_treat_width(t_print *print)
{
	if (print->flag_error)
		return;
	if (print->width < 0)
	{
		print->left_justify = true;
		print->width *= -1;
	}
}

void	ft_handle_flags(t_print *print, va_list arg, const char *str, int *pos)
{
	while (!print->flag_error && str[*pos] && !ft_find_char(SPECIFIERS, str[*pos]))
	{
		if (str[*pos] == MINUS)
			print->left_justify = true;
		else if (str[*pos] == PLUS)
			print->explicit_sign = true;
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
		(*pos)++;
	}
	if (!print->flag_error && str[*pos] && ft_find_char(SPECIFIERS, str[*pos]))
		print->specifier = str[*pos];
}

int	ft_print_arg(va_list arg, const char *str, int *counter, int *pos)
{
	t_print	*print;

	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	ft_initialize_print(print);
	ft_handle_flags(print, arg, str, pos);
	if (print->flag_error || print->specifier == '0')
		return (-1);
	ft_specifiers(print, arg, counter);
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
