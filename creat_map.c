/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:02:49 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/20 01:30:16 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

char	**creat_tab_map(int fd, t_data *data)
{
	char	*line;
	char	**tab_map;
	size_t	i;

	i = 0;
	tab_map = NULL;
	/* voir pour malloc directement data->tab_map */
	tab_map = malloc(sizeof(char *) * data->len.y + 1);
	ft_printf("sizeof len.y = %i\n", data->len.y + 1);
	if (!tab_map)
		return (NULL);
	while (1)
	{
		ft_printf("i = %i\n", i);
		line = get_next_line(fd);
		if (!line)
			break ;
		tab_map[i] = ft_strdup(line);
		if (!tab_map[i])
			return (free_map(tab_map, data), NULL);
		ft_printf("tab_map[i] = [%s]\n", tab_map[i]);
		free(line);
		i++;
	}
	ft_printf("i = %i\n", i);
	//tab_map[i] = '\0';
	ft_printf("tab_map[i] = [%s]\n", tab_map[i]);
	return (tab_map);
}

int	creat_tab_map_cpy(int fd, t_data *data)
{
	char	*line;
	char	**tab_map_cpy;
	size_t	i;

	i = 0;
	tab_map_cpy = malloc(sizeof(char *) * data->len.y);
	ft_printf("sizeof len.y cpy = %i\n", data->len.y);
	if (!tab_map_cpy)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tab_map_cpy[i] = ft_strdup(line);
		if (!tab_map_cpy[i])
			return (free_map(tab_map_cpy, data), -1);
		free(line);
		i++;
	}
	if (is_closed_map_x(tab_map_cpy, data) == -1
		|| is_closed_map_y(tab_map_cpy, data) == -1
		|| check_char(tab_map_cpy, data))
		return (free_map(tab_map_cpy, data), -1);
	test_map(tab_map_cpy, data);
	return (free_map(tab_map_cpy, data), 1);
}
