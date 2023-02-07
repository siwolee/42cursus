# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/02/02 23:51:44 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	cc -Wall -Werror -Wextra -g3 -L. -lft main.c -o tt

test :
	cc -Wall -Werror -Wextra -g3 -L. -lft test2.c -o tt
	echo "" > outfile
	./tt infile "grep a1" "cat -e" outfile
	cat outfile

fclean :
	rm -rf tt

re : fclean all



# NAME = pipex

# SRCS_DIR = ./srcs
# # MAIN = main.c
# # MAIN_OBJ = main.o
# SRCS = $(wildcard ./srcs/*.c)
# OBJS = $(SRCS:.c=.o)

# LIBFT = libft.a

# LIBGNL = libgnl.a
# GNL_SRCS = get_next_line/get_next_line_bonus.c \
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

# CC = cc
# CFLAGS = -Wall -Werror -Wextra -g3

# # AR = ar
# # ARFLAGS = crs

# all : $(NAME)

# $(NAME) : $(OBJS) $(LIBGNL)
# 	@$(CC) $(CFLAGS) -L./ -lgnl -o $(NAME) $(OBJS)
# 	@printf "🥳  compiled $(NAME)\n"

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