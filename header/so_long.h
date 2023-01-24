/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:44:36 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/24 13:22:18 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <fcntl.h>
# include "struct.h"
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/headers/libft.h"
# include "../Libft/headers/ft_printf.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include "../Libft/headers/get_next_line_bonus.h"

int		len_error(char *line);
int		check_len_error(int fd);
int		map_init(char **tab_map, t_len *len);
int		find_pce(char **tab_map, t_len *len);
int		free_map(char **tab_map, t_len *len);
int		creat_tab_map_cpy(int fd, t_len *len);
int		test_map(char **tab_map_cpy, t_len *len);
int		check_char(char **tab_map_cpy, t_len *len);
int		is_closed_map_x(char **tab_map, t_len *len);
int		is_closed_map_y(char **tab_map, t_len *len);
int		gps_x_player(char **tab_map_cpy, t_len *len);
int		gps_y_player(char **tab_map_cpy, t_len *len);

char	**creat_tab_map(int fd, t_len *len);

#endif