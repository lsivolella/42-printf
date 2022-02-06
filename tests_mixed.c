/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_mixed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:14:14 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 22:33:41 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	mixed_test_1(void)
{
	char*	testName;
	char	c;
	char	*str;
	int		nbr;

	testName = "Test 1 - Char, String, Decimal and Integer as variables.\n";
	c = 'A';
	str = "42";
	nbr = 42;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("%%%c%%%s%%%d%%%i", c, str, nbr, nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("%%%c%%%s%%%d%%%i", c, str, nbr, nbr));
}

void	all_mixed_tests(void)
{
	mixed_test_1();
}