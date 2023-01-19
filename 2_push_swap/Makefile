# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/01/19 19:15:52 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

TEST = test
TEST_SRC = test.c
TEST_OBJ =  $(TEST_SRCS:.c=.o)

SRCS_DIR = ./srcs
INC = $(SRC_DIR)/include/push_swap.h
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
		srcs/ft_strlcpy.c
OBJS = $(SRCS:.c=.o)

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
CFLAGS = -Wall -Werror -Wextra -g3

AR = ar
ARFLAGS = crs
CHK = chker
CHK_DIR = ./chk
CHK_INC = include
CHK_SRCS_DIR = $(CHK_DIR)/srcs
CHK_SRCS = \
		chk/srcs/chker.c \
		chk/srcs/ft_atoi.c \
		chk/srcs/get_next_line_utils.c \
		chk/srcs/get_next_line.c \
		chk/srcs/operate.c \
		chk/srcs/operater_.c \
		chk/srcs/pretreat.c \
		chk/srcs/sanantest.c \
		chk/srcs/util.c
CHK_OBJS = $(CHK_SRCS:.c=.o)

all : $(NAME) $(LIBFT_PRINTF)

$(NAME) : $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) -L./printf -lftprintf -o $(NAME) $(SRCS) $(MAIN)

$(LIBFT_PRINTF) : $(PRINTF_OBJS)
	$(AR) $(ARFLAGS) ./printf/$(LIBFT_PRINTF) $(PRINTF_OBJS)
	# rm -rf $(PRINTF_OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

tt : $(TEST)

$(TEST) : 
	$(CC) $(CFLAGS) -o $(TEST) -I$(INC_DIR) $(SRCS) $(TEST_SRCS)

check : $(NAME) $(CHK)

$(CHK) :
	$(CC) $(CFLAGS) -o $(CHK) -I$(CHK_INC) $(CHK_SRCS) $(CHK_FILE)	

clean :
	rm -rf $(OBJS) $(PRITNF_OBJS)

fclean : clean
	rm -rf $(NAME) $(TEST) $(CHK) $(LIBFT_PRINTF)

re : fclean all

.PHONY : fclean clean test all re