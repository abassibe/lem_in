# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/11/30 00:50:18 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS =	lem_in.c \
		parsing.c \
		kind_of_line.c \
		add_room.c \
		utils.c \
		room_exist.c \
		add_pipe.c \
		enough_data.c \
		fill_buff.c \
		algo.c \
		print_move.c \
		get_path.c \
		send_ants.c

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o: $(SRCPATH)%.c
	@gcc $(FLAGS) -c $< -I includes

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME)

re: fclean all
