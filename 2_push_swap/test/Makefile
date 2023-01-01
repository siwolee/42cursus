# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:34:39 by siwolee           #+#    #+#              #
#    Updated: 2023/01/01 22:17:34 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = a.out

TEST = test.c

SRCS_DIR = ../SRCS
SRCS = $(SRCS_DIR)/*.c
# OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3

.PHONY : all clean fclean re mende

all : $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) $(SRCS) $(TEST) -o $(NAME)

clean :
	rm -f $(OBJS) $(B_OBJS) 

fclean : clean
	rm -f $(NAME) $(B_NAME)

re : fclean all