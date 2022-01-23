/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:35:28 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/01/23 12:51:23 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

#define		LINE_SEPARATOR "\n-----------------------------------------------------------\n"

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
	ft_printf("%10+-#0 *.*d", 12, 10, 4);
	//ft_printf("\n<%*.*d>\n", 5, 2, 1);
	//ft_printf("*Test %d %d*\n", 5, 5);
	//TestOne();
	//TestTwo();
}
