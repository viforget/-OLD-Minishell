# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viforget <viforget@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/05 10:48:32 by viforget          #+#    #+#              #
#    Updated: 2019/10/06 14:19:28 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS += -Werror -Wall -Wextra -I includes
LIBDIR = libft

SRC = minishell.c putpromp.c env.c command.c

O_FILES = $(SRC:%.c=%.o)
	FLAGLIB = -L$(LIBDIR) -lft

all: $(NAME)

$(NAME): $(O_FILES)
		@make all -C $(LIBDIR)
		@gcc $(CFLAGS) $(FLAGLIB) -o $(NAME) $(O_FILES)
		@printf "\r\033[32mCOMPILATION MINISHELL OK\033[0m\n"
clean:
		@/bin/rm -rf $(O_FILES)
		@make clean -C $(LIBDIR)
		@printf "\r\033[32mCLEAN MINISHELL OK\033[0m\n"

fclean: clean
		@/bin/rm -rf $(NAME)
		@make fclean -C $(LIBDIR)
		@printf "\r\033[32mFCLEAN MINISHELL OK\033[0m\n"

lib:
		@make re -C $(LIBDIR)

norm:
		@norminette $(SRC)

normlib:
		@norminette $(LIBDIR)/*.c

re: fclean all

.PHONY: all fclean clean re lib norm normlib
