/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:45:41 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 12:11:33 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifiers(t_print *print, va_list arg, int *counter)
{
	// need to ignore non-required specifiers and jump arg
	// ex: alguem enviou um double 'f' para imprimir. Devo ignora-lo e seguir com o programa
	if (print->specifier == 's')
		printf("Test");

	// próximo passo: printar uma string com todas as opções de formatação
}