NAME = libft.a

SRCS = \
		ft_bzero.c \
		ft_calloc.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_substr.c \
		ft_strlcpy.c

OBJS = $(SRCS:.c=.o)

INC = ./libft.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = crs

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(B_OBJS) $(OBJS)

fclean : clean
	rm -f $(BONUS) $(NAME)

re : fclean all