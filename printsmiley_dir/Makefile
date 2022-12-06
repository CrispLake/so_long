# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emajuri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:39:22 by emajuri           #+#    #+#              #
#    Updated: 2022/12/05 16:21:01 by emajuri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft.a

SRC = so_long.c 

OSRC = $(SRC:%.c=%.o)

WWW = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

#$(LIBFT):
#	make -C libft

$(NAME): $(OSRC)
	cc $(WWW) $(OSRC) -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	rm -f $(OSRC)
#	make clean -C libft

fclean: clean
	rm -f $(NAME)
#	rm -f libft/$(LIBFT)

%.o: %.c
	cc $(WWW) -I /usr/local/include -c -o $@ $^ 

re: fclean all
