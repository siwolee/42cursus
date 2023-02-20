# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/02/18 19:27:57 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




# NAME = pipex

# SRCS_DIR = ./srcs
# # MAIN = main.c
# # MAIN_OBJ = main.o
SRCS = $(wildcard ./srcs/*.c)
# OBJS = $(SRCS:.c=.o)

LIBFT = libft.a

$(LIBFT) : 
	cd libft; make; cp $(LIBFT) ../
	cd ..

all : $(LIBFT)
	cc -Wall -Werror -Wextra -g3 -L. -lft -o $(NAME) $(SRCS)

test : $(LIBFT) $(all)
	rm -rf outfile
	cc -Wall -Werror -Wextra -g3 -L. -lft test3.c -o tt
	./tt infile "grep a1" "cat -e" outfile
	cat outfile

fclean :
	rm -rf tt


re : fclean all


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