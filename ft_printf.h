/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:32:21 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/01/23 16:21:45 by lgoncalv         ###   ########.fr       */
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
# define SPECIFIERS		"cspdiuxX%"

typedef enum e_bool
{
	true = 1,
	false = 0
}	t_bool;

/*
*	Structs
*
*	.flags[]			contains all flags passed in string;
*	.specifier			the type of variable to be printed (c, s, p, d, i, u, x, X, %);
*	.explicit_sign		can be '-', '+' or anything else if no sign is to be shown;
*	.hash				indicates if hash flag has been passed (0 = no / >0 = yes);
*	.leftJustify		indicates if left justification has been passed (0 = no / >0 = yes);
*	.width				the width of the string to be printed (<0 = not determined);
*	.precision			the precision of the string to be printed (<0 = not determined);
*
*/

typedef struct s_print
{
	char		flags[4];
	t_bool		left_justify;
	t_bool		zero_padding;
	t_bool		hash;
	t_bool		empty_space;
	t_bool		explicit_sign;
	int			precision;
	int			width;
	char		specifier;
}	t_print;

typedef struct s_pos
{
	int			index;
	int			counter;
}	t_pos;

/*
*	From ft_printf.c
*/

void	ft_init_tprint(t_print *print);
void	ft_flag_size(t_print *print, va_list arg, const char *str, t_pos *pos);
void	ft_set_flags(t_print *print, va_list arg, const char *str, t_pos *pos);
int		ft_print_arg(va_list arg, const char *str, t_pos *pos);
int		ft_printf(const char *format, ...);

/*
*	From ft_printf_utils.c
*/

int		ft_find_char(const char *str, char c);
int		ft_atoi(const char *nptr, t_pos *pos);
void	print_struct(t_print print);

#endif