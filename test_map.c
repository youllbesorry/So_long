/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:42:54 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/17 16:31:21 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	free_map(char **tab_map, t_len *len)
{
	int	i;

	i = 0;
	while (i < len->y + 2)
	{
		free(tab_map[i]);
		i++;
	}
	free(tab_map);
	return (-1);
}

int	gps_x_player(char **tab_map_cpy, t_len *len)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab_map_cpy[y] && y < len->y)
	{
		x = 0;
		while (tab_map_cpy[y][x] && x < len->x)
		{
			if (tab_map_cpy[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	gps_y_player(char **tab_map_cpy, t_len *len)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab_map_cpy[y] && y < len->y)
	{
		x = 0;
		while (tab_map_cpy[y][x])
		{
			if (tab_map_cpy[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

void	test_map(char **tab_map_cpy, t_len *len)
{
	size_t	check;
	int		x;
	int		y;

	check = 1;
	x = gps_x_player(tab_map_cpy, len);
	y = gps_y_player(tab_map_cpy, len);
	ft_printf("x = %i\n", x);
	ft_printf("y = %i\n", y);
	while (check == 1)
	{
		check = 0;
		while (tab_map_cpy[y] && y < len->y)
		{
			x = 0;
			while (tab_map_cpy[y][x] && x < len->x)
			{	
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
				if (tab_map_cpy[y][x - 1] == '0' || tab_map_cpy[y][x - 1] == 'C')
				{
					tab_map_cpy[y][x - 1] = '*';
					check = 1;
				}
				if (tab_map_cpy[y][x - 1] == '0' || tab_map_cpy[y][x - 1] == 'C')
				{
					tab_map_cpy[y][x - 1] = '*';
					check = 1;
				}
				x++;
			}
			ft_printf("%s", tab_map_cpy[y]);
			y++;
		}
	}
	return ;
}
