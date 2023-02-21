/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/21 11:18:34 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.floor);
	mlx_destroy_image(data->mlx, data->img.exit);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.rocks);
	free_map(data->tab_map, data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}

int	key_check(int keycode, t_data *data)
{
	if (keycode == quit)
	{
		destroy(data);
		return (0);
	}
	if (keycode == up)
	{
		data->player_diry -= 4;
	}
	if (keycode == down)
	{
		data->player_diry += 4;
	}
	if (keycode == left)
	{
		data->player_dirx -= 4;
	}
	if (keycode == right)
	{
		data->player_dirx += 4;
	}
	return (0);
}

int	key_check2(int keycode, t_data *data)
{
	if (keycode == up)
	{
		data->player_diry += 4;
	}
	if (keycode == down)
	{
		data->player_diry -= 4;
	}
	if (keycode == left)
	{
		data->player_dirx += 4;
	}
	if (keycode == right)
	{
		data->player_dirx -= 4;
	}
	return (0);
}
