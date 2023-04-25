# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:25:35 by bfaure            #+#    #+#              #
#    Updated: 2023/03/20 13:22:44 by bfaure           ###   ########lyon.fr    #
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

LIBFT_A = $(DIR_LIBFT)$(LIBFT)

MLXLIB_A = $(DIR_MLX)$(LIBMLX)

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
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all		: ${NAME}

$(LIBFT_A):	force
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT} -j4

$(MLXLIB_A): force
	@ ${MAKE} ${LIBMLX} -C ${DIR_MLX} -j4

.PHONY:	all clean fclean re fclean_lib fclean_all force

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft -L${DIR_MLX} -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEAD} $(LIBFT_A) $(MLXLIB_A)
					@${MKDIR} ${DIR_OBJS}
					${CC} ${CFLAGS} -I $(DIR_LIBFT) -I ${DIR_MLX} -c $< -o $@

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
