/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:51:38 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/24 16:52:29 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	map_init(char **tab_map, t_len *len)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_data	data;

	mlx = mlx_init();
	win = mlx_new_window(mlx, (len->x + 1) * 32, (len->y + 1) * 32, "So long");
	data.img.floor = mlx_xpm_file_to_image(mlx, "./images/floor.xpm", &data.img_width, &data.img_height);
	data.img.exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &data.img_width, &data.img_height);
	data.img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &data.img_width, &data.img_height);
	data.img.rocks = mlx_xpm_file_to_image(mlx, "./images/Rocks.xpm", &data.img_width, &data.img_height);
	data.img.player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &data.img_width, &data.img_height);
	y = 0;
	while (tab_map[y] && y < len->y + 1)
	{
		x = 0;
		while (tab_map[y][x] && x < len->x + 1)
		{
			mlx_put_image_to_window(mlx, win, data.img.floor, (x * 32), (y * 32));
			if (tab_map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, data.img.exit, (x * 32), (y * 32));
			if (tab_map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, data.img.wall, (x * 32), (y * 32));
			if (tab_map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, data.img.rocks, (x * 32), (y * 32));
			if (tab_map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, data.img.player, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
