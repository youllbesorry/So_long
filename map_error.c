/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:00:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/21 11:49:49 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	len_error(char *line)
{
	int			len;
	static int	i = 0;

	len = ft_strlen_line(line);
	if (i == 0)
	{
		i = len;
		return (0);
	}
	if (len != i)
	{
		ft_printf("ERROR\nEvery line have not the same len\n");
		return (free(line), -1);
	}
	else
		return (0);
	return (1);
}

int	is_closed_map_x(char **tab_map_cpy, t_data *data)
{
	int	x;

	x = 0;
	data->len.x = ft_strlen_line(tab_map_cpy[0]) - 1;
	data->len.y -= 1;
	while (tab_map_cpy[0][x] && x < data->len.x + 1)
	{
		if (tab_map_cpy[0][x] != '1')
			return (ft_printf("ERROR\nmap not closed\n"), -1);
		x++;
	}
	x = 0;
	while (tab_map_cpy[data->len.y][x] && x < data->len.x + 1)
	{
		if (tab_map_cpy[data->len.y][x] != '1')
			return (ft_printf("ERROR\nmap not closed\n"), -1);
		x++;
	}
	return (1);
}

int	is_closed_map_y(char **tab_map_cpy, t_data *data)
{
	int	y;

	y = 0;
	data->len.x = ft_strlen_line(tab_map_cpy[0]) - 1;
	while (tab_map_cpy[y][0] && y < data->len.y)
	{
		if (tab_map_cpy[y][0] != '1' && y < data->len.y)
			return (ft_printf("ERROR\nmap not closed\n"), -1);
		y++;
	}
	y = 0;
	while (tab_map_cpy[y][data->len.x] && y < data->len.y)
	{
		if (tab_map_cpy[y][data->len.x] != '1' && y < data->len.y)
			return (ft_printf("ERROR\nmap not closed\n"), -1);
		y++;
	}
	if (find_pce(tab_map_cpy, data) == -1)
		return (-1);
	return (1);
}

int	test_pce(char **tab_map_cpy, t_data *data, t_gps_p *gps_p)
{
	if (tab_map_cpy[gps_p->y][gps_p->x] == 'P')
		data->characters.p++;
	if (data->characters.p > 1)
		return (ft_printf("ERROR\nMore than 1 player finded\n"), -1);
	if (tab_map_cpy[gps_p->y][gps_p->x] == 'C')
		data->characters.c++;
	if (tab_map_cpy[gps_p->y][gps_p->x] == 'E')
		data->characters.e++;
	if (data->characters.e > 1)
		return (ft_printf("ERROR\nMore than 1 exit on the map\n"), -1);
	return (1);
}

int	find_pce(char **tab_map_cpy, t_data *data)
{
	t_gps_p			gps_p;

	data->characters.p = 0;
	data->characters.c = 0;
	data->characters.e = 0;
	gps_p.y = 0;
	while (tab_map_cpy[gps_p.y] && gps_p.y < data->len.y)
	{
		gps_p.x = 0;
		while (tab_map_cpy[gps_p.y][gps_p.x] && gps_p.x++ < data->len.x)
			if (test_pce(tab_map_cpy, data, &gps_p) == -1)
				return (-1);
		gps_p.y++;
	}
	if ((data->characters.p < 1))
		return (ft_printf("ERROR\nPlayer not found\n"), -1);
	if ((data->characters.c < 1))
		return (ft_printf("ERROR\nCollectible not found\n"), -1);
	if ((data->characters.e < 1))
		return (ft_printf("ERROR\nExit not found\n"), -1);
	return (1);
}
