/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/11 13:49:22 by asouchet         ###   ########.fr       */
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
			// 	printf("x = [%f]\n", cam->up_left.x);
			// printf("y = [%f]\n", cam->up_left.y);
			// printf("z = [%f]\n", cam->up_left.z);
			// printf("\n\n\n");
	pixel_pos = add_vec(cam->up_left, subs_vec(scale_vec(cam->ref.right, u * \
			 cam->width), scale_vec(cam->ref.up, cam->heigth * v)));
			// printf("p_x = [%f]\n", pixel_pos.x);
			// printf("p_y = [%f]\n", pixel_pos.y);
			// printf("p_z = [%f]\n", pixel_pos.z);
			// printf("\n\n\n");
	res->dir = subs_vec(pixel_pos, cam->coor);
	normed_vec(&res->dir);
}

// pour l'instant cette fonction sert a voir le comportement de nos calculs
int	pixel_color(t_ray ray, t_rgb rgb, t_sphere *sphere)
{
	double	t;
	int	tmp;

	tmp = intersect_sphere(ray, sphere, &t);
	if (t && tmp)
		return (my_mlx_get_color_value((int)round(rgb.r), (int)round(rgb.g), (int)round(rgb.b)));
	return (0);
	// printf("red = [%d]\ngreen = [%d]\nblue = [%d]\n", (int)round(color.x), (int)round(color.y), (int)round(color.z));
}
// void	init_matrix(t_ref *ref, t_matrix *m)
// {
// 	m->a = ref->x;
// 	m->b = ref->y;
// 	m->c = ref->z;
// }

// t_pos	matrix_vector_multi(t_pos dir, t_matrix m)
// {
// 	t_pos	ret;

// 	ret.x = dot_product(dir, m.a);
// 	ret.y = dot_product(dir, m.b);
// 	ret.z = dot_product(dir, m.c);
// 	return (ret);
// }

// t_ray	init_ray(t_data *data, int x, int y)
// {
// 	t_ref		ref;
// 	t_matrix	m;
// 	t_param		*param;
// 	t_pos		vec_dir;
// 	t_pos		*cam_vec;

// 	param = data->param;
// 	cam_vec = param->camera->coor;
// 	ref = set_ref(param->camera->vector);
// 	init_matrix(&ref, &m);
// 	vec_dir = get_vec_dir(param, x, y);
// 	matrix_vector_multi(vec_dir, m);
// 	normed_vec(&vec_dir);
// 	// printf("vec_dir:\nx = [%f]\ny = [%f]\nz = [%f]\n", vec_dir.x, vec_dir.y, vec_dir.z);
// 	return (create_ray(*cam_vec, vec_dir));
// }
