CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rs
RM = rm -f
make = make
NAME = gnl.a

SOURCES = get_next_line_utils.c\
		get_next_line.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

$(NAME) : $(OBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean :
	$(RM) $(OBJECTS)

fclean :
	$(RM) $(OBJECTS) $(NAME)

re : fclean all

.PHONY : all bonus re fclean clean