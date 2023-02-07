# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/01/30 18:56:31 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

TEST = test
TEST_SRC = test.c
TEST_OBJ =  $(TEST_SRCS:.c=.o)

SRCS_DIR = ./srcs
MAIN = srcs/main.c
SRCS = srcs/aftertreat.c \
		srcs/check.c \
		srcs/get_ab.c \
		srcs/merge_sort.c \
		srcs/merge.c \
		srcs/operate.c \
		srcs/operater_double.c \
		srcs/operater_r.c \
		srcs/operater_sp.c \
		srcs/pretreat.c \
		srcs/short2.c \
		srcs/short3.c \
		srcs/short4_eq.c \
		srcs/short4.c \
		srcs/sort_short.c \
		srcs/stack.c \
		srcs/ft_split.c \
		srcs/ft_strlcpy.c \
		srcs/get_next_line_utils.c \
		srcs/get_next_line.c 
OBJS = $(SRCS:.c=.o)

CHK = checker
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
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

AR = ar
ARFLAGS = crs

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_PRINTF)
	@$(CC) $(CFLAGS) -L./ -lftprintf -o $(NAME) $(SRCS) $(MAIN)
	@printf "🥳 compiled $(NAME)\n"

$(LIBFT_PRINTF) : $(PRINTF_OBJS)
	@printf "🤨 compiling ft_printf_objs\n"
	@$(AR) $(ARFLAGS) ./$(LIBFT_PRINTF) $(PRINTF_OBJS)
	@printf "😀 compiled ft_printf\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

bonus : $(CHK)
	
$(CHK) : $(CHK_SRCS) $(NAME)
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