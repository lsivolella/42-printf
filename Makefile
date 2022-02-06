# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 15:48:42 by lgoncalv          #+#    #+#              #
#    Updated: 2022/02/06 17:27:58 by lgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= /bin/rm -f

NAME		= libftprintf.a

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
