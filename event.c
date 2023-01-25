/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:26:33 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/25 19:14:14 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

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
		ft_printf("up");
	if (keycode == down)
		ft_printf("down");
	if (keycode == left)
		ft_printf("left");
	if (keycode == right)
		ft_printf("right");
	return (0);
}
