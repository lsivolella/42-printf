/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:32:21 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/02/05 22:40:47 by lgoncalv         ###   ########.fr       */
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
# define SPECS			"cspdiuxX%onfge"
# define M_SPECS		"cspdiuxX%"
# define MIN_INT		-2147483648
# define MAX_INT		2147483647
# define MAX_U_INT		4294967295
# define LINE_SEPARATOR "\n-----------------------------------------------------------\n"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

// enum e_bool
// {
// 	FALSE,
// 	TRUE
// };
// typedef enum e_bool t_bool;

// enum e_bool
// {
// 	false = 0,
// 	true = 1
// };
// typedef enum e_bool t_bool;

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
	t_bool	flag_error;
	t_bool	left_justify;
	t_bool	zero_padding;
	t_bool	hash;
	t_bool	empty_space;
	t_bool	explicit_sign;
	t_bool	do_pres;
	t_bool	do_wid;
	int		width;
	int		precision;
	char	specifier;
}	t_print;

/*
*	From ft_printf.c
*/

void	ft_flag_size(t_print *print, va_list arg, const char *str, int *pos);
void	ft_precis_flag(t_print *print, va_list arg, const char *str, int *pos);
void	ft_handle_flags(t_print *print, va_list arg, const char *str, int *pos);
int		ft_print_arg(va_list arg, const char *str, int *counter, int *pos);
int		ft_printf(const char *format, ...);

/*
*	From ft_specifiers.c
*/

int		ft_specifiers(t_print *print, va_list arg, int *counter);
void	ft_print_padding(t_print *print, int *counter);
int		ft_print_char(t_print *print, int i, int *counter);
int		ft_print_string(t_print *print, char *str, int *counter);
int		ft_print_integer(t_print *print, int nbr, int *counter);
int		ft_print_u_integer(t_print *print, unsigned int nbr, int *counter);

/*
*	From ft_utils_1.c
*/

int		ft_find_char(const char *str, char c);
int		ft_isalpha(int c);
int		ft_atoi_print(t_print *print, const char *nptr, int *pos);
size_t	ft_strlen(const char *s);
void	ft_initialize_print(t_print *print);

/*
*	From ft_utils_2.c
*/

void	print_struct(t_print print);

/*
*	From ft_itoa.c
*/

char	*ft_itoa(int n);

/*
*	From ft_utoa.c
*/

char	*ft_utoa(unsigned int n);

/*
*	From tests
*/

void	all_percent_tests(void);
void	percent_test_1(void);
void	percent_test_2(void);
void	percent_test_3(void);

void	all_char_tests(void);
void	char_test_1(void);
void	char_test_2(void);
void	char_test_3(void);
void	char_test_4(void);
void	char_test_5(void);
void	char_test_6(void);
void	char_test_7(void);

void	all_string_tests(void);
void	string_test_1(void);
void	string_test_2(void);
void	string_test_3(void);
void	string_test_4(void);
void	string_test_5(void);
void	string_test_6(void);
void	string_test_7(void);
void	string_test_8(void);
void	string_test_9(void);
void	string_test_10(void);
void	string_test_11(void);
void	string_test_12(void);
void	string_test_13(void);
void	string_test_14(void);
void	string_test_15(void);
void	string_test_16(void);

void	all_decimal_tests(void);
void	decimal_test_1(void);
void	decimal_test_2(void);
void	decimal_test_3(void);
void	decimal_test_4(void);
void	decimal_test_5(void);
void	decimal_test_6(void);
void	decimal_test_7(void);
void	decimal_test_8(void);
void	decimal_test_9(void);
void	decimal_test_10(void);
void	decimal_test_11(void);
void	decimal_test_12(void);
void	decimal_test_13(void);
void	decimal_test_14(void);
void	decimal_test_15(void);
void	decimal_test_16(void);

void	all_integer_tests(void);
void	integer_test_1(void);
void	integer_test_2(void);
void	integer_test_3(void);
void	integer_test_4(void);
void	integer_test_5(void);
void	integer_test_6(void);
void	integer_test_7(void);
void	integer_test_8(void);
void	integer_test_9(void);
void	integer_test_10(void);
void	integer_test_11(void);
void	integer_test_12(void);
void	integer_test_13(void);
void	integer_test_14(void);
void	integer_test_15(void);
void	integer_test_16(void);

void	all_u_integer_tests(void);
void	u_integer_test_1(void);
void	u_integer_test_2(void);
void	u_integer_test_3(void);
void	u_integer_test_4(void);
void	u_integer_test_5(void);
void	u_integer_test_6(void);
void	u_integer_test_7(void);
void	u_integer_test_8(void);
void	u_integer_test_9(void);
void	u_integer_test_10(void);
void	u_integer_test_11(void);
void	u_integer_test_12(void);
void	u_integer_test_13(void);
void	u_integer_test_14(void);
void	u_integer_test_15(void);
void	u_integer_test_16(void);

void	all_mixed_tests(void);
void	mixed_test_1(void);
#endif