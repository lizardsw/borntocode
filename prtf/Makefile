CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rs
RM = rm -f
make = make
NAME = libftprintf.a
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
	$(make) -C $(LIBFT_DIR) all

$(NAME) : $(OBJECTS) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean :
	$(make) -C $(LIBFT_DIR) clean
	$(RM) $(OBJECTS)

fclean :
	$(make) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJECTS) $(NAME)

re : fclean all

.PHONY : all bonus re fclean clean