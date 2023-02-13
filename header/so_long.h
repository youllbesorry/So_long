/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:44:36 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/11 10:31:30 by bfaure           ###   ########lyon.fr   */
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
# include "../mlx/mlx.h"
# include "../Libft/headers/get_next_line_bonus.h"

int		len_error(char *line);
int		destroy(t_data *data);
int		map_init(t_data *data);
int		check_len_error(int fd);
int		dis_to_the_right(int x_p, int y_p, t_data *data);
int		dis_to_the_left(int x_p, int y_p, t_data *data);
int		dis_to_the_up(int x_p, int y_p, t_data *data);
int		dis_to_the_down(int x_p, int y_p, t_data *data);
int		key_check(int keycode, t_data *data);
int		find_pce(char **tab_map, t_data *data);
int		free_map(char **tab_map, t_data *data);
int		creat_tab_map_cpy(int fd, t_data *data);
int		test_map(char **tab_map_cpy, t_data *data);
int		check_char(char **tab_map_cpy, t_data *data);
int		is_closed_map_x(char **tab_map, t_data *data);
int		is_closed_map_y(char **tab_map, t_data *data);
int		gps_x_player(char **tab_map_cpy, t_data *data);
int		gps_y_player(char **tab_map_cpy, t_data *data);
int		fill_map(t_data	*data);
int		put_image(char **tab_map, t_data *data, int y, int x);
int		dis_to_the_down_coll(int x_p, int y_p, t_data *data);
int		dis_to_the_up_coll(int x_p, int y_p, t_data *data);
int		dis_to_the_left_coll(int x_p, int y_p, t_data *data);
int		dis_to_the_right_coll(int x_p, int y_p, t_data *data);

char	**creat_tab_map(int fd, t_data *data);

#endif