/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/20 18:16:27 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_ref	set_ref(t_pos cam_vec)
{
	t_pos	tmp;
	t_ref	res;

	if ((cam_vec.x == 0 && cam_vec.y == 1 && cam_vec.z == 0)
		|| (cam_vec.x == 0 && cam_vec.y == -1 && cam_vec.z == 0))
		tmp = (t_pos){.x = 0, .y = 0, .z = 1};
	else
		tmp = (t_pos){.x = 0, .y = 1, .z = 0};
	res.dir = cam_vec;
	res.right = cross_product(cam_vec, tmp);
	normed_vec(&res.right);
	res.up = cross_product(res.right, res.dir);
	normed_vec(&res.up);
	return (res);
}

t_ray	create_ray(t_pos origin, t_pos dir)
{
	t_ray	res;

	res.dir = dir;
	res.origin = origin;
	return (res);
}
