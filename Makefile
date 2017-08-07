# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niragne <niragne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 16:55:07 by niragne           #+#    #+#              #
#    Updated: 2017/08/07 15:04:01 by niragne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
CC			=	gcc
CFLAGS		=	-Ofast
CFLAGSMLX	=	-framework OpenGL -framework AppKit

LIB_PATH	=	libft
LIB			=	$(LIB_PATH)/libft.a

INC_DIR		=	includes
INCS		=	-I $(INC_DIR) -I $(LIB_PATH)

SRC_DIR		=	src
SRC			=	cplx.c \
				image.c \
				julia.c \
				square.c \
				mandelbrot.c \
				main.c 

OBJ_DIR		=	obj

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all: $(NAME)

$(NAME): obj $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(CFLAGSMLX) $(LIB) libmlx.a

obj:
	mkdir obj

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
