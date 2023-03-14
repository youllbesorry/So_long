/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:03:28 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/14 13:34:18 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	loop2(t_data *data)
{
	int	dis_left;
	int	dis_right;

	dis_left = dis_to_the_left(data->player_x, data->player_y, data);
	dis_right = dis_to_the_right(data->player_x, data->player_y, data);
	if (dis_left > 32 && data->player_dirx == -data->v_dir)
	{
		dis_to_the_left_coll(data->player_x, data->player_y, data);
		dis_to_the_left_exit(data->player_x, data->player_y, data);
		data->player_x += data->player_dirx;
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
	if (dis_right > 0 && data->player_dirx == data->v_dir)
	{
		dis_to_the_right_coll(data->player_x, data->player_y, data);
		dis_to_the_right_exit(data->player_x, data->player_y, data);
		data->player_x += data->player_dirx;
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
}

int	loop1(t_data *data)
{
	int	dis_up;
	int	dis_down;

	fill_map(data);
	dis_up = dis_to_the_up(data->player_x, data->player_y, data);
	dis_down = dis_to_the_down(data->player_x, data->player_y, data);
	if (dis_up > 32 && data->player_diry == -data->v_dir)
	{
		dis_to_the_up_coll(data->player_x, data->player_y, data);
		dis_to_the_up_exit(data->player_x, data->player_y, data);
		data->player_y += data->player_diry;
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
	if (dis_down > 0 && data->player_diry == data->v_dir)
	{
		dis_to_the_down_coll(data->player_x, data->player_y, data);
		dis_to_the_down_exit(data->player_x, data->player_y, data);
		data->player_y += data->player_diry;
		data->move++;
		ft_printf("move = %i\n", data->move);
	}
	loop2(data);
	return (0);
}
