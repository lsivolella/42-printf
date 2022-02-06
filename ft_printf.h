/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:32:21 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/06 17:22:47 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>	// For DMA functions
# include <unistd.h>	// For read & ssize_t
# include <stdarg.h>	// For variadic macros

/*
**	Macros
*/

# define PERCENT		'%'
# define MINUS			'-'
# define ZERO			'0'
# define PRECISION		'.'
# define HASH			'#'
# define SPACE			' '
# define PLUS			'+'
# define STAR			'*'
# define OCTAL			"01234567"
# define DECIMAL		"0123456789"
# define L_HEXA			"0123456789abcdef"
# define U_HEXA			"0123456789ABCDEF"
# define FLAGS			"-0.# +*"
# define ALLFLAGS		"-0.# +*0123456789"
# define SPECS			"cspdiuxX%"
# define MIN_INT		-2147483648
# define MAX_INT		2147483647
# define MAX_U_INT		4294967295

/*
**	Structs 
*/

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_print
{
	t_bool	flag_error;
	t_bool	left_justify;
	t_bool	zero_padding;
	t_bool	hash;
	t_bool	empty_space;
	t_bool	explicit_sign;
	t_bool	do_pres;
	int		width;
	int		precision;
	char	specifier;
}	t_print;

typedef struct s_int
{
	unsigned long long int	value;
	t_bool					positive;
}	t_int;

/*
**	From ft_printf.c
*/

void	ft_flag_size(t_print *print, va_list arg, const char *str, int *pos);
void	ft_precis_flag(t_print *print, va_list arg, const char *str, int *pos);
void	ft_handle_flags(t_print *print, va_list arg, const char *str, int *pos);
int		ft_print_arg(va_list arg, const char *str, int *counter, int *pos);
int		ft_printf(const char *format, ...);

/*
**	From ft_specifiers_1.c
*/

int		ft_specifiers(t_print *print, va_list arg, int *counter);
void	ft_print_padding(t_print *print, int *counter);

/*
**	From ft_specifiers_2.c
*/

int		ft_print_c(t_print *print, int i, int *counter);
int		ft_print_s(t_print *print, char *str, int *counter);
int		ft_print_di(int nbr, int *counter);
int		ft_print_uxX(unsigned int nbr, int *counter, char *base);
int		ft_print_p(unsigned long int nbr, int *counter);

/*
**	From ft_utils_1.c
*/

int		ft_find_char(const char *str, char c);
int		ft_isalpha(int c);
int		ft_atoi_print(t_print *print, const char *nptr, int *pos);
size_t	ft_strlen(const char *s);
void	ft_initialize_print(t_print *print);

/*
**	From ft_utoa.c
*/

char	*ft_utoa(t_int *n, char *base);

#endif