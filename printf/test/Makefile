NAME = a.out

SRCS = test.c ../printf.c ../printf_type.c\
		../ft_isalpha.c ../ft_strlcpy.c ../ft_strlen.c\
		../printf_num.c

INC = ../ft_printf.h

DIR = ./

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

AR = ar
ARFLAGS = crs

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) $(SRCS) $(INC)

fclean : clean
	rm -f $(NAME)

re : fclean all