/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:18 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 22:56:47 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	integer_test_1(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 1 - Positive integer variable.\n";
	nbr = 10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%i>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%i>", nbr));
}

void	integer_test_2(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 2 - Negative integer variable.\n";
	nbr = -10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%i>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%i>", nbr));
}

void	integer_test_3(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 3 - Positive integer variable with text before.\n";
	nbr = 10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %i>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %i>", nbr));
}

void	integer_test_4(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 4 - Positive integer variable with text afterwards.\n";
	nbr = 10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%i - Test>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%i - Test>", nbr));
}

void	integer_test_5(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 5 - Negative integer variable with text before.\n";
	nbr = -10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %i>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %i>", nbr));
}

void	integer_test_6(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 6 - Negative integer variable with text afterwards.\n";
	nbr = -10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%i - Test>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%i - Test>", nbr));
}

void	integer_test_7(void)
{
	char*	testName;
	int		nbr1;
	int		nbr2;

	testName = "Test 7 - Min and Max integer variable values.\n";
	nbr1 = MIN_INT;
	nbr2 = MAX_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%i && %i>", nbr1, nbr2));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%i && %i>", nbr1, nbr2));
}

void	integer_test_8(void)
{
	char*	testName;
	long	nbr1;

	testName = "Test 8 - Overflow: Max integer variable value + 1.\n";
	nbr1 = MAX_INT + 1;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%i>", nbr1));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%i>", nbr1));
}

void	integer_test_9(void)
{
	char*	testName;
	long	nbr1;

	testName = "Test 8 - Overflow: Min integer variable value - 1.\n";
	nbr1 = MIN_INT - 1;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%i>", nbr1));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%i>", nbr1));
}

void	all_integer_tests(void)
{
	integer_test_1();
	integer_test_2();
	integer_test_3();
	integer_test_4();
	integer_test_5();
	integer_test_6();
	integer_test_7();
	integer_test_8();
	integer_test_9();
	// integer_test_10();
	// integer_test_11();
	// integer_test_12();
	// integer_test_13();
	// integer_test_14();
	// integer_test_15();
	// integer_test_16();
}
