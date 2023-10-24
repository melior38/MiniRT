/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:57:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/20 16:20:52 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

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
	t_inter	ret;

	ret.a_mod_color = change_intensity(param->alight->rgb,
			param->alight->ratio);
	ret.inter_point = add_vec(ray.origin, scale_vec(ray.dir, p->dist));
	ret.light_bright = param->light->bright;
	ret.light_color = param->light->rgb;
	ret.light_pos = param->light->coor;
	return (ret);
}

// le scaling d'un vecteur
t_pos	scale_vec(t_pos vec, double scaling)
{
	t_pos	res;

	res.x = vec.x * scaling;
	res.y = vec.y * scaling;
	res.z = vec.z * scaling;
	return (res);
}

t_pos	create_vec(double x, double y, double z)
{
	t_pos	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double	dot_product(t_pos vec1, t_pos vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}
