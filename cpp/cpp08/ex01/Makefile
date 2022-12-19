# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 19:10:28 by seongwch          #+#    #+#              #
#    Updated: 2022/11/30 15:44:16 by seongwch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span
CC = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 
make = make
RM = rm -f
SOURCE = main.cpp\
			Span.cpp
OBJECT = $(SOURCE:.cpp=.o)

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

.PHONY : all re clean fclean re 
