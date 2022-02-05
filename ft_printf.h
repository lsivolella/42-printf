/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:32:21 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 12:59:23 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>		// Used for debugging -> DELETE BEFORE DELIVERY
# include <stdlib.h>	// For DMA functions
# include <unistd.h>	// For read & ssize_t
# include <stdarg.h>	// For variadic macros

/*
*	Macros
*/

# define PERCENT		'%'
# define MINUS			'-'
# define ZERO			'0'
# define PRECISION		'.'
# define HASH			'#'
# define SPACE			' '
# define PLUS			'+'
# define STAR			'*'
# define DECIMAL		"0123456789"
# define LOWHEXA		"0123456789abcdef"
# define UPPERHEXA		"0123456789ABCDEF"
# define FLAGS			"-0.# +*"
# define ALLFLAGS		"-0.# +*0123456789"
# define SPECIFIERS		"cspdiuxX%onfge"
# define M_SPECIFIERS	"cspdiuxX%"

typedef enum e_bool
{
	true = 1,
	false = 0
}	t_bool;

/*
*	Structs
*
*	.error				indicates if an error was found in the flags formatting
*	.leftJustify		indicates if left justification has been passed (0 = no / >0 = yes);
*	.zero_padding		;
*	.hash				indicates if hash flag has been passed (0 = no / >0 = yes);
*	.empty_space		;
*	.explicit_sign		can be '-', '+' or anything else if no sign is to be shown;
*	.width				the width of the string to be printed (<0 = not determined);
*	.precision			the precision of the string to be printed (<0 = not determined);
*	.specifier			the type of variable to be printed (c, s, p, d, i, u, x, X, %);
*/

typedef struct s_print
{
	t_bool		flag_error;
	t_bool		left_justify;
	t_bool		zero_padding;
	t_bool		hash;
	t_bool		empty_space;
	t_bool		explicit_sign;
	int			width;
	int			precision;
	char		specifier;
	
}	t_print;

/*
*	From ft_printf.c
*/

void	ft_initialize_print(t_print *print);
void	ft_get_flag_size(t_print *print, va_list arg, const char *str, int *pos);
void	ft_handle_flags(t_print *print, va_list arg, const char *str, int *pos);
void	ft_treat_width(t_print *print);
int		ft_print_arg(va_list arg, const char *str, int *counter, int *pos);
int		ft_printf(const char *format, ...);

/*
*	From ft_utils.c
*/

int		ft_find_char(const char *str, char c);
int		ft_isalpha(int c);
int		ft_atoi_print(t_print *print, const char *nptr, int *pos);
void	print_struct(t_print print);

/*
*	From ft_print_s.c
*/

void	ft_specifiers(t_print *print, va_list arg, int *counter);

#endif