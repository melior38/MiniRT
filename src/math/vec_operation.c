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
	{
		tmp.x = 0;
		tmp.y = 0;
		tmp.z = 1;
	}
	else
	{
		tmp.x = 0;
		tmp.y = 1;
		tmp.z = 0;
	}
	res.dir = cam_vec;
	res.right = cross_product(cam_vec, tmp);
	normed_vec(&res.right);
	res.up = cross_product(res.right, res.dir);
	normed_vec(&res.up);
	// t_pos	tmp;
	// t_ref	res;

	// if (cam_vec.x || cam_vec.z)
	// 	tmp = add_vec(cam_vec, (t_pos){0, 1, 0});
	// else
	// {
	// 	tmp.x = cam_vec.y / vec_norm(cam_vec);
	// 	tmp.y = 0;
	// 	tmp.z = 0;
	// }
	// res.right = cross_product(tmp, cam_vec);
	// res.up = cross_product(cam_vec, res.right);
	// res.dir = cam_vec;
	// normed_vec(&res.right);
	// normed_vec(&res.up);
	return (res);
}

t_ray	create_ray(t_pos origin, t_pos dir)
{
	t_ray	res;

	res.dir = dir;
	res.origin = origin;
	return (res);
}

// calcule le vecteur passant par le point x y de notre viewport
void	init_ray(t_data *data, int x, int y, t_ray *res)
{
	double		u;
	double		v;
	t_pos		pixel_pos;
	t_camera	*cam;

	cam = data->param->camera;
	u = (double)x / (double)WIDTH;
	v = (double)y / (double)HEIGTH;
	pixel_pos = add_vec(cam->up_left, subs_vec(scale_vec(cam->ref.right, u * \
			 cam->width), scale_vec(cam->ref.up, cam->heigth * v)));
	res->dir = subs_vec(pixel_pos, cam->coor);
	normed_vec(&res->dir);
}

t_inter	update_intersection(t_param *param, t_inter *p, t_ray ray)
{
	t_inter ret;

	ret.a_mod_color = change_intensity(param->alight->rgb, param->alight->ratio);
	ret.inter_point = add_vec(ray.origin, scale_vec(ray.dir, p->dist));
	// printf("\nret.inter_point.x = [%f]\n", ret.inter_point.x);
	// printf("ret.inter_point.y = [%f]\n", ret.inter_point.y);
	// printf("ret.inter_point.z = [%f]\n", ret.inter_point.z);
	ret.light_bright = param->light->bright;
	ret.light_color = param->light->rgb;
	ret.light_pos = param->light->coor;
	return (ret);
}
