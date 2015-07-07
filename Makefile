# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 05:48:46 by nsavry            #+#    #+#              #
#    Updated: 2014/04/27 17:52:39 by nsavry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FTC = ft_main.c\
	  ft_current.c\
	  ft_event.c\
	  ft_draw_line.c\
	  ft_realloc.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@Make -C ./libft
	@printf '\033[1;33;40m'
	@echo "[libft]\c"
	@printf '\033[0m'
	@printf '\033[1;32;40m'
	@echo "[ok]"
	@printf '\033[0m'
	@gcc -o $(NAME) -L./libft -lft -L/usr/X11/lib -lmlx -lXext -lX11 $(FTO)
	@printf '\033[1;33;40m'
	@echo "[$(NAME)]\c"
	@printf '\033[0m'
	@printf '\033[1;32;40m'
	@echo "[ok]"
	@printf '\033[0m'

%.o: %.c
	@clear
	@printf '\033[1;31;40m'
	@echo "## - Makefile - ##"
	@printf '\033[0m'
	@printf '\033[1;37;40m'
	@echo "Creating library libft and compile $(NAME)"
	@printf '\033[0m'
	@gcc -Wall -Werror -Wextra -I./ -I./libft/includes -c $<
	@printf '\033[1;33;40m'
	@echo "[c file]\c"
	@printf '\033[0m'
	@printf '\033[1;32;40m'
	@echo "[ok]"
	@printf '\033[0m'

clean:
	@make -C ./libft clean
	@rm -rf $(FTO)

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
