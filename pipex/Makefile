# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 20:09:40 by seongwch          #+#    #+#              #
#    Updated: 2022/07/02 16:15:28 by seongwch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc -g
RM = rm -f
make = make
CFLAGS = -Wall -Wextra -Werror
LIBPRTFDIR = ./prtf/
LIBPRTF = ./prtf/libftprintf.a
SOURCE_DIR = ./src/
SOURCE_BONUS_DIR = ./bonus/

SOURCE_NAME = main.c check_file.c *.c

SOURCES = $(addprefix $(SOURCE_DIR), $(SOURCE_NAME))
SOURCES_BONUS = $(addprefix $(SOURCE_BONUS_DIR), $(SOURCE_BONUS_NAME))


OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

all : $(NAME)

$(LIBPRTF) :
	$(make) -C $(LIBPRTFDIR) all

$(NAME) : $(LIBPRTF) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBPRTF)

clean :
	$(make) -C $(LIBPRTFDIR) clean
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean :
	$(make) -C $(LIBPRTFDIR) fclean
	$(RM) $(OBJECTS) $(NAME)
	$(RM) $(OBJECTS_BONUS) $(NAME_BONUS)

re :
	$(make) fclean
	$(make) all

bonus : $(NAME_BONUS)

.PHONY : all bonus re fclean clean
	