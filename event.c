/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/09 17:06:57 by bfaure           ###   ########lyon.fr   */
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

int	key_check_right(int keycode, t_data *data)
{
	int	dis_right;

	dis_right = dis_to_the_right(data->player_x, data->player_y, data);
	if (keycode == right)
	{
		ft_printf("right1\n");
		ft_printf("%i\n", dis_right);
		if (dis_right > 0)
			data->player_x += 4;
		//fill_map(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.player,
		// 	(data->player_x), (data->player_y));
	}
	return (0);
}

int	key_check_up(int keycode, t_data *data)
{
	int	dis_up;

	dis_up = dis_to_the_up(data->player_x, data->player_y, data);
	if (keycode == up)
	{
		ft_printf("up1\n");
		ft_printf("%i\n", dis_up);
		if (dis_up > 32)
			data->player_y -= 4;
		//fill_map(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.player,
		// 	(data->player_x), (data->player_y));
	}
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
		ft_printf("exit\n");
		free_map(data->tab_map, data);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
		return (0);
	}
	if (keycode == up)
	{
		ft_printf("up\n");
		ft_printf("%i\n", dis_up);
		if (dis_up > 32)
			data->player_y -= 4;
		//fill_map(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.player,
		// 	(data->player_x), (data->player_y));
	}
	if (keycode == down)
	{
		ft_printf("down\n");
		ft_printf("%i\n", dis_down);
		if (dis_down > 0)
			data->player_y += 4;
		//fill_map(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.player,
		// 	(data->player_x), (data->player_y));
	}
	if (keycode == left)
	{
		ft_printf("left\n");
		ft_printf("%i\n", dis_left);
		if (dis_left > 32)
			data->player_x -= 4;
		//fill_map(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.player,
		// 	(data->player_x), (data->player_y));
	}
	if (keycode == right)
	{
		ft_printf("right\n");
		ft_printf("%i\n", dis_right);
		if (dis_right > 0)
			data->player_x += 4;
		//fill_map(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.player,
		// 	(data->player_x), (data->player_y));
	}
	/*test for diagonals*/
	// if (keycode == up && keycode == right)
	// {
	// 	ft_printf("up && right\n");
	// 	ft_printf("%i\n", dis_up);
	// 	if (dis_up > 32)
	// 		data->player_y -= 4;
	// 	if (dis_right > 0)
	// 		data->player_x += 4;
	// 	mlx_clear_window(data->mlx, data->win);
	// 	fill_map(data->tab_map, data);
	// 	mlx_put_image_to_window(data->mlx, data->win, data->img.player,
	// 		(data->player_x), (data->player_y));
	// }
	// if (keycode == down)
	// {
	// 	ft_printf("down\n");
	// 	ft_printf("%i\n", dis_down);
	// 	if (dis_down > 0)
	// 		data->player_y += 4;
	// 	mlx_clear_window(data->mlx, data->win);
	// 	fill_map(data->tab_map, data);
	// 	mlx_put_image_to_window(data->mlx, data->win, data->img.player,
	// 		(data->player_x), (data->player_y));
	// }
	// if (keycode == left)
	// {
	// 	ft_printf("left\n");
	// 	ft_printf("%i\n", dis_left);
	// 	if (dis_left > 32)
	// 		data->player_x -= 4;
	// 	mlx_clear_window(data->mlx, data->win);
	// 	fill_map(data->tab_map, data);
	// 	mlx_put_image_to_window(data->mlx, data->win, data->img.player,
	// 		(data->player_x), (data->player_y));
	// }
	// if (keycode == right)
	// {
	// 	ft_printf("right\n");
	// 	ft_printf("%i\n", dis_right);
	// 	if (dis_right > 0)
	// 		data->player_x += 4;
	// 	mlx_clear_window(data->mlx, data->win);
	// 	fill_map(data->tab_map, data);
	// 	mlx_put_image_to_window(data->mlx, data->win, data->img.player,
	// 		(data->player_x), (data->player_y));
	// }
	return (0);
}
