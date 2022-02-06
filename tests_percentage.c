/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:18 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 22:33:50 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	percent_test_1(void)
{
	char*	testName;

	testName = "Test 1 - Simple percentage.\n";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%%>"));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%%>"));
}

void	percent_test_2(void)
{
	char*	testName;

	testName = "Test 2 - Percentage with text before.\n";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %%>"));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %%>"));
}

void	percent_test_3(void)
{
	char*	testName;

	testName = "Test 3 - Percentage with text after.\n";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%% - Tested>"));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%% - Tested>"));
}

void	all_percent_tests(void)
{
	percent_test_1();
	percent_test_2();
	percent_test_3();
}
