/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:18 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/06 16:04:33 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	hexa_test_1(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 1 - Low hexa variable.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%x>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%x>", nbr));
}

void	hexa_test_2(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 2 - High hexa variable.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%X>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%X>", nbr));
}

void	hexa_test_3(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 3 - Low hexa variable with text before.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %x>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %x>", nbr));
}

void	hexa_test_4(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 4 - High hexa variable with text before.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %X>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %X>", nbr));
}

void	hexa_test_5(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 5 - Low hexa variable with text afterwards.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%x - Test>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%x - Test>", nbr));
}

void	hexa_test_6(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 6 - High hexa variable with text afterwards.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%X - Test>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%X - Test>", nbr));
}

void	hexa_test_7(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 7 - Low hexa negative variable.\n";
	nbr = -957;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%x - Test>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%x - Test>", nbr));
}

void	hexa_test_8(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 8 - High hexa negative variable.\n";
	nbr = -957;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%x - Test>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%x - Test>", nbr));
}

void	all_hexa_tests(void)
{
	hexa_test_1();
	hexa_test_2();
	hexa_test_3();
	hexa_test_4();
	hexa_test_5();
	hexa_test_6();
	hexa_test_7();
	hexa_test_8();
	// hexa_test_9();
	// hexa_test_10();
	// hexa_test_11();
	// hexa_test_12();
	// hexa_test_13();
	// hexa_test_14();
	// hexa_test_15();
	// hexa_test_16();
}
