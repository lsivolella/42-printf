// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_itoa.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/02/05 20:57:11 by lgoncalv          #+#    #+#             */
// /*   Updated: 2022/02/05 20:57:35 by lgoncalv         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_printf.h"

// static size_t	ft_get_size(long n)
// {
// 	size_t	size;

// 	size = 0;
// 	if (n == 0)
// 		size++;
// 	else if (n < 0)
// 	{
// 		size++;
// 		n *= -1;
// 	}
// 	while (n > 0)
// 	{
// 		size++;
// 		n /= 10;
// 	}
// 	return (size);
// }

// static int	ft_recursive_power(long nbr, int power)
// {
// 	while (power > 0)
// 		return (nbr * ft_recursive_power(nbr, power - 1));
// 	if (power == 0)
// 		return (1);
// 	else if (power < 0)
// 		return (0);
// 	return (nbr);
// }

// char	*ft_itoa(int n)
// {
// 	char	*nbr;
// 	long	num;
// 	size_t	size;
// 	size_t	i;

// 	i = 0;
// 	num = n;
// 	size = ft_get_size(num);
// 	nbr = (char *)malloc((size + 1) * sizeof(char));
// 	if (!nbr)
// 		return (NULL);
// 	if (num < 0)
// 	{
// 		nbr[i++] = '-';
// 		num *= -1;
// 		size--;
// 	}
// 	while (size > 0)
// 	{
// 		nbr[i++] = (num / ft_recursive_power(10, --size)) + 48;
// 		num -= num / ft_recursive_power(10, size) * \
// 			ft_recursive_power(10, size);
// 	}
// 	nbr[i] = '\0';
// 	return (nbr);
// }
