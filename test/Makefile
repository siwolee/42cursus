# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 19:48:02 by siwolee           #+#    #+#              #
#    Updated: 2023/01/02 20:27:38 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#out - executing file
#lib - library
NAME = a.out

TEST = test.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = crs

ifeq ($(DEBUG),true)
	CDEBUG = -g
endif

RM = rm
RMFLAGS = -rf

INC_DIR = include

SRC_DIR = ./src
SRC_UTIL_DIR = $(SRC_DIR)/util

SRCS = \
	$(wildcard $(SRC_DIR)/*.c)	\
	$(wildcard $(SRC_UTIL_DIR)/*.c)

OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_DIR = ./lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT).a
LIBFT_INC_DIR = $(LIBFT_DIR)/include

LIB_DIR = ./lib
LIB_PATH = $(wildcard $(LIB_DIR)/*.a)
LIB_SRCS = $(subst $(LIB_DIR),,$(subst .a, ,$(subst ft, ,$(LIB_PATH))))




all : $(NAME)

bonus : $(NAME)

clean : $(LIBFT)_clean
	@$(RM) $(RMFLAGS) $(OBJS)
	@printf "🧹 $(FG_TEXT)Cleaning $(NAME)'s Object files...\n"

fclean : $(LIBFT)_fclean clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "🧹 Cleaning all $(NAME)\n"

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) $(CDEBUG) -I$(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@
	printf "🚧 Create $@ from$<\n"

# #최종 라이브러리 구성
# $(NAME) : $(LIBFT_FILE) $(OB성S)
# 	@$(AR) $(ARFLAGS) $@ $(OBJS)

#최종 실행 파일 제작
$(NAME) : $(LIBFT_FILE) $(OB성S)
	$(CC) $(CCFLAGS) -o $@ -I$(INC_DIR) -c $(TEST) -L$(LIB_DIR) -l$(LIB_SRCS)


$(LIBFT) : $(LIBFT_FILE)

#libft makefile 실행
$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)
	@mv $(LIBFT_FILE) $(LIB_DIR)/$(LIBFT).a

$(LIBFT)_clean :
	@make --no-print-directory -C $(LIBFT_DIR) clean
$(LIBFT)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean

.PHONY : \
	all clean fclean re \
	@(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
	debug \