# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 22:35:15 by ssachet           #+#    #+#              #
#    Updated: 2015/03/17 19:11:01 by ssachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = ft_select
MAIN = select.c
LIB = -Llibft -lft -I libft -I libft/get_next_line -I libft/printf
TERMLIB = -ltermcap

SRC= select.c lst.c signals.c lst_generic.c print.c print_help.c move.c search.c selection.c underlining.c xy.c del_end.c
H = select.h libft/libft.h libft/get_next_line/get_next_line.h libft/printf/ft_printf.h
O = $(SRC:.c=.o)

.PHONY: all clean fclean re libft

all: libft $(EXEC)

libft:
	make -C libft
%.o: %.c $(H)
	$(CC) $(CFLAGS) -c $<

$(EXEC): $(O) libft/libft.a
	$(CC) -o $(EXEC) $(O) $(LIB) $(TERMLIB)

clean:
	rm -rf $(O)
	make clean -C libft

fclean: clean
	rm -rf $(EXEC)
	make clean -C libft

re: fclean all
