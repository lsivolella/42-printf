/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:35:28 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 23:01:36 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void TestOne()
{
	char*	testName;
	int		result;

	testName = "Test 1 - Simple string, no arguments.\n";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	result = ft_printf("*Test*");
	printf("\nReturn Size: %d\n", result);
	printf("\n-> Original Behavior\n");
	result = printf("*Test*");
	printf("\nReturn Size: %d\n", result);
}

void TestTwo()
{
	char*	testName;
	char*	string;
	int		result;

	testName = "Test 2 - One string as argument.\n";
	string = "Hello World";
	printf("%s", LINE_SEPARATOR);
	printf("%s", testName);
	printf("\n-> FT Behavior\n");
	result = ft_printf("*%s*", string);
	printf("\nReturn Size: %d\n", result);
	printf("\n-> Original Behavior\n");
	result = printf("*%s*", string);
	printf("\nReturn Size: %d\n", result);
}

// #0- +

int main(void)
{
	// all_percent_tests();
	// all_char_tests();
	// all_string_tests();
	// all_decimal_tests();
	// all_integer_tests();
	all_u_integer_tests();
	// all_mixed_tests();

	// char *string;
	// int width;
	// int precision;

	// string = "Test";
	// width = -10;
	// precision = 3;
	//printf("<%*.*s>\n", width, precision, string);
	//ft_printf("<%*.*s>\n", width, precision, string);
	


	// printf("<%2c>\n", 'a');
	// printf("<%-2c>\n", 'a');
	// ft_printf("<%-2c>\n", 'a');
	
	// to test during flag captures:
	// precision:
	// negative precision value as argument -> flag formatting error! (done!)
	// positive explicit precision value as argument -> flag formatting error! (done!)
	// 0 precision value as argument -> means no precision
	// 									(rounds value to next integer - should I worry?) (done!)
	// null precision value as argument -> means no precision
	// 									(rounds value to next integer - should I worry?)
	
	// negative precision value as parameter -> invalidates precision parameter! (done!)
	// positive precision value as parameter -> ignores + char (done!)
	// 0 precision value as parameter -> means no precision (done!)
	// null precision value as parameter -> not possible with compiler flags (done!)
	
	// width:
	// negative width value as argument -> means left-justify (done!)
	// positive width value as argument -> means explicit_sign (done!)
	// 0 width value as argument -> the 0 argument alone means use zero_padding, 
	// 								and combined with a > 0 value to the right means
	// 								zero_padding + width (done!)
	// null width value as argument -> means no minimum width (done!)
	
	// negative width value as parameter -> means left-justify (done!)
	// positive width value as parameter -> no special meaning (done!)
	// 0 width value as parameter -> means no minimum width
	// null width value as parameter -> not possible with compiler flags (done!)


	// ft_printf("Test 1: %c\n", 'c');
	// ft_printf("Test 2: %s\n", "string");
	// ft_printf("Test 3: %d\n", 1);
	// ft_printf("Test 4: %u\n", 1);
	// ft_printf("Test 5: %x\n", 1);
	// ft_printf("Test 6: %X\n", 1);
	// ft_printf("Test 7: %p\n", 1);
	// ft_printf("Test 8: %i\n", 1);
	//ft_printf("%10+-#0 *.*d", 12, 10, 4);
	//ft_printf("\n<%*.*d>\n", 5, 2, 1);
	//ft_printf("*Test %d %d*\n", 5, 5);
	//TestOne();
	//TestTwo();
}
