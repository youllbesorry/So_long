/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:42:54 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/17 14:23:56 by bfaure           ###   ########lyon.fr   */
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
	size_t	x;
	size_t	y;

	return (1);
}

void	test_map(char **tab_map_cpy, t_len *len)
{
	return ;
}
