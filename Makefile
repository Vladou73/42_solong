# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 17:55:57 by vnafissi          #+#    #+#              #
#    Updated: 2022/02/22 16:54:52 by vnafissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*********** VARIABLES ************

#VARIABLE=VALUE
CC = clang
CFLAGS = -Wall -Werror -Wextra -Wconversion
SYSTEM = $(shell uname)

#Varying flags & compilation for different systems
#ifeq (${SYSTEM}, Darwin)
MLX_USED = mlx_mac
INCS = -I ./includes -I ./libft/includes -I ./${MLX_USED}
MLX_FLAGS = -L ./${MLX_USED}  -lmlx -Ofast -framework OpenGL -framework AppKit
#else
#ifeq (${SERVER}, Linux)
#MLX_USED = mlx_linux
#INCS = -I ./includes -I ./libft -I ./${MLX_USED}
#MLX_FLAGS	=	-L./${MLX_USED} -lmlx -lX11 -lbsd -lXext -lm
#endif

LIBFTDIRNAME = libft
LIBFTNAME = libft.a

NAME = so_long
SRCS = so_long.c parse_input.c
OBJS=$(SRCS:.c=.o)

#*********** RULES ************
%.o : %.c
	$(CC) ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	${MAKE} -C libft
	${MAKE} -C ${MLX_USED}
	${CC} -g ${CFLAGS} ${MLX_FLAGS} -o ${NAME} ${OBJS} libft/libft.a ${INCS}

clean:
	${MAKE} -C ${LIBFTDIRNAME} clean
	${MAKE} -C ${MLX_USED} clean
	rm -f ${OBJS}

fclean: clean
	${MAKE} -C ${LIBFTDIRNAME} fclean
	rm -f $(NAME)

re: fclean all

#in case files exist with same name as targets
.PHONY: all clean fclean re bonus
