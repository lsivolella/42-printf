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

void	ft_init_tprint(t_print *print)
{
	print->left_justify = false;
	print->zero_padding = false;
	print->explicit_sign = false;
	print->hash = false;
	print->width = -1;
	print->precision = -1;
	print->specifier = '\0';
}

void	ft_flag_size(t_print *print, va_list arg, const char *str, t_pos *pos)
{
	// HANDLE ARGUMENT IS 0 -> WHAT HAPPENS WHEN WIDTH OR PRECISION ARE 0??
	if (str[pos->index] == PRECISION)
	{
		(pos->index)++;
		if (str[pos->index] == STAR)
			print->precision = va_arg(arg, int);
		else if (ft_find_char(DECIMAL, str[pos->index]))
		{
			print->precision = ft_atoi(str, pos);
			(pos->index)--;
		}
	}
	else
	{
		if (str[pos->index] == STAR)
			print->width = va_arg(arg, int);
		else if (ft_find_char(DECIMAL, str[pos->index]))
		{
			print->width = ft_atoi(str, pos);
			(pos->index)--;
		}
	}
}

void	ft_set_flags(t_print *print, va_list arg, const char *str, t_pos *pos)
{
	while (!ft_find_char(SPECIFIERS, str[pos->index]) && str[pos->index])
	{
		if (str[pos->index] == MINUS)
			print->left_justify = true;
		else if (str[pos->index] == ZERO)
			print->zero_padding = true;
		else if (str[pos->index] == PRECISION
			|| ft_find_char(DECIMAL, str[pos->index])
			|| str[pos->index] == STAR)
			ft_flag_size(print, arg, str, pos);
		else if (str[pos->index] == HASH)
			print->hash = true;
		else if (str[pos->index] == SPACE)
			print->empty_space = true;
		else if (str[pos->index] == PLUS)
			print->explicit_sign = true;
		(pos->index)++;
		if (str[pos->index] == PERCENT)
			print->specifier = PERCENT;
	}
}

int	ft_print_arg(va_list arg, const char *str, t_pos *pos)
{
	t_print	*print;

	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	ft_init_tprint(print);
	ft_set_flags(print, arg, str, pos);
	// ft_handle_specifier_print -> coordinates printing
	print_struct(*print);
	free(print);
	return (1);
}

void	ft_init_tpos(t_pos *pos)
{
	pos->index = -1;
	pos->counter = 0;
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arg;
	t_pos	*pos;

	ret = 0;
	va_start(arg, format);
	pos = (t_pos *)malloc(sizeof(t_pos));
	if (!pos)
		return (-1);
	ft_init_tpos(pos);
	while (format[++pos->index])
	{
		if (format[pos->index] != PERCENT)
			pos->counter += write(1, &format[pos->index], 1);
		else
		{
			ret = pos->index++;
			if (ft_print_arg(arg, format, pos) < 0)
				return (-1);
		}
	}
	va_end(arg);
	free(pos);
	return (ret);
}
