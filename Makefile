# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 17:55:57 by vnafissi          #+#    #+#              #
#    Updated: 2022/02/14 15:57:14 by vnafissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#$@ The filename representing the target.
#$< The filename of the first prerequisite.
#$? The names of all prerequisites that are newer than the target, separated by spaces.
#$^ The filenames of all the prerequisites, separated by spaces.
#This list has duplicate filenames removed since for most uses,
#such as compiling, copying, etc., duplicates are not wanted.

#*********** VARIABLES ************

#VARIABLE=VALUE
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wconversion
LIBFTDIRNAME = libft
LIBFTNAME = libft.a
INCS = -I ./includes -I ./libft

NAME = push_swap
SRCS = push_swap.c ft_linked_lists.c ft_linked_lists2.c ft_operations.c \
ft_initialization.c ft_big_algo.c ft_small_algo.c
OBJS=$(SRCS:.c=.o)

#*********** RULES ************

#old fashioned suffix rule : ‘.c.o’ (target = '.o', source = '.c')
# is equivalent to the pattern rule ‘%.o : %.c’. which is up to date.
%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCS}

all: $(NAME)

$(NAME): $(OBJS)
	${MAKE} -C libft
	${CC} -g ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a ${INCS}

clean:
	${MAKE} -C ${LIBFTDIRNAME} clean
	rm -f ${OBJS}

fclean: clean
	${MAKE} -C ${LIBFTDIRNAME} fclean
	rm -f $(NAME)

re: fclean all

#in case files exist with same name as targets
.PHONY: all clean fclean re bonus
