/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:52:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/07 18:15:52 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include <math.h>
# include <mlx.h>

# define HEIGTH	768 .0
# define WIDTH 1366.0

typedef struct s_axis {
	float	x;
	float	y;
	float	z;
}				t_axis;

typedef struct s_rgb {
	float	r;
	float	g;
	float	b;
}				t_rgb;

typedef struct s_sphere {
	t_axis	center;
	float	radius;
	t_rgb	colour;
}				t_sphere;

typedef struct s_plan {
	t_axis	coor;
	float	vector;
	
	
}				t_plan;

typedef struct s_param {
	// t_sphere *sp_tab;
	t_axis	axe;
	t_plan	plan;


	
	
}				t_param;

typedef struct s_data {
	void		*img;
	char		*addr;
	void		*mlx;
	void		*mlx_win;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_param		*param;
	
}				t_data;
//////////////////////////////////// MAIN.C ////////////////////////////////////

int			main(int ac, char **av);

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// parsing ///////////////////////////////////
//////////////////////////////////// folder ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



#endif