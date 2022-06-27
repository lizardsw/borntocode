# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 20:09:40 by seongwch          #+#    #+#              #
#    Updated: 2022/06/27 21:39:41 by seongwch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc -g
RM = rm -f
make = make
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit -lz
GNLDIR = ./gnl
GNL = ./gnl/gnl.a
MLXDIR = ./mlx
MLX = ./mlx/libmlx.a
SOURCE_DIR = ./mandatory/
SOURCE_BONUS_DIR = ./bonus/

SOURCE_NAME = check_map.c display_utils.c display.c event_manage.c \
				get_map.c key_event.c liblist.c main.c
SOURCE_BONUS_NAME = check_map_bonus.c display_bonus.c display_utils_bonus.c enemy_game_bonus.c \
						event_manage_bonus.c game_event_bonus.c get_map_bonus.c input_enemy_bonus.c \
						liblist_bonus.c main_bonus.c make_itoa_bonus.c
SOURCES = $(addprefix $(SOURCE_DIR), $(SOURCE_NAME))
SOURCES_BONUS = $(addprefix $(SOURCE_BONUS_DIR), $(SOURCE_BONUS_NAME))

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

all : $(NAME)

$(GNL) :
	$(make) -C $(GNLDIR) all

$(MLX) :
	$(make) -C $(MLXDIR) all

$(NAME) : $(GNL) $(MLX) $(OBJECTS)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJECTS) $(GNL)

clean :
	$(make) -C $(GNLDIR) clean
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean :
	$(make) -C $(GNLDIR) fclean
	$(make) -C $(MLXDIR) clean
	$(RM) $(OBJECTS) $(NAME)
	$(RM) $(OBJECTS_BONUS) $(NAME_BONUS)

re :
	$(make) fclean
	$(make) all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(GNL) $(MLX) $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME_BONUS) $(OBJECTS_BONUS) $(GNL)
	