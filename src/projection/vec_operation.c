/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/23 15:08:56 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

typedef struct s_referential {
	t_axis	x;
	t_axis	y;
	t_axis	z;
}				t_referential;

typedef struct s_corner {
	t_axis	C_left_up;
	t_axis	C_left_down;
	t_axis	C_right_up;
	t_axis	C_right_down;
}				t_corner;

typedef struct s_scale {
	double	hx;
	double	hy;
}				t_scale;

// we need to norm the camera vec
t_referential	set_referential(t_axis cam_vec, t_referential ref)
{
	t_axis	tmp;

	if (cam_vec.x || cam_vec.z)
		tmp = add_vec(tmp, (t_axis){0,1,0});
	else
	{
		tmp.x = cam_vec.y / vector_norm(cam_vec);
		tmp.y = 0;
		tmp.z = 0;
	}
	ref.x = cross_product(tmp, cam_vec);
	ref.y = cross_product(ref.x, cam_vec);
	ref.z = cam_vec;
}

t_axis	get_W_center(t_axis cam_coor, t_referential ref)
{
	return (add_vec(cam_coor, ref.z));
}

t_corner get_corner(t_param *param, t_referential ref)
{
	t_axis win_center;
	t_scale sca;// a rajouter dans param potentiellement
	t_corner	corner;

	sca.hx = 3.0;
	sca.hy = 2.0;
	win_center = get_W_center(param->camera->center_coor, ref);
	corner.C_left_up = add_vec(scale_vec(ref.x, (sca.hx / 2.0)), scale_vec(ref.y, sca.hy / 2.0));
	corner.C_right_up = add_vec(corner.C_left_up, scale_vec(ref.x, sca.hx * -1.0));
	corner.C_left_down = add_vec(corner.C_left_up, scale_vec(ref.y, sca.hy * -1.0));
	corner.C_right_down = add_vec(corner.C_left_down, scale_vec(ref.x, sca.hx));
	return (corner);
}