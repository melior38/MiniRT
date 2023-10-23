/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/19 16:51:31 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_ref	set_ref(t_pos cam_vec)
{
	// t_pos	tmp;
	// t_ref	res;

	// if ((cam_vec.x == 0 && cam_vec.y == 1 && cam_vec.z == 0)
	// 	|| (cam_vec.x == 0 && cam_vec.y == -1 && cam_vec.z == 0))
	// {
	// 	tmp.x = 0;
	// 	tmp.y = 0;
	// 	tmp.z = 1;
	// }
	// else
	// {
	// 	tmp.x = 0;
	// 	tmp.y = 1;
	// 	tmp.z = 0;
	// }
	// res.dir = cam_vec;
	// res.right = cross_product(cam_vec, tmp);
	// normed_vec(&res.right);
	// res.up = cross_product(res.right, res.dir);
	// normed_vec(&res.up);
	t_pos	tmp;
	t_ref	res;

	if (cam_vec.x || cam_vec.z)
		tmp = add_vec(cam_vec, (t_pos){0, 1, 0});
	else
	{
		tmp.x = cam_vec.y / vec_norm(cam_vec);
		tmp.y = 0;
		tmp.z = 0;
	}
	res.right = cross_product(tmp, cam_vec);
	res.up = cross_product(cam_vec, res.right);
	res.dir = cam_vec;
	normed_vec(&res.right);
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

void	update_intersection(t_param *param, t_intersection *p, t_pos obj_center, t_ray ray)
{
	(void)	obj_center;
	p->a_mod_color = change_intensity(param->alight->rgb, param->alight->ratio);
	p->inter_point = add_vec(ray.origin, scale_vec(ray.dir, p->dist));
	p->light_bright = param->light->bright;
	p->light_color = param->light->rgb;
	p->light_pos = param->light->coor;
}


// // pour l'instant cette fonction sert a voir le comportement de nos calculs
// int	pixel_color_sphere(t_ray ray, t_sphere *sphere, t_alight *A)
// {
// 	t_rgb	rgb;
// 	double	t;

// 	rgb = sphere->rgb;
// 	if (intersect_sphere(ray, sphere, &t))
// 		return (my_mlx_get_color_value((int)round(rgb.r), (int)round(rgb.g), (int)round(rgb.b)));
// 	else
// 		return (my_mlx_get_color_value(A->rgb.r, A->rgb.g, A->rgb.b));
// 	return (0);
// }

// int	pixel_color_cylinder(t_ray ray, t_cylinder *cylinder, t_alight *A)
// {
// 	t_rgb	rgb;
// 	double	t;

// 	rgb = cylinder->rgb;
// 	if (intersect_cylinder(ray, cylinder, &t))
// 		return (my_mlx_get_color_value((int)round(rgb.r), (int)round(rgb.g), (int)round(rgb.b)));
// 	else
// 		return (my_mlx_get_color_value(A->rgb.r, A->rgb.g, A->rgb.b));
// 	return (0);
// }

// int	pixel_color_plane(t_ray ray, t_plane *plane, t_alight *A)
// {
// 	t_rgb	rgb;
// 	double	t;

// 	rgb = plane->rgb;
// 	if (intersect_plane(ray, plane, &t))
// 		return (my_mlx_get_color_value((int)round(rgb.r), (int)round(rgb.g), (int)round(rgb.b)));
// 	else
// 		return (my_mlx_get_color_value(A->rgb.r, A->rgb.g, A->rgb.b));
// 	return (0);
// }
