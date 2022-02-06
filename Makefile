# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 15:48:42 by lgoncalv          #+#    #+#              #
#    Updated: 2022/02/06 16:22:16 by lgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= /bin/rm -f
RMRUN		= rm -f											# DELETE BEFORE DELIVERY

NAME		= libftprintf.a

SRCSMAIN	= main.c \
			tests_percentage.c \
			tests_char.c \
			tests_string.c \
			tests_decimal.c \
			tests_integer.c \
			tests_u_integer.c \
			tests_hexa.c \
			tests_pointer.c \
			tests_mixed.c				# DELETE BEFORE DELIVERY

SRCS		= ft_printf.c \
			ft_utils_1.c \
			ft_utils_2.c \
			ft_utoa.c \
			ft_specifiers.c

OBJS		= $(SRCS:.c=.o)

.c.o:
			@$(CC) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

bonus:		all

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

run:														# DELETE BEFORE DELIVERY
			@$(CC) $(SRCSMAIN) $(SRCS) && ./a.out

crun:													# DELETE BEFORE DELIVERY
			@clear && $(CC) $(SRCSMAIN) $(SRCS) && ./a.out && $(RMRUN) *.out