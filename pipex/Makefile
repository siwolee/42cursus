# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/02/23 17:47:44 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

AR = ar
ARFLAGS = -rc

SRCS_DIR = ./srcs
MENDE_SRC = $(SRCS_DIR)/pipex_mende.c
MENDE_OBJ = $(MENDE_SRCS:.c=.o)
MAIN_OBJ = main.o
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
INCLUDE = $(SRCS_DIR)/pipex.h

LIBFT = libft.a


all : $(NAME)

$(NAME) : $(LIBFT) $(MENDE_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -L. -lft -o $(NAME) $(MENDE_OBJ) $(OBJS)

bonus : $(LIBFT)

$(MENDE_OBJ) : $(MENDE_SRCS) $(INCLUDE)
	$(CC) $(CFLAGS) -L. -lft -c -o $@ $>

*.o : *.c $(INCLUDE)
	$(CC) $(CFLAGS) -L. -lft -c -o $@ $^


test : $(LIBFT)
	rm -rf outfile
	cc -Wall -Werror -Wextra -g3 -L. -lft test3.c -o tt
	./tt infile "grep a1" "cat -e" outfile
	cat outfile

$(LIBFT) : 
	@cd libft ; make; cd ../
	@mv libft/$(LIBFT) ./
	@printf "LIBFT library compiled\n"
	

fclean : clean
	rm -rf 

clean :
	rm -rf $(OBJS) $(MENDE_OBJ) $(BONUS_OBJ) $(LIBFT)

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

.PHONY : fclean clean test all re