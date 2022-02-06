/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:18 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 22:56:31 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	decimal_test_1(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 1 - Positive decimal variable.\n";
	nbr = 10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%d>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%d>", nbr));
}

void	decimal_test_2(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 2 - Negative decimal variable.\n";
	nbr = -10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%d>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%d>", nbr));
}

void	decimal_test_3(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 3 - Positive decimal variable with text before.\n";
	nbr = 10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %d>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %d>", nbr));
}

void	decimal_test_4(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 4 - Positive decimal variable with text afterwards.\n";
	nbr = 10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%d - Test>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%d - Test>", nbr));
}

void	decimal_test_5(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 5 - Negative decimal variable with text before.\n";
	nbr = -10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %d>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %d>", nbr));
}

void	decimal_test_6(void)
{
	char*	testName;
	int		nbr;

	testName = "Test 6 - Negative decimal variable with text afterwards.\n";
	nbr = -10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%d - Test>", nbr));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%d - Test>", nbr));
}

void	decimal_test_7(void)
{
	char*	testName;
	int		nbr1;
	int		nbr2;

	testName = "Test 7 - Min and Max decimal variable values.\n";
	nbr1 = MIN_INT;
	nbr2 = MAX_INT;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%d && %d>", nbr1, nbr2));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%d && %d>", nbr1, nbr2));
}

void	decimal_test_8(void)
{
	char*	testName;
	long	nbr1;

	testName = "Test 8 - Overflow: Max decimal variable value + 1.\n";
	nbr1 = MAX_INT + 1;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%d>", nbr1));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%d>", nbr1));
}

void	decimal_test_9(void)
{
	char*	testName;
	long	nbr1;

	testName = "Test 9 - Overflow: Min decimal variable value - 1.\n";
	nbr1 = MIN_INT - 1;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%d>", nbr1));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%d>", nbr1));
}

// void	decimal_test_4(void)
// {
// 	char*	testName;
// 	char*	str;

// 	testName = "Test 4 - String variable right-justified width 10 as string.\n";
// 	str = "Lucas";
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%10s>", str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%10s>", str));
// }

// void	decimal_test_5(void)
// {
// 	char*	testName;
// 	char*	str;
// 	int		width;

// 	testName = "Test 5 - String variable right-justified width 10 as variable.\n";
// 	str = "Lucas";
// 	width = 10;
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%*s>", width, str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%*s>", width, str));
// }

// void	decimal_test_6(void)
// {
// 	char*	testName;
// 	char*	str;

// 	testName = "Test 6 - String variable left-justified width 2 as string.\n";
// 	str = "Lucas";
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%-10s>", str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%-10s>", str));
// }

// void	decimal_test_7(void)
// {
// 	char*	testName;
// 	char*	str;
// 	int		width;

// 	testName = "Test 7 - String variable left-justified width 10 as variable.\n";
// 	str = "Lucas";
// 	width = 10;
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%*s>", width, str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%*s>", width, str));
// }

// void	decimal_test_8(void)
// {
// 	char*	testName;
// 	char*	str;

// 	testName = "Test 8 - String variable left-justified precision 2 as string.\n";
// 	str = "Lucas";
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%.2s>", str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%.2s>", str));
// }

// void	decimal_test_9(void)
// {
// 	char*	testName;
// 	char*	str;
// 	int		precision;

// 	testName = "Test 9 - String variable left-justified precision 2 as variable.\n";
// 	str = "Lucas";
// 	precision = 2;
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%.*s>", precision, str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%.*s>", precision, str));
// }

// void	decimal_test_10(void)
// {
// 	char*	testName;
// 	char*	str;

// 	testName = "Test 10 - String variable right-justified precision 2 as string.\n";
// 	str = "Lucas";
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%-.2s>", str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%-.2s>", str));
// }

// void	decimal_test_11(void)
// {
// 	char*	testName;
// 	char*	str;
// 	int		precision;

// 	testName = "Test 11 - String variable right-justified precision 2 as variable.\n";
// 	str = "Lucas";
// 	precision = 2;
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%-.*s>", precision, str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%-.*s>", precision, str));
// }

// void	decimal_test_12(void)
// {
// 	char*	testName;
// 	char*	str;

// 	testName = "Test 12 - String variable left-justified width 10 and precision 2 as string.\n";
// 	str = "Lucas";
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%10.2s>", str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%10.2s>", str));
// }

// void	decimal_test_13(void)
// {
// 	char*	testName;
// 	char*	str;

// 	testName = "Test 13 - String variable right-justified width 10 and precision 2 as string.\n";
// 	str = "Lucas";
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%-10.2s>", str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%-10.2s>", str));
// }

// void	decimal_test_14(void)
// {
// 	char*	testName;
// 	char*	str;
// 	int		width;
// 	int		precision;

// 	testName = "Test 14 - String variable left-justified width 10 and precision 2 as variable.\n";
// 	str = "Lucas";
// 	width = 10;
// 	precision = 2;
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%*.*s>", width, precision, str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%*.*s>", width, precision, str));
// }

// void	decimal_test_15(void)
// {
// 	char*	testName;
// 	char*	str;
// 	int		width;
// 	int		precision;

// 	testName = "Test 15 - String variable right-justified width 10 and precision 2 as string.\n";
// 	str = "Lucas";
// 	width = -10;
// 	precision = 2;
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("<%*.*s>", width, precision, str));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("<%*.*s>", width, precision, str));
// }

// void	decimal_test_16(void)
// {
// 	char*	testName;

// 	testName = "Test 16 - Null string.\n";
// 	printf("%s", LINE_SEPARATOR);
// 	printf("%s", testName);
// 	printf("\n-> FT Behavior\n");
// 	printf("\nReturn Size: %d\n", ft_printf("< %s >", NULL));
// 	printf("\n-> Original Behavior\n");
// 	printf("\nReturn Size: %d\n", printf("< %s >", "(null)"));
// }

void	all_decimal_tests(void)
{
	decimal_test_1();
	decimal_test_2();
	decimal_test_3();
	decimal_test_4();
	decimal_test_5();
	decimal_test_6();
	decimal_test_7();
	decimal_test_8();
	decimal_test_9();
	// decimal_test_10();
	// decimal_test_11();
	// decimal_test_12();
	// decimal_test_13();
	// decimal_test_14();
	// decimal_test_15();
	// decimal_test_16();
}
