/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:00:05 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/13 18:36:30 by bfaure           ###   ########lyon.fr   */
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

int	is_closed_map(char **tab_map, int len_y)
{
	int	x;
	int	y;
	int	len_x;

	x = 0;
	len_x = ft_strlen_line(tab_map[0]);
	while (tab_map[0][x] && x < len_x)
	{
		if (tab_map[0][x] != '1')
		{
			ft_printf("\nERROR : map not closed 1.1");
			return (-1);
		}
		x++;
	}
	x = 0;
	while (tab_map[len_y][x] && x < len_x)
	{
		ft_printf("\nx = %i", x);
		ft_printf("\nlen_y = %i", len_y);
		ft_printf("\ntab_map[len_y][x] = %c", tab_map[len_y][x]);
		if (tab_map[len_y][x] != '1')
		{
			ft_printf("\nERROR : map not closed 1.2");
			return (-1);
		}
		x++;
	}
	x = 0;
	y = 0;
	while (tab_map[y][0])
	{
		if (tab_map[y][0] != '1' && y < len_y)
		{
			ft_printf("\nERROR : map not closed 2.1");
			return (-1);
		}
		y++;
	}
	y = 0;
	while (tab_map[y][len_x])
	{
		if (tab_map[y][len_x] != '1' && y < len_y)
		{
			ft_printf("\nERROR : map not closed 2.2");
			return (-1);
		}
		y++;
	}
	return (1);
}
