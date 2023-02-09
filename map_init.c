/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:51:38 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/09 17:08:13 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	put_image(char **tab_map, t_data *data, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.floor,
		(x * 32), (y * 32));
	if (tab_map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit,
			(x * 32), (y * 32));
	if (tab_map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
			(x * 32), (y * 32));
	if (tab_map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.rocks,
			(x * 32), (y * 32));
	mlx_put_image_to_window(data->mlx, data->win, data->img.player,
		(data->player_x), (data->player_y));
	return (0);
}

int	fill_map(t_data	*data)
{
	int		x;
	int		y;

	y = 0;
	while (data->tab_map[y] && y < data->len.y + 1)
	{
		x = 0;
		while (data->tab_map[y][x] && x < data->len.x + 1)
		{
			put_image(data->tab_map, data, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int	map_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->len.x + 1) * 32,
			(data->len.y + 1) * 32, "So long");
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "./images/floor.xpm",
			&data->img_width, &data->img_height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "./images/exit.xpm",
			&data->img_width, &data->img_height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "./images/wall.xpm",
			&data->img_width, &data->img_height);
	data->img.rocks = mlx_xpm_file_to_image(data->mlx, "./images/Rocks.xpm",
			&data->img_width, &data->img_height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, "./images/player.xpm",
			&data->img_width, &data->img_height);
	fill_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.player,
		(data->player_x), (data->player_y));
	mlx_hook(data->win, ON_KEYDOWN, (1L << 0), key_check, data);
	mlx_hook(data->win, ON_DESTROY, (1L << 5), destroy, data);
	mlx_loop_hook(data->mlx, fill_map, data);
	mlx_loop(data->mlx);
	return (0);
}
