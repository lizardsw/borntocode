# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 20:09:40 by seongwch          #+#    #+#              #
#    Updated: 2022/07/07 10:18:11 by seongwch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
RM = rm -f
make = make
CFLAGS = -Wall -Wextra -Werror
LIBPRTFDIR = ./prtf/
LIBPRTF = ./prtf/libftprintf.a
SOURCE_DIR = ./src/

SOURCE_NAME = main.c \
				parsing.c \
				pipe.c

SOURCES = $(addprefix $(SOURCE_DIR), $(SOURCE_NAME))

OBJECTS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

all : $(NAME)

$(LIBPRTF) :
	$(make) -C $(LIBPRTFDIR) all

$(NAME) : $(LIBPRTF) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBPRTF)

clean :
	$(make) -C $(LIBPRTFDIR) clean
	$(RM) $(OBJECTS)

fclean :
	$(make) -C $(LIBPRTFDIR) fclean
	$(RM) $(OBJECTS) $(NAME)

re :
	$(make) fclean
	$(make) all

.PHONY : all re fclean clean
	