# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emajuri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:39:22 by emajuri           #+#    #+#              #
#    Updated: 2023/04/04 15:16:04 by emajuri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft.a

SRC = so_long.c makemap.c splitxy.c validate.c check_path.c check_path_utils.c \
	  a_star_successors.c check_path_utils2.c movement.c image_functions.c check_error.c

OSRC = $(SRC:%.c=%.o)
DEP = $(OSRC:%.o=%.d)

WWW = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OSRC)
	cc $(WWW) $(OSRC) -L libft/ -lft -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	rm -f $(OSRC) $(DEP)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/$(LIBFT)

-include $(DEP)

%.o: %.c
	cc $(WWW) -MMD -c $< -o $@ 

re: fclean all
