/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/26 15:58:07 by bfaure           ###   ########lyon.fr   */
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
	int	x_p;
	int	y_p;
	int	dis_up;
	int	dis_down;
	int	dis_left;
	int	dis_right;

	x_p = gps_x_player(data->tab_map, data) * 32;
	y_p = gps_y_player(data->tab_map, data) * 32;
	dis_up = dis_to_the_up(x_p, y_p, data);
	dis_down = dis_to_the_down(x_p, y_p, data);
	dis_left = dis_to_the_left(x_p, y_p, data);
	dis_right = dis_to_the_right(x_p, y_p, data);
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
