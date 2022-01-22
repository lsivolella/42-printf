# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 15:48:42 by lgoncalv          #+#    #+#              #
#    Updated: 2022/01/22 16:21:06 by lgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= /bin/rm -f
RMRUN		= rm -f											# DELETE BEFORE DELIVERY

NAME		= libftprintf.a

SRCSMAIN	= main.c ft_printf.c							# DELETE BEFORE DELIVERY

SRCS		= ft_printf.c

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
			@$(CC) $(SRCSMAIN) && ./a.out && $(RMRUN) *.out