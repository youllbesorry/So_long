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

int	main(int argc, char **argv)
{
	int		fd;
	char	**tab_map;
	t_data	data;

	fd = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		data.len.y = check_len_error(fd);
		if (data.len.y == 0)
			return (close(fd), ft_printf("ERROR\nempty map\n"), -1);
		if (data.len.y == -1)
			return (close(fd), -1);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		if (creat_tab_map_cpy(fd, &data) == -1)
			return (close(fd), -1);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		tab_map = creat_tab_map(fd, &data);
		data.tab_map = tab_map;
		map_init(&data);
		close(fd);
	}
	else
		return (ft_printf("ERROR\nyou need to pass at leas one maps\n"), -1);
	return (0);
}
