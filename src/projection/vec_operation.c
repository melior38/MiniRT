/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/25 13:56:37 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// typedef struct s_referential {
// 	t_axis	x;
// 	t_axis	y;
// 	t_axis	z;
// }				t_referential;

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

t_axis	get_win_center(t_axis cam_coor, t_referential ref)
{
	return (add_vec(cam_coor, ref.z));
}

// determine hx and hy
void set_hor_n_ver(t_param *param, int fov)
{
	param->hy = tan((double)fov) * 1;
	param->hx = (param->hy / 9.0) * 16;
}


