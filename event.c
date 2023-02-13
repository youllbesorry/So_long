/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/11 10:54:44 by bfaure           ###   ########lyon.fr   */
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
	int	dis_up;
	int	dis_down;
	int	dis_left;
	int	dis_right;

	// dis_up = dis_to_the_up(data->player_x, data->player_y, data);
	// dis_down = dis_to_the_down(data->player_x, data->player_y, data);
	// dis_left = dis_to_the_left(data->player_x, data->player_y, data);
	// dis_right = dis_to_the_right(data->player_x, data->player_y, data);
	if (keycode == quit)
	{
		ft_printf("exit\n");
		free_map(data->tab_map, data);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
		return (0);
	}
	if (keycode == up)
	{
		dis_up = dis_to_the_up(data->player_x, data->player_y, data);
		ft_printf("up\n");
		ft_printf("%i\n", dis_up);
		if (dis_up > 32)
			data->player_y -= 4;
		if (data->tab_map[(data->player_y / 32)][(data->player_x / 32)] == 'C')
			data->tab_map[(data->player_y / 32)][(data->player_x / 32)] = '0';
		dis_up = dis_to_the_up(data->player_x, data->player_y, data);
	}
	if (keycode == down)
	{
		dis_down = dis_to_the_down(data->player_x, data->player_y, data);
		ft_printf("down\n");
		ft_printf("%i\n", dis_down);
		if (dis_down > 0)
			data->player_y += 4;
		if (data->tab_map[(data->player_y / 32) + 1][(data->player_x / 32)] == 'C')
			data->tab_map[(data->player_y / 32) + 1][(data->player_x / 32)] = '0';
		dis_down = dis_to_the_down(data->player_x, data->player_y, data);
	}
	if (keycode == left)
	{
		dis_left = dis_to_the_left(data->player_x, data->player_y, data);
		ft_printf("left\n");
		ft_printf("%i\n", dis_left);
		if (dis_left > 32)
			data->player_x -= 4;
		if (data->tab_map[(data->player_y / 32)][(data->player_x / 32)] == 'C')
			data->tab_map[(data->player_y / 32)][(data->player_x / 32)] = '0';
		dis_left = dis_to_the_left(data->player_x, data->player_y, data);
	}
	if (keycode == right)
	{
		ft_printf("start\n");
		dis_right = dis_to_the_right(data->player_x, data->player_y, data);
		ft_printf("right\n");
		ft_printf("%i\n", dis_right);
		if (dis_right > 0)
			data->player_x += 4;
		if (data->tab_map[(data->player_y / 32)][(data->player_x / 32) + 1] == 'C')
			data->tab_map[(data->player_y / 32)][(data->player_x / 32) + 1] = '0';
		dis_right = dis_to_the_right(data->player_x, data->player_y, data);
	}
	return (0);
}
