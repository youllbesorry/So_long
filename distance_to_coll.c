/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_coll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:22:18 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/13 17:21:42 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	dis_to_the_right_coll(int x_p, int y_p, t_data *data)
{
	int	y_h;
	int	y_f;

	y_f = (32 * ((y_p + 31) / 32));
	y_h = (32 * ((y_p) / 32));
	if (data->tab_map[(y_h / 32)][(x_p / 32) + 1] == 'C')
	{
		data->tab_map[(y_h / 32)][(x_p / 32) + 1] = '0';
		data->coll++;
	}
	if (data->tab_map[(y_f / 32)][(x_p / 32) + 1] == 'C')
	{
		data->tab_map[(y_f / 32)][(x_p / 32) + 1] = '0';
		data->coll++;
	}
}

void	dis_to_the_left_coll(int x_p, int y_p, t_data *data)
{
	int	y_h;
	int	y_f;

	y_f = (32 * ((y_p + 31) / 32));
	y_h = (32 * ((y_p) / 32));
	if (data->tab_map[(y_h / 32)][(x_p / 32)] == 'C')
	{
		data->tab_map[(y_h / 32)][(x_p / 32)] = '0';
		data->coll++;
	}
	if (data->tab_map[(y_f / 32)][(x_p / 32)] == 'C')
	{
		data->tab_map[(y_f / 32)][(x_p / 32)] = '0';
		data->coll++;
	}	
}

void	dis_to_the_up_coll(int x_p, int y_p, t_data *data)
{
	int	x_h;
	int	x_f;

	x_f = (32 * ((x_p + 31) / 32));
	x_h = (32 * ((x_p) / 32));
	if (data->tab_map[(y_p / 32)][(x_h / 32)] == 'C')
	{
		data->tab_map[(y_p / 32)][(x_h / 32)] = '0';
		data->coll++;
	}
	if (data->tab_map[(y_p / 32)][(x_f / 32)] == 'C')
	{
		data->tab_map[(y_p / 32)][(x_f / 32)] = '0';
		data->coll++;
	}
}

void	dis_to_the_down_coll(int x_p, int y_p, t_data *data)
{
	int	x_h;
	int	x_f;

	x_f = (32 * ((x_p + 31) / 32));
	x_h = (32 * ((x_p) / 32));
	if (data->tab_map[(y_p / 32) + 1][(x_h / 32)] == 'C')
	{
		data->tab_map[(y_p / 32) + 1][(x_h / 32)] = '0';
		data->coll++;
	}
	if (data->tab_map[(y_p / 32) + 1][(x_f / 32)] == 'C')
	{
		data->tab_map[(y_p / 32) + 1][(x_f / 32)] = '0';
		data->coll++;
	}
}
