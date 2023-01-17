/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:43 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/17 14:04:01 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_characters
{
	int	p;
	int	c;
	int	e;
}	t_characters;

typedef struct s_len
{
	int	x;
	int	y;
}	t_len;

typedef struct s_gps_parssing
{
	int	x;
	int	y;
}	t_gps_p;

#endif