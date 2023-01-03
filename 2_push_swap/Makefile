# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/01/03 16:32:22 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
MAIN_FILE = main.c

TEST = test
TEST_FILE = test.c

SRCS_DIR = ./srcs
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

INC_DIR = include

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_FILE) -o $(NAME)

tt : $(TEST)

$(TEST) : 
	$(CC) $(CFLAGS) -o $(TEST) -I$(INC_DIR) $(SRCS) $(TEST_FILE)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(CDEBUG) -I$(INC_DIR) -c $< -o $@


clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(TEST)

re : fclean all

.PHONY : fclean clean test all re