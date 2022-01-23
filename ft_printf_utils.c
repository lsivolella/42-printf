/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:27:59 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/01/23 12:45:57 by lgoncalv         ###   ########.fr       */
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

int	ft_atoi(const char *nptr, int *pos)
{
	int	nbr;

	nbr = 0;
	while (nptr[*pos] > 47 && nptr[*pos] < 58 && nptr[*pos])
	{
		nbr = nbr * 10 + nptr[*pos] - 48;
		(*pos)++;
	}
	return (nbr);
}

void	print_struct(t_print print)
{
	printf("\n");
	if (print.left_justify)
		printf("print.left_justify = true\n");
	else
		printf("print.left_justify = false\n");
		
	if (print.zero_padding)
		printf("print.zero_padding = true\n");
	else
		printf("print.zero_padding = false\n");
		
	if (print.hash)
		printf("print.hash = true\n");
	else
		printf("print.hash = false\n");
		
	if (print.empty_space)
		printf("print.empty_space = true\n");
	else
		printf("print.empty_space = false\n");
		
	if (print.explicit_sign)
		printf("print.explicit_sign = true\n");
	else
		printf("print.explicit_sign = false\n");

	printf("print.precision = %d\n", print.precision);

	printf("print.width = %d\n", print.width);

	printf("print.specifier = %c\n", print.specifier);
}
