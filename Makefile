# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 17:24:06 by jimikim           #+#    #+#              #
#    Updated: 2021/06/23 00:21:11 by jimikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MANDATORY_SRCS = ./mandatory/utils/ft_split.c \
       ./mandatory/utils/ft_std_io.c \
       ./mandatory/utils/ft_strcmp.c \
       ./mandatory/utils/ft_strjoin.c \
       ./mandatory/utils/ft_strlcat.c \
       ./mandatory/utils/ft_strlcpy.c \
       ./mandatory/utils/ft_strlen.c \
       ./mandatory/utils/ft_strncmp.c \
       ./mandatory/utils/ft_utils.c \
       ./mandatory/pipex.c
BONUS_SRCS = ./bonus/utils/ft_here_doc_bonus.c \
	      ./bonus/utils/ft_split_bonus.c \
	      ./bonus/utils/ft_std_io_bonus.c \
	      ./bonus/utils/ft_strcmp_bonus.c \
	      ./bonus/utils/ft_strjoin_bonus.c \
	      ./bonus/utils/ft_strlcat_bonus.c \
	      ./bonus/utils/ft_strlcpy_bonus.c \
	      ./bonus/utils/ft_strncmp_bonus.c \
	      ./bonus/utils/ft_utils_bonus.c \
	      ./bonus/get_next_line/get_next_line_bonus.c \
	      ./bonus/get_next_line/get_next_line_utils_bonus.c \
	      ./bonus/pipex_bonus.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME) : $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I./header -c $^ -o $@

all : $(NAME)

bonus : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)

clean :
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean :
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS) $(NAME)

re :
	make fclean
	make all

.PHONY :
	all
	bonus
	clean
	fclean
	re
