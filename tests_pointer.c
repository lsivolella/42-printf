/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:18 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/06 16:26:30 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	pointer_test_1(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 1 - Pointer variable.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%p>", &nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%p>", &nbr));
}

void	pointer_test_2(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 2 - Non pointer variable.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%p>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%p>", nbr));
}

void	pointer_test_3(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 3 - Pointer variable with text before.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %p>", &nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %p>", &nbr));
}

void	pointer_test_4(void)
{
	char*			testName;
	unsigned int	nbr;

	testName = "Test 4 - Pointer variable with text afterwards.\n";
	nbr = MAX_U_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%p - Test>", &nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%p - Test>", &nbr));
}

void	pointer_test_5(void)
{
	char*	testName;

	testName = "Test 7 - Null pointer address variable.\n";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%p>", 0));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%p>", 0));
}

void	all_pointer_tests(void)
{
	pointer_test_1();
	pointer_test_2();
	pointer_test_3();
	pointer_test_4();
	pointer_test_5();
	// pointer_test_6();
	// pointer_test_7();
	// pointer_test_8();
	// pointer_test_9();
	// pointer_test_10();
	// pointer_test_11();
	// pointer_test_12();
	// pointer_test_13();
	// pointer_test_14();
	// pointer_test_15();
	// pointer_test_16();
}
