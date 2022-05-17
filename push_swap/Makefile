CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rs
RM = rm -f
make = make
NAME = swap

SOURCES = *.c

OBJECTS = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(SOURCES)
	gcc *.c libftprintf.a

