
CC = gcc
CFLAGS = -Wall
AR = ar rs
TARGET = libft.a


PART1 = ft_atoi\
	ft_isascii\
	ft_memcmp\
	ft_strchar\
	ft_strncmp\
	ft_toupper\
	ft_bzero\
	ft_isdigit\
	ft_memcpy\
	ft_strlcat\
	ft_strnstr\
	ft_isalnum\
	ft_isprint\
	ft_memmove\
	ft_strlcpy\
	ft_strrchar\
	ft_isalpha\
	ft_memchr\
	ft_memset\
	ft_strlen\
	ft_tolower\
	ft_strdup\
	ft_calloc

PART2 = ft_itoa\
	ft_putchar_fd\
	ft_putendl_fd\
	ft_putnbr_fd\
	ft_putstr_fd\
	ft_split\
	ft_striteri\
	ft_strjoin\
	ft_strmapi\
	ft_strtrim\
	ft_substr

BONUS = ft_lstadd_back\
	ft_lstclear\
	ft_lstiter\
	ft_lstmap\
	ft_lstsize\
	ft_lstadd_front\
	ft_lstdelone\
	ft_lstlast\
	ft_lstnew


all : $(TARGET)

SRCS = $(addprefix ./,$(addsuffix .c, $(PART1)))
OBJECTS = $(addprefix ./,$(addsuffix .o, $(PART1)))

SRCS1 = $(addprefix ./,$(addsuffix .c, $(PART2)))
OBJECTS1 = $(addprefix ./,$(addsuffix .o, $(PART2)))

SRCS2 = $(addprefix ./,$(addsuffix .c, $(BONUS)))
OBJECTS2 = $(addprefix ./,$(addsuffix .o, $(BONUS)))

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS) $(OBJECTS1) $(OBJECTS2)
	$(AR) $@ $^

fclean :
	rm *.o

clean :
	rm *.o libft.a

