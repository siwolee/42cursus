# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/01/17 18:06:34 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

TEST = test
TEST_SRC = test.c
TEST_OBJ =  $(TEST_SRCS:.c=.o)

SRCS_DIR = ./srcs
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

INC_DIR = include

MAIN_SRC = $(SRC_DIR)/main.c
MAIN_OBJ =  $(MAIN_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3

CHK = chker
CHK_DIR = ./chk
CHK_INC = $(CHK_DIR)/include
CHK_SRCS_DIR = $(CHK_DIR)/srcs
CHK_FILE = $(CHK_DIR)/chker.c
CHK_SRCS = $(wildcard $(CHK_SRCS_DIR)/*.c)
CHK_OBJS = $(CHK_SRCS:.c=.o)



all : $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) -o $(NAME) -I$(INC_DIR) $(SRCS)

tt : $(TEST)

$(TEST) : 
	$(CC) $(CFLAGS) -o $(TEST) -I$(INC_DIR) $(SRCS) $(TEST_FILE)

check : $(NAME) $(CHK)

$(CHK) :
	$(CC) $(CFLAGS) -o $(CHK) -I$(CHK_INC) $(CHK_SRCS) $(CHK_FILE)	

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(TEST) $(CHK)

re : fclean all

.PHONY : fclean clean test all re