/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:02:49 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/17 12:03:35 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	**creat_tab_map(int fd, t_data *data)
{
	char	*line;
	size_t	i;

	i = 0;
	line = NULL;
	data->len.y += 2;
	data->tab_map = malloc(sizeof(char *) * data->len.y);
	if (!data->tab_map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->tab_map[i] = ft_strdup(line);
		if (!data->tab_map[i])
			return (free_map(data->tab_map, data), NULL);
		free(line);
		i++;
	}
	data->tab_map[i] = ft_strdup("\0");
	return ((void **)data->tab_map);
}

int	creat_tab_map_cpy(int fd, t_data *data)
{
	char	*line;
	char	**tab_map_cpy;
	size_t	i;

	i = 0;
	tab_map_cpy = malloc(sizeof(char *) * data->len.y);
	if (!tab_map_cpy)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tab_map_cpy[i] = ft_strdup(line);
		if (!tab_map_cpy[i])
			return (free_map_cpy(tab_map_cpy, data), -1);
		free(line);
		i++;
	}
	if (is_closed_map_x(tab_map_cpy, data) == -1
		|| is_closed_map_y(tab_map_cpy, data) == -1
		|| check_char(tab_map_cpy, data) == -1
		|| test_map(tab_map_cpy, data) == -1)
		return (free_map_cpy(tab_map_cpy, data), -1);
	return (free_map_cpy(tab_map_cpy, data), 1);
}
