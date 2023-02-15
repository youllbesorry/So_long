/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:03:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/15 15:04:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	loop(t_data *data)
{
	int	dis_up;
	int	dis_down;
	int	dis_left;
	int	dis_right;

	fill_map(data);
	dis_up = dis_to_the_up(data->player_x, data->player_y, data);
	dis_down = dis_to_the_down(data->player_x, data->player_y, data);
	dis_left = dis_to_the_left(data->player_x, data->player_y, data);
	dis_right = dis_to_the_right(data->player_x, data->player_y, data);
	if (dis_up > 32 && data->player_diry == -1)
	{
		dis_to_the_up_coll(data->player_x, data->player_y, data);
		dis_to_the_up_exit(data->player_x, data->player_y, data);
		data->player_y += data->player_diry;
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
	if (dis_down > 0 && data->player_diry == 1)
	{
		dis_to_the_down_coll(data->player_x, data->player_y, data);
		dis_to_the_down_exit(data->player_x, data->player_y, data);
		data->player_y += data->player_diry;
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
	if (dis_left > 32 && data->player_dirx == -1)
	{
		dis_to_the_left_coll(data->player_x, data->player_y, data);
		dis_to_the_left_exit(data->player_x, data->player_y, data);
		data->player_x += data->player_dirx;
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
	if (dis_right > 0 && data->player_dirx == 1)
	{
		dis_to_the_right_coll(data->player_x, data->player_y, data);
		dis_to_the_right_exit(data->player_x, data->player_y, data);
		data->player_x += data->player_dirx;
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
	return (0);
}
