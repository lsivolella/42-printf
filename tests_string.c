/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:18 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 22:34:03 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	string_test_1(void)
{
	char*	testName;
	char*	str;

	testName = "Test 1 - String variable.\n";
	str = "Lucas";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%s>", str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%s>", str));
}

void	string_test_2(void)
{
	char*	testName;
	char*	str;

	testName = "Test 2 - String variable with text before.\n";
	str = "Lucas";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %s>", str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %s>", str));
}

void	string_test_3(void)
{
	char*	testName;
	char*	str;

	testName = "Test 3 - String variable with text afterwards.\n";
	str = "Lucas";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%s - Test>", str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%s - Test>", str));
}

void	string_test_4(void)
{
	char*	testName;
	char*	str;

	testName = "Test 4 - String variable right-justified width 10 as string.\n";
	str = "Lucas";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%10s>", str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%10s>", str));
}

void	string_test_5(void)
{
	char*	testName;
	char*	str;
	int		width;

	testName = "Test 5 - String variable right-justified width 10 as variable.\n";
	str = "Lucas";
	width = 10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%*s>", width, str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%*s>", width, str));
}

void	string_test_6(void)
{
	char*	testName;
	char*	str;

	testName = "Test 6 - String variable left-justified width 2 as string.\n";
	str = "Lucas";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%-10s>", str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%-10s>", str));
}

void	string_test_7(void)
{
	char*	testName;
	char*	str;
	int		width;

	testName = "Test 7 - String variable left-justified width 10 as variable.\n";
	str = "Lucas";
	width = 10;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%*s>", width, str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%*s>", width, str));
}

void	string_test_8(void)
{
	char*	testName;
	char*	str;

	testName = "Test 8 - String variable left-justified precision 2 as string.\n";
	str = "Lucas";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%.2s>", str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%.2s>", str));
}

void	string_test_9(void)
{
	char*	testName;
	char*	str;
	int		precision;

	testName = "Test 9 - String variable left-justified precision 2 as variable.\n";
	str = "Lucas";
	precision = 2;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%.*s>", precision, str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%.*s>", precision, str));
}

void	string_test_10(void)
{
	char*	testName;
	char*	str;

	testName = "Test 10 - String variable right-justified precision 2 as string.\n";
	str = "Lucas";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%-.2s>", str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%-.2s>", str));
}

void	string_test_11(void)
{
	char*	testName;
	char*	str;
	int		precision;

	testName = "Test 11 - String variable right-justified precision 2 as variable.\n";
	str = "Lucas";
	precision = 2;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%-.*s>", precision, str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%-.*s>", precision, str));
}

void	string_test_12(void)
{
	char*	testName;
	char*	str;

	testName = "Test 12 - String variable left-justified width 10 and precision 2 as string.\n";
	str = "Lucas";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%10.2s>", str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%10.2s>", str));
}

void	string_test_13(void)
{
	char*	testName;
	char*	str;

	testName = "Test 13 - String variable right-justified width 10 and precision 2 as string.\n";
	str = "Lucas";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%-10.2s>", str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%-10.2s>", str));
}

void	string_test_14(void)
{
	char*	testName;
	char*	str;
	int		width;
	int		precision;

	testName = "Test 14 - String variable left-justified width 10 and precision 2 as variable.\n";
	str = "Lucas";
	width = 10;
	precision = 2;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%*.*s>", width, precision, str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%*.*s>", width, precision, str));
}

void	string_test_15(void)
{
	char*	testName;
	char*	str;
	int		width;
	int		precision;

	testName = "Test 15 - String variable right-justified width 10 and precision 2 as string.\n";
	str = "Lucas";
	width = -10;
	precision = 2;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%*.*s>", width, precision, str));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%*.*s>", width, precision, str));
}

void	string_test_16(void)
{
	char*	testName;

	testName = "Test 16 - Null string.\n";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("< %s >", NULL));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("< %s >", "(null)"));
}

void	all_string_tests(void)
{
	string_test_1();
	string_test_2();
	string_test_3();
	string_test_4();
	string_test_5();
	string_test_6();
	string_test_7();
	string_test_8();
	string_test_9();
	string_test_10();
	string_test_11();
	string_test_12();
	string_test_13();
	string_test_14();
	string_test_15();
	string_test_16();
}
