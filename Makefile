# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:20:21 by dmontema          #+#    #+#              #
#    Updated: 2022/04/25 16:42:57 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

INCS	=	-I./inc

SRC_DIR		=	./src
SRCS		= 	$(SRC_DIR)/main.c \
				$(SRC_DIR)/data.c \
				$(SRC_DIR)/parser.c \
				$(SRC_DIR)/ft_atoi.c \
				$(SRC_DIR)/time.c \
				$(SRC_DIR)/activity.c \
				$(SRC_DIR)/philo_checker.c \
				$(SRC_DIR)/philo_eat.c \
				$(SRC_DIR)/philo_sleep.c

OBJ_DIR		= 	obj
OBJS		=	$(SRCS:.c=.o) # $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=address

# COLOURS
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
RESET	=	\033[m

# **************************************************************************** #
#	RULES																	   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Installing philosophers...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread
	@echo "$(GREEN)\tCOMPLETE!$(RESET)"

.c.o:
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(OBJS)
	@echo "$(GREEN)Cleaning done.$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) | grep --color=always 'Error!\|Error:' || echo "$(GREEN)Everything is OK!$(RESET)" >&1

