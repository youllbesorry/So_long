/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/27 13:35:01 by bfaure           ###   ########lyon.fr   */
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

	dis_up = dis_to_the_up(data->player_x, data->player_y, data);
	dis_down = dis_to_the_down(data->player_x, data->player_y, data);
	dis_left = dis_to_the_left(data->player_x, data->player_y, data);
	dis_right = dis_to_the_right(data->player_x, data->player_y, data);
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
		if (dis_up > 0)
			data->player_y -= 8;
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			(data->player_x), (data->player_y));
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
