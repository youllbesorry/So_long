/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_cal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:12:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/14 13:51:51 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	dis_to_the_right(int x_p, int y_p, t_data *data)
{
	int	y_h;
	int	y_f;

	y_f = (32 * ((y_p + 31) / 32));
	y_h = (32 * ((y_p) / 32));
	if (data->tab_map[(y_h / 32)][(x_p / 32) + 1] == '1'
	|| data->tab_map[(y_f / 32)][(x_p / 32) + 1] == '1')
		return (0);
	return ((32 - x_p % 32) + dis_to_the_right((32 + x_p), y_p, data));
}

int	dis_to_the_left(int x_p, int y_p, t_data *data)
{
	int	y_h;
	int	y_f;

	y_f = (32 * ((y_p + 31) / 32));
	y_h = (32 * ((y_p) / 32));
	if (data->tab_map[(y_h / 32)][(x_p / 32)] == '1'
	|| data->tab_map[(y_f / 32)][(x_p / 32)] == '1')
		return (0);
	return ((32 + x_p % 32) + dis_to_the_left((x_p - 32), y_p, data));
}

int	dis_to_the_up(int x_p, int y_p, t_data *data)
{
	int	x_h;
	int	x_f;

	x_f = (32 * ((x_p + 31) / 32));
	x_h = (32 * ((x_p) / 32));
	if (data->tab_map[(y_p / 32)][(x_h / 32)] == '1'
	|| data->tab_map[(y_p / 32)][(x_f / 32)] == '1')
		return (0);
	return ((32 + y_p % 32) + dis_to_the_up(x_p, (y_p - 32), data));
}

int	dis_to_the_down(int x_p, int y_p, t_data *data)
{
	int	x_h;
	int	x_f;

	x_f = (32 * ((x_p + 31) / 32));
	x_h = (32 * ((x_p) / 32));
	if (data->tab_map[(y_p / 32) + 1][(x_h / 32)] == '1'
	|| data->tab_map[(y_p / 32) + 1][(x_f / 32)] == '1')
		return (0);
	return ((32 - y_p % 32) + dis_to_the_down(x_p, (y_p + 32), data));
}
