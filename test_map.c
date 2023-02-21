/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:42:54 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/21 11:51:19 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	check_char(char **tab_map_cpy, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (tab_map_cpy[y] && y < data->len.y)
	{
		x = 0;
		while (tab_map_cpy[y][x] && x < data->len.x)
		{
			if (tab_map_cpy[y][x] != 'P' && tab_map_cpy[y][x] != 'C'
			&& tab_map_cpy[y][x] != 'E' && tab_map_cpy[y][x] != '0'
			&& tab_map_cpy[y][x] != '1')
				return (ft_printf("ERROR\nUnknown characters on the map\n"), -1);
			x++;
		}
		y++;
	}
	return (0);
}

size_t	check_path(char **tab_map_cpy, int x, int y, size_t check)
{
	if (tab_map_cpy[y][x - 1] == '0' || tab_map_cpy[y][x - 1] == 'C')
	{
		tab_map_cpy[y][x - 1] = '*';
		check = 1;
	}
	if (tab_map_cpy[y][x + 1] == '0' || tab_map_cpy[y][x + 1] == 'C')
	{
		tab_map_cpy[y][x + 1] = '*';
		check = 1;
	}
	if (tab_map_cpy[y - 1][x] == '0' || tab_map_cpy[y - 1][x] == 'C')
	{
		tab_map_cpy[y - 1][x] = '*';
		check = 1;
	}
	if (tab_map_cpy[y + 1][x] == '0' || tab_map_cpy[y + 1][x] == 'C')
	{
		tab_map_cpy[y + 1][x] = '*';
		check = 1;
	}
	return (check);
}

int	is_finishable(char **tab_map_cpy, t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (tab_map_cpy[y] && y < data->len.y)
	{
		x = 0;
		while (tab_map_cpy[y][x] && x < data->len.x)
		{
			if (tab_map_cpy[y][x] == 'C')
				return (ft_printf("ERROR \nMap can not be finished\n"), -1);
			if (tab_map_cpy[y][x] == 'E')
			{
				if (tab_map_cpy[y][x + 1] != '*'
				&& tab_map_cpy[y][x - 1] != '*'
				&& tab_map_cpy[y + 1][x] != '*'
				&& tab_map_cpy[y - 1][x] != '*')
					return (ft_printf("ERROR \nMap can not be finished\n"), -1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	test_map(char **tab_map_cpy, t_data *data)
{
	size_t	check;
	int		x;
	int		y;

	check = 1;
	tab_map_cpy[gps_y_player(tab_map_cpy, data)]
	[gps_x_player(tab_map_cpy, data)] = '*';
	while (check == 1)
	{
		check = 0;
		y = 0;
		while (tab_map_cpy[y] && y < data->len.y)
		{
			x = 0;
			while (tab_map_cpy[y][x] && x < data->len.x)
			{
				if (tab_map_cpy[y][x] == '*')
					check = check_path(tab_map_cpy, x, y, check);
				x++;
			}
			y++;
		}
	}
	return (is_finishable(tab_map_cpy, data));
}
