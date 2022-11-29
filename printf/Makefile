NAME = libftprintf.a

SRCS = printf.c printf_type.c

OBJS = $(SRCS:.c=.o)

INC = ./printf.h

DIR = ./

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = crs

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all