#makefile for test.

NAME = a.out

SRCS = test.c ../*.c

INC = ../*.h

DIR = ./

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -D BUFFER_SIZE=2147483646

AR = ar
ARFLAGS = crs

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) $(SRCS) $(INC)

fclean : clean
	rm -f $(NAME)

re : fclean all