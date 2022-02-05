# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 15:48:42 by lgoncalv          #+#    #+#              #
#    Updated: 2022/01/31 20:46:01 by lgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= /bin/rm -f
RMRUN		= rm -f											# DELETE BEFORE DELIVERY

NAME		= libftprintf.a

SRCSMAIN	= main.c										# DELETE BEFORE DELIVERY

SRCS		= ft_printf.c ft_utils.c ft_print_s.c

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