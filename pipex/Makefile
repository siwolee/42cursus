# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/02/09 23:12:22 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




# NAME = pipex

# SRCS_DIR = ./srcs
# # MAIN = main.c
# # MAIN_OBJ = main.o
# SRCS = $(wildcard ./srcs/*.c)
# OBJS = $(SRCS:.c=.o)

LIBFT = libft.a

$(LIBFT) : 
	cd libft; make; cp $(LIBFT) ../
	cd ..

all :
	cc -Wall -Werror -Wextra -g3 -L. -lft main.c -o tt

test : $(LIBFT)
	rm -rf outfile
	cc -Wall -Werror -Wextra -g3 -L. -lft test3.c -o tt
	./tt infile "grep a1" "cat -e" outfile
	cat outfile

fclean :
	rm -rf tt

re : fclean all

# LIBGNL = libgnl.a
# GNL_SRCS = get_next_line/get_next_line_bonus.c 
# 			get_next_line/get_next_line_utils_bonus.c 
# GNL_OBJS = $(GNL_SRCS:.c=.o)

# # LIBFT_PRINTF = libftprintf.a
# # PRINTF_INC = printf/ft_printf.h
# # PRINTF_SRCS =  \
# # 		printf/ft_calloc.c \
# # 		printf/ft_isalpha.c \
# # 		printf/ft_strlcpy.c \
# # 		printf/ft_strlen.c \
# # 		printf/printf_format.c \
# # 		printf/printf_hex.c \
# # 		printf/printf_num.c \
# # 		printf/printf_ptr.c \
# # 		printf/printf_str.c \
# # 		printf/printf_type.c \
# # 		printf/printf.c 
# # PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

AR = ar
ARFLAGS = -cr

# all : $(NAME)

# $(NAME) : $(OBJS) $(LIBGNL)
# 	@$(CC) $(CFLAGS) -L./ -lgnl -o $(NAME) $(OBJS)
# 	@printf "🥳 compiled $(NAME)\n"

# %.o : %.c
# 	@$(CC) $(CFLAGS) -L./ -lft  -c $^ -o $@

# $(LIBGNL) : $(GNL_OBJS)
# 	ar -crs -o $(LIBGNL) $(GNL_OBJS)

# %.o : %.c
# 	@$(CC) $(CFLAGS) -c $^ -o $@

# bonus : $(NAME) $(CHK)

# clean :
# 	@rm -rf $(PRINTF_OBJS) *.dSYM $(OBJS)
# 	@printf "🗑  cleaned\n"

# fclean : clean
# 	@rm -rf $(NAME) $(TEST) $(CHK) $(LIBFT_PRINTF)
# 	@printf "🧽 fcleaned\n"

# re : fclean all

# .PHONY : fclean clean test all re