/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/14 13:02:52 by bfaure           ###   ########lyon.fr   */
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

	if (keycode == quit)
	{
		free_map(data->tab_map, data);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
		return (0);
	}
	if (keycode == up)
	{
		dis_up = dis_to_the_up(data->player_x, data->player_y, data);
		if (dis_up > 32)
		{
			data->player_y -= 4;
			data->move++;
			ft_printf("move = %i\n", data->move);
		}
		dis_to_the_up_coll(data->player_x, data->player_y, data);
		dis_to_the_up_exit(data->player_x, data->player_y, data);
		dis_up = dis_to_the_up(data->player_x, data->player_y, data);
	}
	if (keycode == down)
	{
		dis_down = dis_to_the_down(data->player_x, data->player_y, data);
		if (dis_down > 0)
		{
			data->player_y += 4;
			data->move++;
			ft_printf("move = %i\n", data->move);
		}	
		dis_to_the_down_coll(data->player_x, data->player_y, data);
		dis_to_the_down_exit(data->player_x, data->player_y, data);
		dis_down = dis_to_the_down(data->player_x, data->player_y, data);
	}
	if (keycode == left)
	{
		dis_left = dis_to_the_left(data->player_x, data->player_y, data);
		if (dis_left > 32)
		{
			data->player_x -= 4;
			data->move++;
			ft_printf("move = %i\n", data->move);
		}
		dis_to_the_left_coll(data->player_x, data->player_y, data);
		dis_to_the_left_exit(data->player_x, data->player_y, data);
		dis_left = dis_to_the_left(data->player_x, data->player_y, data);
	}
	if (keycode == right)
	{
		dis_right = dis_to_the_right(data->player_x, data->player_y, data);
		if (dis_right > 0)
		{
			data->player_x += 4;
			data->move++;
			ft_printf("move = %i\n", data->move);
		}
		dis_to_the_right_coll(data->player_x, data->player_y, data);
		dis_to_the_right_exit(data->player_x, data->player_y, data);
		dis_right = dis_to_the_right(data->player_x, data->player_y, data);
	}
	return (0);
}
