NAME = libft.a
SOURCES_DIRECTORY = ./
SOURCES_LIST = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
	ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
	ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
INCLUDE = ./
HEADERS = ./header.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:						${NAME}

${NAME}:					${OBJECTS_DIRECTORY} ${OBJECTS} $(HEADERS)
							ar rc $(NAME) $(OBJECTS)
							ranlib $(NAME)


${OBJECTS_DIRECTORY}:
							mkdir -p $(OBJECTS_DIRECTORY)

${OBJECTS_DIRECTORY}%.o : 	$(SOURCES_DIRECTORY)%.c $(HEADERS)
							$(CC) $(CFLAGS) -c -o $@ $<

clean:
							rm -f $(OBJECTS)

fclean:						clean
							rm -f $(NAME)
							rmdir $(OBJECTS_DIRECTORY)

re:							fclean all
