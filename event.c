/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/27 11:33:12 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	destroy(t_data *data)
{
	free_map(data->tab_map, data);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

int	key_check(int keycode, t_data *data)
{
	int	player_x;
	int	player_y;
	int	dis_up;
	int	dis_down;
	int	dis_left;
	int	dis_right;

	player_x = gps_x_player(data->tab_map, data) * 32;
	player_y = gps_y_player(data->tab_map, data) * 32;
	ft_printf("dis1\n");
	dis_up = dis_to_the_up(player_x, player_y, data);
	ft_printf("dis2\n");
	dis_down = dis_to_the_down(player_x, player_y, data);
	ft_printf("dis3\n");
	dis_left = dis_to_the_left(player_x, player_y, data);
	ft_printf("dis4\n");
	dis_right = dis_to_the_right(player_x, player_y, data);
	if (keycode == quit)
	{
		free_map(data->tab_map, data);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
		return (0);
	}
	if (keycode == up)
	{
		ft_printf("up\n");
		ft_printf("%i\n", dis_up);
		// if (dis_up > 0)
		// 	data->y_p -= 8;
	}
	if (keycode == down)
	{
		ft_printf("down\n");
		ft_printf("%i\n", dis_down);
	}
	if (keycode == left)
	{
		ft_printf("left\n");
		ft_printf("%i\n", dis_left);
	}
	if (keycode == right)
	{
		ft_printf("right\n");
		ft_printf("%i\n", dis_right);
	}
	return (0);
}
