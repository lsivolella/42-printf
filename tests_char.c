/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:18 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 22:33:05 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	char_test_1(void)
{
	char*	testName;
	char	c;

	testName = "Test 1 - Char variable.\n";
	c = 'a';
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%c>", c));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%c>", c));
}

void	char_test_2(void)
{
	char*	testName;
	char	c;

	testName = "Test 2 - Char variable with text before.\n";
	c = 'a';
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<Test: %c>", c));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<Test: %c>", c));
}

void	char_test_3(void)
{
	char*	testName;
	char	c;

	testName = "Test 3 - Char variable with text afterwards.\n";
	c = 'a';
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%c - Test>", c));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%c - Test>", c));
}

void	char_test_4(void)
{
	char*	testName;
	char	c;

	testName = "Test 4 - Char variable right-justified width 2 as string.\n";
	c = 'a';
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%2c>", c));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%2c>", c));
}

void	char_test_5(void)
{
	char*	testName;
	char	c;
	int		width;

	testName = "Test 5 - Char variable right-justified width 2 as variable.\n";
	c = 'a';
	width = 2;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%*c>", width, c));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%*c>", width, c));
}

void	char_test_6(void)
{
	char*	testName;
	char	c;

	testName = "Test 6 - Char variable left-justified width 2 as string.\n";
	c = 'a';
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%-2c>", c));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%-2c>", c));
}

void	char_test_7(void)
{
	char*	testName;
	char	c;
	int		width;

	testName = "Test 7 - Char variable left-justified width 2 as variable.\n";
	c = 'a';
	width = 2;
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	printf("\nReturn Size: %d\n", ft_printf("<%-*c>", width, c));
	printf("\n-> Original Behavior\n");
	printf("\nReturn Size: %d\n", printf("<%-*c>", width, c));
}

void	all_char_tests(void)
{
	char_test_1();
	char_test_2();
	char_test_3();
	char_test_4();
	char_test_5();
	char_test_6();
	char_test_7();
}
