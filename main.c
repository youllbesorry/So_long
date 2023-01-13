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

int	creat_tab_map(int fd, int len_y)
{
	char	*line;
	char	**tab_map;
	size_t	i;

	i = 0;
	tab_map = malloc(sizeof(char *) * len_y);
	if (!tab_map)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tab_map[i] = ft_strdup(line);
		if (!tab_map[i])
			return (-1);
		ft_printf("%s", tab_map[i]);
		free(line);
		i++;
	}
	if (is_closed_map(tab_map, len_y) == -1)
		return (-1);
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
		//ft_printf("%s", line);
		if (len_error(line) == -1)
			return (free(line), -1);
		free(line);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		len_y;

	fd = 0;
	len_y = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		len_y = check_len_error(fd);
		if (len_y == -1)
			return (close(fd), -1);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		if (creat_tab_map(fd, len_y) == -1)
			return (close(fd), -1);
		close(fd);
	}
	else
	{
		ft_printf("ERROR : you need to pass at leas one maps");
		return (-1);
	}
	return (0);
}
