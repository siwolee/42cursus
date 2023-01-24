# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/01/24 15:02:56 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

TEST = test
TEST_SRC = test.c
TEST_OBJ =  $(TEST_SRCS:.c=.o)

SRCS_DIR = ./srcs
MAIN = srcs/main.c
SRCS = srcs/*.c
OBJS = $(SRCS:.c=.o)

BONUS = checker
CHK_SRCS = srcs/main_chk.c
CHK_OBJS = $(CHK_SRCS:.c=.o)

LIBFT_PRINTF = libftprintf.a
PRINTF_INC = printf/ft_printf.h
PRINTF_SRCS =  \
		printf/ft_calloc.c \
		printf/ft_isalpha.c \
		printf/ft_strlcpy.c \
		printf/ft_strlen.c \
		printf/printf_format.c \
		printf/printf_hex.c \
		printf/printf_num.c \
		printf/printf_ptr.c \
		printf/printf_str.c \
		printf/printf_type.c \
		printf/printf.c 
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 --fsanitise=address

AR = ar
ARFLAGS = crs

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_PRINTF)
	@$(CC) $(CFLAGS) -L./ -lftprintf -o $(NAME) $(SRCS) $(MAIN)
	@printf "🥳  compiled $(NAME)\n"

$(LIBFT_PRINTF) : $(PRINTF_OBJS)
	@printf "🤨  compiling ft_printf_objs\n"
	@$(AR) $(ARFLAGS) ./$(LIBFT_PRINTF) $(PRINTF_OBJS)
	@printf "😀  compiled ft_printf\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

bonus : $(NAME) $(CHK)
	
$(CHK) :
	@$(CC) $(CFLAGS) -L./ -lftprintf -o $(CHK) $(CHK_SRCS) $(SRCS)
	@printf "✅  checker compiled\n"

clean :
	@rm -rf $(PRINTF_OBJS) *.dSYM $(OBJS)
	@printf "🗑  cleaned\n"

fclean : clean
	@rm -rf $(NAME) $(TEST) $(CHK) $(LIBFT_PRINTF)
	@printf "🧽 fcleaned\n"

re : fclean all

.PHONY : fclean clean test all re