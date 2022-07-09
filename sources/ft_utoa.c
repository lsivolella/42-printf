/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:57:11 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/07/09 12:40:38 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_get_size(unsigned long long int n, int b_length)
{
	unsigned long long int	num;
	size_t					size;

	num = n;
	size = 1;
	while (num)
	{
		num /= b_length;
		size++;
	}
	return (size);
}

char	*ft_utoa(t_int *n, char *base)
{
	unsigned long long int	num;
	char					*nbr;
	size_t					size;
	int						b_length;

	num = n->value;
	b_length = ftp_strlen(base);
	size = ft_get_size(num, b_length);
	nbr = (char *)malloc((size + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[size--] = '\0';
	while (num > 0)
	{
		nbr[size--] = base[num % b_length];
		num /= b_length;
	}
	if (size == 0 && nbr[1] == '\0')
		nbr[0] = '0';
	return (nbr);
}
