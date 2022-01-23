/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:18:27 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/01/22 22:15:26 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_print(t_print *print)
{
	print->left_justify = false;
	print->zero_padding = false;
	print->explicit_sign = 'a';
	print->hash = false;
	print->width = -1;
	print->precision = -1;
}

void	ft_handle_flags(t_print *print, va_list arg, const char *str, int *pos)
{
	while (!ft_find_char(SPECIFIERS, str[++(*pos)]))
	{
		if (str[*pos] == MINUS && (*pos)++ > 0)
			print->left_justify = true;
		if (str[*pos] == ZERO && (*pos)++ > 0)
			print->zero_padding = true;
		if (str[*pos] == PRECISION && (*pos)++ > 0)
		{
			// se nao tiver numero na sequencia, precision = 0
			// se tiver numero existe uma string de numeros - tratar e armazenar o tamanho como int
			// se tiver uma estrela (precisao como argumento) - obter o argumento e armazenar como int
		}
		if (str[*pos] == HASH && (*pos)++ > 0)
			print->hash = true;
		if (str[*pos] == SPACE && (*pos)++ > 0)
			print->empty_space = true;
		if (str[*pos] == PLUS && (*pos)++ > 0)
			print->explicit_sign = true;
		//if find char de numero, converter para int (necessario iterar mais um pouco para pegar
		//numeros com mais de um digito)
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
	// handle specifier -> coordenar a impressao
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
		if (format[pos] != ARG_REQUEST)
			counter += write(1, &format[pos], 1);
		else
		{
			if (ft_print_arg(arg, format, &counter, &pos) < 0)
				return (-1);
		}
	}
	va_end(arg);
	return (counter);
}
