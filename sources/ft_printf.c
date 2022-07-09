/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:18:27 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/06 17:21:24 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_size(t_print *print, va_list arg, const char *str, int *pos)
{
	if (str[*pos] == PRECISION)
		ft_precis_flag(print, arg, str, pos);
	else
	{
		if (str[*pos] == STAR)
			print->width = va_arg(arg, int);
		else if (ft_find_char(DECIMAL, str[*pos]))
		{
			print->width = ft_atoi_print(print, str, pos);
			(*pos)--;
		}
		if (print->width < 0)
		{
			print->left_justify = TRUE;
			print->width *= -1;
		}
	}
}

void	ft_precis_flag(t_print *print, va_list arg, const char *str, int *pos)
{
	int	value;

	value = -1;
	(*pos)++;
	if (str[*pos] == STAR)
		value = va_arg(arg, int);
	else if (ft_find_char(DECIMAL, str[*pos]) || ft_isalpha(str[*pos]))
	{
		value = ft_atoi_print(print, str, pos);
		(*pos)--;
	}
	else if (str[*pos] == MINUS || str[*pos] == PLUS)
		print->flag_error = TRUE;
	print->do_pres = value >= 0;
	print->precision = value;
}

void	ft_handle_flags(t_print *print, va_list arg, const char *str, int *pos)
{
	while (!print->flag_error && str[*pos] && !ft_find_char(SPECS, str[*pos]))
	{
		if (str[*pos] == MINUS)
			print->left_justify = TRUE;
		else if (str[*pos] == PLUS)
			print->explicit_sign = TRUE;
		else if (str[*pos] == ZERO)
			print->zero_padding = TRUE;
		else if (str[*pos] == PRECISION
			|| ft_find_char(DECIMAL, str[*pos])
			|| str[*pos] == STAR)
			ft_flag_size(print, arg, str, pos);
		else if (str[*pos] == HASH)
			print->hash = TRUE;
		else if (str[*pos] == SPACE)
			print->empty_space = TRUE;
		(*pos)++;
	}
	if (!print->flag_error && str[*pos] && ft_find_char(SPECS, str[*pos]))
		print->specifier = str[*pos];
}

int	ft_print_arg(va_list arg, const char *str, int *counter, int *pos)
{
	t_print	*print;
	int		ret;

	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	ft_initialize_print(print);
	ft_handle_flags(print, arg, str, pos);
	if (print->flag_error || print->specifier == '0')
		return (-1);
	ret = ft_specifiers(print, arg, counter);
	free(print);
	return (ret);
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
