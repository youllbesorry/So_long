/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:00:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/16 15:44:03 by bfaure           ###   ########lyon.fr   */
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
		return (-1);
	}
	else
		return (0);
	return (1);
}

int	is_closed_map_x(char **tab_map, int len_y)
{
	int	x;
	int	len_x;

	x = 0;
	len_x = ft_strlen_line(tab_map[0]) - 1;
	len_y -= 1;
	while (tab_map[0][x] && x < len_x)
	{
		if (tab_map[0][x] != '1')
			return (ft_printf("\nERROR : map not closed 1.1"), -1);
		x++;
	}
	x = 0;
	while (tab_map[len_y][x] && x < len_x)
	{
		if (tab_map[len_y][x] != '1')
			return (ft_printf("\nERROR : map not closed 1.2"), -1);
		x++;
	}
	return (1);
}

int	is_closed_map_y(char **tab_map, int len_y)
{
	int	y;
	int	len_x;

	y = 0;
	len_x = ft_strlen_line(tab_map[0]) - 1;
	len_y -= 1;
	while (tab_map[y][0] && y < len_y)
	{
		if (tab_map[y][0] != '1' && y < len_y)
			return (ft_printf("\nERROR : map not closed 2.1"), -1);
		y++;
	}
	y = 0;
	while (tab_map[y][len_x] && y < len_y)
	{
		if (tab_map[y][len_x] != '1' && y < len_y)
			return (ft_printf("\nERROR : map not closed 2.2"), -1);
		y++;
	}
	if (find_pce(tab_map, len_x, len_y) == -1)
		return (-1);
	return (1);
}

int	test_pce(char **tab_map, t_characters *characters, int x, int y)
{
	if (tab_map[y][x] == 'P')
		characters->p++;
	if (characters->p > 1)
		return (ft_printf("\nERROR : more than 1 player finded"), -1);
	if (tab_map[y][x] == 'C')
		characters->c++;
	if (tab_map[y][x] == 'E')
		characters->e++;
	if (characters->e > 1)
		return (ft_printf("\nERROR : more than 1 exit on the map"), -1);
	return (1);
}

int	find_pce(char **tab_map, int len_x, int len_y)
{
	int				x;
	int				y;
	t_characters	characters;

	characters.p = 0;
	characters.c = 0;
	characters.e = 0;
	y = 0;
	while (tab_map[y] && y < len_y)
	{
		x = 0;
		while (tab_map[y][x] && x++ < len_x)
			if (test_pce(tab_map, &characters, x, y) == -1)
				return (-1);
		y++;
	}
	if ((characters.p < 1))
		return (ft_printf("\nERROR : player not found"), -1);
	if ((characters.c < 1))
		return (ft_printf("\nERROR : collectible not found"), -1);
	if ((characters.e < 1))
		return (ft_printf("\nERROR : exit not found"), -1);
	return (1);
}
