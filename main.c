/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:09:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/12 10:09:27 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	check_map_error(t_data *data, int fd)
{
	data->len.y = check_len_error(fd);
	if (data->len.y == 0)
		return (close(fd), ft_printf("ERROR\nempty map\n"), -1);
	if (data->len.y == -1)
		return (close(fd), -1);
	close(fd);
	return (0);
}

void	init_data(t_data *data)
{
	data->player_x = 0;
	data->player_y = 0;
	data->player_dirx = 0;
	data->player_diry = 0;
	data->img_height = 0;
	data->img_width = 0;
}

void	fill_data(t_data *data, int fd)
{
	data->tab_map = creat_tab_map(fd, data);
	data->player_x = gps_x_player(data->tab_map, data) * 32;
	data->player_y = gps_y_player(data->tab_map, data) * 32;
	data->coll = 0;
	data->move = 0;
	close(fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	fd = 0;
	init_data(&data);
	if (argc > 1)
	{
		if (ft_strnstr((const char *) argv[1], ".ber", ft_strlen(argv[1])) == 0)
			return (ft_printf("ERROR\nMap not in .ber\n"), -1);
		fd = open(argv[1], O_RDONLY);
		if (check_map_error(&data, fd) == -1)
			return (-1);
		fd = open(argv[1], O_RDONLY);
		if (creat_tab_map_cpy(fd, &data) == -1)
			return (close(fd), -1);
		close(fd);
		if (data.len.y == data.len.x)
			return (ft_printf("ERROR\nMap not rectangular\n"), -1);
		fd = open(argv[1], O_RDONLY);
		fill_data(&data, fd);
		map_init(&data);
	}
	else
		return (ft_printf("ERROR\nyou need to pass at leas one maps\n"), -1);
	return (0);
}
