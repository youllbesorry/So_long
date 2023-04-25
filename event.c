/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/20 13:00:59 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	destroy(t_data *data)
{
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);
	if (data->img.rocks)
		mlx_destroy_image(data->mlx, data->img.rocks);
	if (data->tab_map)
		free_map(data->tab_map, data);
	if (data->mlx)
		mlx_do_key_autorepeaton(data->mlx);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	exit (0);
}

int	key_check(int keycode, t_data *data)
{
	if (keycode == quit)
		destroy(data);
	if (keycode == up)
		data->player_diry -= data->v_dir;
	if (keycode == down)
		data->player_diry += data->v_dir;
	if (keycode == left)
		data->player_dirx -= data->v_dir;
	if (keycode == right)
		data->player_dirx += data->v_dir;
	return (0);
}

int	key_check2(int keycode, t_data *data)
{
	if (keycode == up)
		data->player_diry += data->v_dir;
	if (keycode == down)
		data->player_diry -= data->v_dir;
	if (keycode == left)
		data->player_dirx += data->v_dir;
	if (keycode == right)
		data->player_dirx -= data->v_dir;
	return (0);
}
