/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:09:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/12 10:09:27 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

char	**creat_tab_map(int fd, t_len *len)
{
	char	*line;
	char	**tab_map;
	size_t	i;

	i = 0;
	tab_map = malloc(sizeof(char *) * len->y);
	if (!tab_map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tab_map[i] = ft_strdup(line);
		if (!tab_map[i])
			return (free_map(tab_map, len), NULL);
		ft_printf("%s", tab_map[i]);
		free(line);
		i++;
	}
	return (tab_map);
}

int	creat_tab_map_cpy(int fd, t_len *len)
{
	char	*line;
	char	**tab_map_cpy;
	size_t	i;

	i = 0;
	tab_map_cpy = malloc(sizeof(char *) * len->y);
	if (!tab_map_cpy)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tab_map_cpy[i] = ft_strdup(line);
		if (!tab_map_cpy[i])
			return (free_map(tab_map_cpy, len), -1);
		ft_printf("%s", tab_map_cpy[i]);
		free(line);
		i++;
	}
	if (is_closed_map_x(tab_map_cpy, len) == -1
		|| is_closed_map_y(tab_map_cpy, len) == -1)
		return (-1);
	free_map(tab_map_cpy, len);
	return (1);
}

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

int	main(int argc, char **argv)
{
	int		fd;
	t_len	len;

	fd = 0;
	len.y = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		len.y = check_len_error(fd);
		if (len.y == 0)
			return (close(fd), ft_printf("ERROR : empty map"), -1);
		if (len.y == -1)
			return (close(fd), -1);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		if (creat_tab_map_cpy(fd, &len) == -1)
			return (close(fd), -1);
		close(fd);
	}
	else
		return (ft_printf("ERROR : you need to pass at leas one maps"), -1);
	return (0);
}
