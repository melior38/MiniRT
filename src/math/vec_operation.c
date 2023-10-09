/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/09 15:00:56 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// // we need to norm the camera vec
// t_ref	set_ref(t_pos *cam_vec)
// {
// 	t_pos	tmp;
// 	t_ref ref;

// 	normed_vec(cam_vec);
// 	if (cam_vec->x || cam_vec->z)
// 		tmp = add_vec(*cam_vec, (t_pos){0,1,0});
// 	else
// 	{
// 		tmp.x = cam_vec->y / vec_norm(*cam_vec);
// 		tmp.y = 0;
// 		tmp.z = 0;
// 	}
// 	ref.x = cross_product(tmp, *cam_vec);
// 	ref.y = cross_product(ref.x, *cam_vec);
// 	ref.z = *cam_vec;
// 	return (ref);
// }

// // faire * x et * y
// void	get_win_scale(t_param *param, int x, int y)
// {
// 	t_pos	center;
// 	t_pos	*cam;
// 	t_pos	tmp;

// 	cam = param->camera->coor;
// 	param->hx = tan(param->camera->fov);
// 	param->hy = (param->hx  * (double)(WIDTH) / (double)(HEIGTH));
// 	param->dir.pixel_size = (param->hx * 2) / (double)(WIDTH);
// 	center = add_vec(*cam, param->ref.z);
// 	param->dir.shift_x = scale_vec(param->ref.x, param->dir.pixel_size);
// 	param->dir.shift_y = scale_vec(param->ref.y, param->dir.pixel_size);
// 	tmp = subs_vec(param->ref.z, add_vec(scale_vec(param->ref.x, \
// 			param->hx), scale_vec(param->ref.y,param->hy)));
// 	param->corner = add_vec(tmp, *cam);
// }

// // return un t_pos mais pour les test va return un int 
// int	pixel_color(t_param *param, t_pos pixel)
// {
// 	(void) param;
// 	printf("pixel.x = {%f} \npixel.y = {%f}\npixel.z = {%f}\n", pixel.x, pixel.y, pixel.z);
// 	if (pixel.z > pixel.y && pixel.z > pixel.x)
// 		return (my_mlx_get_color_value(pixel.z * 50, pixel.z, pixel.z));
// 	else if (pixel.x > pixel.y && pixel.x > pixel.z)
// 		return (my_mlx_get_color_value(pixel.x, pixel.x * 50, pixel.x));
// 	else if (pixel.y > pixel.z && pixel.y > pixel.x)
// 		return (my_mlx_get_color_value(pixel.y, pixel.y, pixel.y * 50));
// 	else 
// 		return (my_mlx_get_color_value(0, 0, 0));
// }

// void	little_main_for_pixel(t_data *data, t_pos pixel, int x, int  y)
// {
// 	int				colour;
// 	t_ref	ref;
// 	t_param			*param;
// 	double			tmp_x;
// 	double			tmp_y;

// 	tmp_x = param->dir->
// 	param = data->param;
// 	ref = set_ref(param->camera->vector);

// 	colour = pixel_color(data->param, pixel);
// 	my_mlx_pixel_put(data, x, y, colour);
// }
// we need to norm the camera vec

t_ref	set_ref(t_pos *cam_vec)
{
	t_pos	tmp;
	t_ref ref;

	normed_vec(cam_vec);
	if (cam_vec->x || cam_vec->z)
		tmp = add_vec(*cam_vec, (t_pos){0,1,0});
	else
	{
		tmp.x = cam_vec->y / vec_norm(*cam_vec);
		tmp.y = 0;
		tmp.z = 0;
	}
	ref.x = cross_product(tmp, *cam_vec);
	ref.y = cross_product(ref.x, *cam_vec);
	ref.z = *cam_vec;
	return (ref);
}

// calcule le vecteur passant par le point x y de notre viewport
t_pos	get_vec_dir(t_param *param, int x, int y)
{
	double	fov_coeff;
	double	win_ratio;
	double	p_x;
	double	p_y;
	t_pos	*cam_pos;

	cam_pos = param->camera->coor;
	fov_coeff = tan(param->camera->fov / 2 * M_PI / 180);
	win_ratio = (double)WIDTH / (double)HEIGTH;
	p_x = (2 * x / (double)WIDTH) * fov_coeff * win_ratio;
	p_y = (1 - 2 * y / (double)HEIGTH) * fov_coeff;
	return (create_vec(p_x, p_y, 1));
}

// pour l'instant cette fonction sert a voir le comportement de nos calculs
int	pixel_color(t_ray ray, t_rgb *pixel, t_sphere *sphere)
{
	t_rgb	color;
	t_rgb	tmp;

	tmp = *pixel;
	color.r = tmp.r;
	color.g = tmp.g;
	color.b = tmp.b;
	if (intersect_sphere(ray, sphere))
		return (my_mlx_get_color_value((int)round(color.r), (int)round(color.g), (int)round(color.b)));
	return (0);
	// printf("red = [%d]\ngreen = [%d]\nblue = [%d]\n", (int)round(color.x), (int)round(color.y), (int)round(color.z));
}
void	init_matrix(t_ref *ref, t_matrix *m)
{
	m->a = ref->x;
	m->b = ref->y;
	m->c = ref->z;
}

t_pos	matrix_vector_multi(t_pos dir, t_matrix m)
{
	t_pos	ret;

	ret.x = dot_product(dir, m.a);
	ret.y = dot_product(dir, m.b);
	ret.z = dot_product(dir, m.c);
	return (ret);
}

t_ray	create_ray(t_pos origin, t_pos dir)
{
	t_ray	res;

	res.dir = dir;
	res.origin = origin;
	return (res);
}

t_ray	init_ray(t_data *data, int x, int y)
{
	t_ref		ref;
	t_matrix	m;
	t_param		*param;
	t_pos		vec_dir;
	t_pos		*cam_vec;

	param = data->param;
	cam_vec = param->camera->coor;
	ref = set_ref(param->camera->vector);
	init_matrix(&ref, &m);
	vec_dir = get_vec_dir(param, x, y);
	matrix_vector_multi(vec_dir, m);
	normed_vec(&vec_dir);
	// printf("vec_dir:\nx = [%f]\ny = [%f]\nz = [%f]\n", vec_dir.x, vec_dir.y, vec_dir.z);
	return (create_ray(*cam_vec, vec_dir));
}
