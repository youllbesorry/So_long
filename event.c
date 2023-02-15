/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/15 14:41:18 by bfaure           ###   ########lyon.fr   */
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
	if (keycode == quit)
	{
		free_map(data->tab_map, data);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
		return (0);
	}
	if (keycode == up)
	{
		data->player_diry -= 1;
	}
	if (keycode == down)
	{
		data->player_diry += 1;
	}
	if (keycode == left)
	{
		data->player_dirx -= 1;
	}
	if (keycode == right)
	{
		data->player_dirx += 1;
	}
	return (0);
}

int	key_check2(int keycode, t_data *data)
{
	if (keycode == up)
	{
		data->player_diry += 1;
	}
	if (keycode == down)
	{
		data->player_diry -= 1;
	}
	if (keycode == left)
	{
		data->player_dirx += 1;
	}
	if (keycode == right)
	{
		data->player_dirx -= 1;
	}
	return (0);
}
