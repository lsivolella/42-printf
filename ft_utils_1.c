/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:27:59 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/06 15:50:02 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_char(const char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_atoi_print(t_print *print, const char *nptr, int *pos)
{
	int	nbr;

	nbr = 0;
	if (nptr[*pos] == '-' || nptr[*pos] == '+')
	{
		print->flag_error = TRUE;
		return (nbr);
	}
	while (nptr[*pos] > 47 && nptr[*pos] < 58 && nptr[*pos])
	{
		nbr = nbr * 10 + nptr[*pos] - 48;
		(*pos)++;
	}
	return (nbr);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_initialize_print(t_print *print)
{
	print->flag_error = FALSE;
	print->left_justify = FALSE;
	print->zero_padding = FALSE;
	print->explicit_sign = FALSE;
	print->do_pres = FALSE;
	print->hash = FALSE;
	print->width = 0;
	print->precision = 0;
	print->specifier = '0';
}
