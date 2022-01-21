CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rs
RM = rm -f
make = make
NAME = ft_printf.a
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft


SOURCES = ft_printf.c\
	ft_printf1.c\
	ft_printf2.c\
	ft_printf_utils.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

$(LIBFT) :
	$(make) all -C $(LIBFT_DIR)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(AR) $(ARFLAGS) $@ $^ 

clean :
	$(make) fclean -C $(LIBFT_DIR)
	$(RM) $(OBJECTS)

fclean :
	$(make) fclean -C $(LIBFT_DIR)
	$(RM) $(OBJECTS) $(NAME)

re : fclean all

.PHONY : all bonus re fclean clean

