# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:25:35 by bfaure            #+#    #+#              #
#    Updated: 2023/03/03 15:52:07 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	so_long

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	./

DIR_MLX		=	mlx/

DIR_LIBFT	=	Libft/

# ---- Files ---- #

HEAD			=	header/so_long.h

SRCS			=	main.c\
					test_map.c\
					map_error.c\
					utils.c\
					creat_map.c\
					map_init.c\
					event.c\
					loop.c\
					distance_cal.c\
					distance_to_coll.c\
					distance_to_exit.c\

OBJS = ${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all		:
	@ ${MAKE} libs -j4
	@ ${MAKE} ${NAME} -j4

libs	:
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT}
	@ ${MAKE} ${LIBMLX} -C ${DIR_MLX}

.PHONY:	all clean fclean re fclean_lib fclean_all

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft -L${DIR_MLX} -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
			
${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
			@ $(MAKE) ${LIBFT} -C ${DIR_LIBFT}

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEAD} ./Libft/headers/ft_printf.h ./Libft/headers/get_next_line.h ./Libft/headers/libft.h | ${DIR_OBJS}
					${CC} ${CFLAGS} -I ${addprefix ${DIR_LIBFT}, headers/} -I ${DIR_MLX} -c $< -o $@

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

re				:	fclean_all
					$(MAKE)
