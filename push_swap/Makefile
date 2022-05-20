CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
make = make
NAME = push_swap
LIBPRT = ./prtf/libftprintf.a
LIBPRT_DIR = ./prtf

SOURCES = get_number.c\
	linkedlist.c\
	list_for_rule.c\
	list_push_pop.c\
	main.c\
	pivot_utils.c\
	pivot.c\
	push_rules_utils.c\
	push_rules.c\
	small_sort.c\
	sort_list.c

OBJECTS = $(SOURCES:.c=.o)

$(LIBPRT) : 
	$(make) -C $(LIBPRT_DIR) all

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

$(NAME) : $(OBJECTS) $(LIBPRT)
	echo $(OBJECTS)
	gcc -o $(NAME) $(OBJECTS) $(LIBPRT)

clean :
	$(make) -C $(LIBPRT_DIR) clean
	$(RM) $(OBJECTS)

fclean :
	$(make) -C $(LIBPRT_DIR) fclean
	$(RM) $(NAME) $(OBJECTS)

re : fclean all