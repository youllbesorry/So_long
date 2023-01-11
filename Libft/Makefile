# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:23:52 by bfaure            #+#    #+#              #
#    Updated: 2022/11/29 12:22:53 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_strchr.c\
	ft_strlen.c\
	ft_strrchr.c\
	ft_bzero.c\
	ft_isascii.c\
	ft_memchr.c\
	ft_memmove.c\
	ft_strlcat.c\
	ft_strncmp.c\
	ft_tolower.c\
	ft_isalnum.c\
	ft_isdigit.c\
	ft_memcmp.c\
	ft_memset.c\
	ft_strlcpy.c\
	ft_strnstr.c\
	ft_toupper.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\

HEADER = libft.h

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re