# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 16:41:43 by amtan             #+#    #+#              #
#    Updated: 2025/08/13 17:19:39 by amtan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = bsq
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INCS    = -I .

SRCS    = dp_rows.c fill_square.c main.c parse_header_line.c parse_map.c \
          print_free_map.c read_line.c solve_map.c update_best.c
OBJS    = $(SRCS:.c=.o)

DEPS    = bsq.h solver_int.h reader_int.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
