# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/21 17:49:07 by dcastro-          #+#    #+#              #
#    Updated: 2017/09/12 22:21:28 by dcastro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc -Wall -Werror -Wextra

SRCS = srcs/main.c srcs/hooks.c srcs/mandle.c srcs/julia.c srcs/draw.c srcs/opts.c\


OBJ = $(SRCS:.c=.o)

INC = -L libft/ -lft -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx_macos
	make -C libft
	$(CC) $(INC) $(OBJ) -o $(NAME)

clean:
	make -C libft/ clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)

re: fclean all
