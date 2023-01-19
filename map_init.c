/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:51:38 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/19 15:06:11 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	map_init(char **tab_map)
{
	void	*mlx;
	void	*win;

	(void) tab_map;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 360, "So long");
	mlx_loop(mlx);
	return (0);
}
