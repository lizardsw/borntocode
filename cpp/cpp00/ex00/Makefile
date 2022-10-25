# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongwch <seongwch@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 19:10:28 by seongwch          #+#    #+#              #
#    Updated: 2022/10/25 19:58:28 by seongwch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 
make = make
RM = rm -f
SOURCE = megaphone.cpp
OBJECT  = megaphone.o

all : $(NAME)

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $^ -o $@
	
$(NAME) : $(OBJECT)
	$(CC) -o $(NAME) $(OBJECT)

clean :
	$(RM) $(OBJECT)

fclean :
	$(RM) $(OBJECT) $(NAME)

re :
	$(make) fclean
	$(make) all

PHONY : all re clean fclean re 
