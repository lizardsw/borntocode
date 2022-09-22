# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongwch <seongwch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:04:51 by seongwch          #+#    #+#              #
#    Updated: 2022/09/22 17:29:35 by seongwch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
make = make
CC = CC
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./

SRCS_NAME =	philosopers_main.c\
			philo_utils.c\
			philo_start.c\
			philo_libft.c\
			philo_init.c\
			philo_action.c\
			error.c

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(OBJ) $(NAME)

re :
	$(make) fclean
	$(make) all

.PHONY : all re fclean clean