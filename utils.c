/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:04:19 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/19 12:55:05 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	check_len_error(int fd)
{
	char	*line;
	size_t	i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (len_error(line) == -1)
			return (-1);
		free(line);
		i++;
	}
	return (i);
}

int	free_map(char **tab_map, t_len *len)
{
	int	i;

	i = 0;
	while (i < len->y + 1)
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
