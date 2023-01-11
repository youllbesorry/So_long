# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 13:21:39 by bfaure            #+#    #+#              #
#    Updated: 2022/12/16 09:16:01 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putnbr_base.c\
		ft_putptr.c\

HEADER = ft_printf.h

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