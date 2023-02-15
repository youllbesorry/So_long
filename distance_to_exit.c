/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:50:40 by bfaure            #+#    #+#             */
/*   Updated: 2023/02/15 15:03:45 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	dis_to_the_right_exit(int x_p, int y_p, t_data *data)
{
	int	y_h;
	int	y_f;

	y_f = (32 * ((y_p + 31) / 32));
	y_h = (32 * ((y_p) / 32));
	if (data->tab_map[(y_h / 32)][(x_p / 32) + 1] == 'E')
	{
		if (data->coll == data->characters.c)
		{	
			ft_printf("Congratulation\n");
			destroy(data);
		}
	}
	if (data->tab_map[(y_f / 32)][(x_p / 32) + 1] == 'E')
	{
		if (data->coll == data->characters.c)
		{	
			ft_printf("Congratulation\n");
			destroy(data);
		}
	}
}

void	dis_to_the_left_exit(int x_p, int y_p, t_data *data)
{
	int	y_h;
	int	y_f;

	y_f = (32 * ((y_p + 31) / 32));
	y_h = (32 * ((y_p) / 32));
	if (data->tab_map[(y_h / 32)][(x_p / 32)] == 'E')
	{
		if (data->coll == data->characters.c)
		{	
			ft_printf("Congratulation\n");
			destroy(data);
		}
	}
	if (data->tab_map[(y_f / 32)][(x_p / 32)] == 'E')
	{
		if (data->coll == data->characters.c)
		{	
			ft_printf("Congratulation\n");
			destroy(data);
		}
	}	
}

void	dis_to_the_up_exit(int x_p, int y_p, t_data *data)
{
	int	x_h;
	int	x_f;

	x_f = (32 * ((x_p + 31) / 32));
	x_h = (32 * ((x_p) / 32));
	if (data->tab_map[(y_p / 32)][(x_h / 32)] == 'E')
	{
		if (data->coll == data->characters.c)
		{	
			ft_printf("Congratulation\n");
			destroy(data);
		}
	}
	if (data->tab_map[(y_p / 32)][(x_f / 32)] == 'E')
	{
		if (data->coll == data->characters.c)
		{	
			ft_printf("Congratulation\n");
			destroy(data);
		}
	}
}

void	dis_to_the_down_exit(int x_p, int y_p, t_data *data)
{
	int	x_h;
	int	x_f;

	x_f = (32 * ((x_p + 31) / 32));
	x_h = (32 * ((x_p) / 32));
	if (data->tab_map[(y_p / 32) + 1][(x_h / 32)] == 'E')
	{
		if (data->coll == data->characters.c)
		{	
			ft_printf("Congratulation\n");
			destroy(data);
		}
	}
	if (data->tab_map[(y_p / 32) + 1][(x_f / 32)] == 'E')
	{
		if (data->coll == data->characters.c)
		{
			ft_printf("Congratulation\n");
			destroy(data);
		}
	}
}
