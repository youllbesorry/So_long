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
	if (read(fd, 0, 0) == -1)
		return (close(fd),
			ft_printf("ERROR\nYou have not the right to read the map"), -1);
	if (data->len.y == 0)
		return (close(fd), ft_printf("ERROR\nEmpty map\n"), -1);
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
	data->len.x = 0;
	data->len.y = 0;
	data->img.exit = NULL;
	data->img.floor = NULL;
	data->img.player = NULL;
	data->img.rocks = NULL;
	data->img.wall = NULL;
	data->tab_map = NULL;
}

void	fill_data(t_data *data, int fd)
{
	data->tab_map = NULL;
	creat_tab_map(fd, data);
	data->player_x = gps_x_player(data->tab_map, data) * 32;
	data->player_y = gps_y_player(data->tab_map, data) * 32;
	data->coll = 0;
	data->move = 0;
	if (data->len.x >= 15 && data->len.x < 30)
		data->v_dir = 2;
	else if (data->len.x >= 30)
		data->v_dir = 4;
	else
		data->v_dir = 1;
	close(fd);
}

int	ber_error(char **argv)
{
	size_t	len;

	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
	|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	fd = 0;
	init_data(&data);
	if (argc == 2)
	{
		if (ber_error(argv) == -1)
			return (ft_printf("ERROR\nMap not in .ber\n"), -1);
		fd = open(argv[1], O_RDONLY);
		if (check_map_error(&data, fd) == -1)
			return (-1);
		fd = open(argv[1], O_RDONLY);
		if (creat_tab_map_cpy(fd, &data) == -1)
			return (close(fd), -1);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		fill_data(&data, fd);
		map_init(&data);
		close(fd);
	}
	else
		return (ft_printf("ERROR\nYou need to give 1 map to the game\n"), -1);
	return (0);
}
