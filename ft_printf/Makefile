# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoandria <yoandria@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/16 10:14:10 by yoandria          #+#    #+#              #
#    Updated: 2026/04/24 02:14:05 by yoandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       ft_print_char.c \
       ft_print_str.c \
       ft_print_ptr.c \
       ft_print_nbr.c \
       ft_print_unbr.c \
       ft_print_hex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@if [ -f main.c ]; then \
		$(CC) $(CFLAGS) main.c -L. -lftprintf -o test_printf; \
		echo "Compilation successful. Run './test_printf'"; \
	else \
		echo "Error: Please create a main.c to test."; \
	fi

.PHONY: all clean fclean re test