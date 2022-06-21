NAME = a.out
CC = gcc
RM = rm -f
make = make
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lz
GNLDIR = ./gnl
GNL = ./gnl/gnl.a

SOURCES = *.c

OBJECTS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $^

all : $(NAME)

$(GNL) :
	$(make) -C $(GNLDIR) all

$(NAME) : $(OBJECTS) $(GNL)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJECTS) $(GNL)

clean :
	$(make) -C $(GNLDIR) clean
	$(RM) $(OBJECTS)

fclean :
	$(make) -C $(GNLDIR) fclean
	$(RM) $(OBJECTS) $(NAME)