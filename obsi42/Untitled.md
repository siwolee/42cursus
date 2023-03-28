
```make
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 17:16:26 by juhyulee           #+#    #+#             #
#    Updated: 2023/03/24 21:44:43 by siwolee	        ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = ./src
SOURCES =  \
		catch_signal.c\
		env0.c\
		env1.c\
		error.c\
		error1.c\
		ft_split_replace.c\
		init.c\
		main.c\
		node.c\
		parse.c\
		red.c\
		util.c\
		util0.c\
		util1.c\
		execute/child.c\
		execute/command.c\
		execute/exec.c\
		execute/file_open.c\
		execute/init_cmd.c\
		execute/parent.c\
		execute/util.c\
		execute/heredoc.c\
		builtin/echo.c \
		builtin/env.c \
		builtin/exit.c \
		builtin/export.c \
		builtin/pwd.c \
		builtin/unset.c \
		builtin/cd.c \
		merge.c

SRCS = $(patsubst %.o,$(SRCS_DIR)/%.o,$(SOURCES))

# OBJS = $(SRCS:.c=.o)
OBJ_DIR = ./obj
OBJECTS = $(SOURCES:.c=.o)
OBJS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJECTS))

# 서브 디렉토리 넣으셈
SUBDIR = builtin execute
OBJS_SUBDIR = $(patsubst %,$(OBJ_DIR)/%,$(SUBDIR))

LIBFT = ./libft/libft.a
HEADER = -I./header
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f
RL_INC = -I$(HOME)/.brew/opt/readline/include
RL_LIB = -L$(HOME)/.brew/opt/readline/lib -lreadline


ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
				@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
		  -nrRf $(firstword $(MAKEFILE_LIST)) \
		  ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr " [\`expr $C '*' 10 / $T\`" : '.*\(....\)$$'`%]"
endif

.PHONY: all clean

all: target
				@$(ECHO) All done

$(OBJS_SUBDIR) :
			@mkdir objs
			@mkdir $(OBJS_SUBDIR)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
			@$(CC) $(CFLAGS) $(RL_INC) $(HEADER) -c $< -o $@
			@$(ECHO) Compiling $@
			@sleep 0.1

$(LIBFT) :
			@make -C ./libft
			@printf "📚 LIBFT library compiled\n"

target: $(OBJS_SUBDIR) $(LIBFT) $(OBJS)
				@$(ECHO) Linking $@
				@sleep 0.1
				@touch $@
			
clean :
			@make -C ./libft fclean
			@$(RM) $(OBJS)
			@printf "🗑 cleaned\n"

fclean :	clean
			@$(RM) $(NAME)
			@printf "🧽 fcleaned\n"

re :		fclean all

.PHONY : all clean fclean re


endif



# all : 		$(NAME)

# $(NAME) :	$(OBJS_SUBDIR) $(OBJS) print_objs_compile $(LIBFT)
# 			@$(CC) $(CFLAGS) -o $(NAME) $(HEADER) $(LIBFT) $(OBJS) $(RL_LIB)
# 			@printf "🥳 compiled $(NAME)\n"

# print_objs_compile :
# 			@printf "🍎 compiled OBJS\n"

# $(OBJS_SUBDIR) :
# 			@mkdir objs
# 			@mkdir $(OBJS_SUBDIR)

# $(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
# 			@$(CC) $(CFLAGS) $(RL_INC) $(HEADER) -c $< -o $@

# $(LIBFT) :
# 			@make -C ./libft
# 			@printf "📚 LIBFT library compiled\n"

# clean :
# 			@make -C ./libft fclean
# 			@$(RM) $(OBJS)
# 			@printf "🗑 cleaned\n"

# fclean :	clean
# 			@$(RM) $(NAME)
# 			@printf "🧽 fcleaned\n"

# re :		fclean all

# .PHONY : all clean fclean re

```
