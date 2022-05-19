CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
make = make
NAME = a.out
LIBPRT = libftprintf.a

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES: .c = .o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

$(NAME) : $(OBJECTS) $(LIBPRT)
	gcc -o $(NAME) $(OBJECTS) $(LIBPRT)

clean :
	rm *.o