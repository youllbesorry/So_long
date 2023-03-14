/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:43 by bfaure            #+#    #+#             */
/*   Updated: 2023/03/14 12:12:40 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	up = 119,
	down = 115,
	left = 97,
	right = 100,
	quit = 65307
};

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

typedef struct s_gps_parsing
{
	int	x;
	int	y;
}	t_gps_p;

typedef struct s_image
{
	void	*floor;
	void	*exit;
	void	*rocks;
	void	*wall;
	void	*player;
}	t_img;

typedef struct s_data
{
	int				player_x;
	int				player_y;
	int				player_diry;
	int				player_dirx;
	int				img_width;
	int				img_height;
	int				coll;
	int				move;
	int				v_dir;
	char			**tab_map;
	void			*mlx;
	void			*win;
	t_img			img;
	t_len			len;
	t_characters	characters;
}	t_data;

#endif