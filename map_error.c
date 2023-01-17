/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:00:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/17 15:14:06 by bfaure           ###   ########lyon.fr   */
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
		ft_printf("\nERROR : Every line have not the same len\n");
		return (free(line), -1);
	}
	else
		return (0);
	return (1);
}

int	is_closed_map_x(char **tab_map, t_len *len)
{
	int	x;

	x = 0;
	len->x = ft_strlen_line(tab_map[0]) - 1;
	len->y -= 1;
	while (tab_map[0][x] && x < len->x)
	{
		if (tab_map[0][x] != '1')
			return (ft_printf("\nERROR : map not closed 1.1"),
				free_map(tab_map, len));
		x++;
	}
	x = 0;
	while (tab_map[len->y][x] && x < len->x)
	{
		if (tab_map[len->y][x] != '1')
			return (ft_printf("\nERROR : map not closed 1.2"),
				free_map(tab_map, len));
		x++;
	}
	return (1);
}

int	is_closed_map_y(char **tab_map, t_len *len)
{
	int	y;

	y = 0;
	len->x = ft_strlen_line(tab_map[0]) - 1;
	len->y -= 1;
	while (tab_map[y][0] && y < len->y)
	{
		if (tab_map[y][0] != '1' && y < len->y)
			return (ft_printf("\nERROR : map not closed 2.1"),
				free_map(tab_map, len));
		y++;
	}
	y = 0;
	while (tab_map[y][len->x] && y < len->y)
	{
		if (tab_map[y][len->x] != '1' && y < len->y)
			return (ft_printf("\nERROR : map not closed 2.2"),
				free_map(tab_map, len));
		y++;
	}
	if (find_pce(tab_map, len) == -1)
		return (-1);
	return (1);
}

int	test_pce(char **tab_map, t_characters *characters,
	t_gps_p *gps_p, t_len *len)
{
	if (tab_map[gps_p->y][gps_p->x] == 'P')
		characters->p++;
	if (characters->p > 1)
		return (ft_printf("\nERROR : more than 1 player finded"),
			free_map(tab_map, len));
	if (tab_map[gps_p->y][gps_p->x] == 'C')
		characters->c++;
	if (tab_map[gps_p->y][gps_p->x] == 'E')
		characters->e++;
	if (characters->e > 1)
		return (ft_printf("\nERROR : more than 1 exit on the map"),
			free_map(tab_map, len));
	return (1);
}

int	find_pce(char **tab_map, t_len *len)
{
	t_gps_p			gps_p;
	t_characters	characters;

	characters.p = 0;
	characters.c = 0;
	characters.e = 0;
	gps_p.y = 0;
	while (tab_map[gps_p.y] && gps_p.y < len->y + 1)
	{
		gps_p.x = 0;
		while (tab_map[gps_p.y][gps_p.x] && gps_p.x++ < len->x)
			if (test_pce(tab_map, &characters, &gps_p, len) == -1)
				return (-1);
		gps_p.y++;
	}
	if ((characters.p < 1))
		return (ft_printf("\nERROR : player not found"),
			free_map(tab_map, len));
	if ((characters.c < 1))
		return (ft_printf("\nERROR : collectible not found"),
			free_map(tab_map, len));
	if ((characters.e < 1))
		return (ft_printf("\nERROR : exit not found"),
			free_map(tab_map, len));
	return (1);
}
