/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_u_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:18 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/06 15:59:42 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	u_integer_test_1(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 1 - Max unsigned integer variable.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%u>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%u>", nbr));
}

void	u_integer_test_2(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 2 - Max unsigned integer variable with text before.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %u>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %u>", nbr));
}

void	u_integer_test_3(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 3 - Max unsigned integer variable with text afterwards.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%u - Test>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%u - Test>", nbr));
}

void	u_integer_test_4(void)
{
	char*	testName;
	long	nbr1;

	testName = "Test 4 - Overflow: Max unsigned integer variable value + 1.\n";
	nbr1 = MAX_U_INT + 1;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%u>", nbr1));
	printf("\nReturn Size: %d\n", ft_printf("<%u>", nbr1));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%u>", nbr1));
}

void	u_integer_test_5(void)
{
	char*	testName;
	long	nbr1;

	testName = "Test 5 - Overflow: Min unsigned integer variable value - 1.\n";
	nbr1 = -1;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%u>", nbr1));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%u>", nbr1));
}


void	all_u_integer_tests(void)
{
	u_integer_test_1();
	u_integer_test_2();
	u_integer_test_3();
	u_integer_test_4();
	u_integer_test_5();
	// u_integer_test_6();
	// u_integer_test_7();
	// u_integer_test_8();
	// u_integer_test_9();
	// u_integer_test_10();
	// u_integer_test_11();
	// u_integer_test_12();
	// u_integer_test_13();
	// u_integer_test_14();
	// u_integer_test_15();
	// u_integer_test_16();
}
