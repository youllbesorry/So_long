# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:25:35 by bfaure            #+#    #+#              #
#    Updated: 2023/01/12 11:58:58 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	so_long

LIBFT		=	./libft.a

LIBMLX		=	./libmlx.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	./

DIR_MLX		=	mlminilibx_mms_20200219/

DIR_LIBFT	=	Libft/

# ---- Files ---- #

HEAD	=	so_long.h

SRCS	=	main.c\
			test_map.c\

OBJS	=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ******** RULES ******** #

all		:	${NAME}

# ---- Variables Rules ---- #

${NAME}	:	${OBJS} ${addprefix ${DIR_LIBFT}, ${LIBFT}} ${addprefix ${DIR_MLX}, ${LIBMLX}}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft -L${DIR_MLX} -lmlx -framework OpenGL -framework AppKit

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
			make ${LIBFT} -C ${DIR_LIBFT}

${addprefix ${DIR_MLX}, ${LIBMLX}}	:
			make ${LIBMLX} -C ${DIR_MLX}

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c so_long.h ./libft/libft.h | ${DIR_OBJS}
					${CC} ${CFLAGS} -I ${addprefix ${DIR_LIBFT}, headers/} -I ${DIR_MLX} -I. -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #

fclean_lib		:
					make fclean -C ${DIR_LIBFT}
					make clean -C ${DIR_MLX}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

fclean_all		:	fclean fclean_lib

re				:	fclean all

.PHONY:	all clean fclean re fclean_lib fclean_all