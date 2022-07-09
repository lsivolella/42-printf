# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 15:48:42 by lgoncalv          #+#    #+#              #
#    Updated: 2022/07/09 12:17:51 by lgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER
CC				= gcc

# FLAGS
CFLAGS			= -Wall -Wextra -Werror
INCLUDES		= -I $(INCLUDES_PATH)

# PATHS
INCLUDES_PATH	= ./includes
SRCS_PATH		= ./sources
OBJS_PATH		= ./objects

# COMMANDS
RM				= /bin/rm -f

# NAMES
NAME			= libftprintf.a
INTRO			= LIBFTPRINTF

# SOURCES
SRCS			= ft_printf.c\
				ft_specifiers_1.c\
				ft_specifiers_2.c\
				ft_utils_1.c\
				ft_utoa.c\

SRCS			:= $(addprefix $(SRCS_PATH)/,$(SRCS))

# OBJECTS
OBJS			= $(subst $(SRCS_PATH),$(OBJS_PATH),$(SRCS:%.c=%.o))

# PATTERN RULE
$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar -rsc $(NAME) $(OBJS)
	@echo "[$(INTRO)] Library [$(NAME)] created!"

clean:
	@$(RM) $(OBJS)
	@echo "[$(INTRO)] Objects removed!"

fclean:	clean
	@$(RM) $(NAME)
	@echo "[$(INTRO)] Library [$(NAME)] removed!"

re:	fclean all

.PHONY: all clean fclean re