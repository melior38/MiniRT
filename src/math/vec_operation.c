/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/04 13:37:33 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// // we need to norm the camera vec
// t_referential	set_referential(t_pos *cam_vec)
// {
// 	t_pos	tmp;
// 	t_referential ref;

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
// 	t_referential	ref;
// 	t_param			*param;
// 	double			tmp_x;
// 	double			tmp_y;

// 	tmp_x = param->dir->
// 	param = data->param;
// 	ref = set_referential(param->camera->vector);

// 	colour = pixel_color(data->param, pixel);
// 	my_mlx_pixel_put(data, x, y, colour);
// }
// we need to norm the camera vec

t_referential	set_referential(t_pos *cam_vec)
{
	t_pos	tmp;
	t_referential ref;

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
int	pixel_color(t_param *param, t_pos pixel)
{
	t_pos color;
	(void) param;

	color.x = pixel.x * 200;
	color.y = pixel.y * 200;
	color.z = pixel.z * 200;
	if (color.x < 0)
		color.x = color.x * -1 / 2.0;
	if (color.y < 0)
		color.y = color.y * -1 / 2.0;
	if (color.z < 0)
		color.z = color.z * -1 / 2.0;
	// printf("red = [%d]\ngreen = [%d]\nblue = [%d]\n", (int)round(color.x), (int)round(color.y), (int)round(color.z));
	return (my_mlx_get_color_value((int)round(color.x), (int)round(color.y), (int)round(color.z)));
	// (void) param;
	// printf("pixel.x = {%f} \npixel.y = {%f}\npixel.z = {%f}\n", pixel.x, pixel.y, pixel.z);
	// if (pixel.z > pixel.y && pixel.z > pixel.x)
	// 	return (my_mlx_get_color_value(pixel.z * 50, pixel.z, pixel.z));
	// else if (pixel.x > pixel.y && pixel.x > pixel.z)
	// 	return (my_mlx_get_color_value(pixel.x, pixel.x * 50, pixel.x));
	// else if (pixel.y > pixel.z && pixel.y > pixel.x)
	// 	return (my_mlx_get_color_value(pixel.y, pixel.y, pixel.y * 50));
	// else 
	// 	return (my_mlx_get_color_value(0, 0, 0));
}

void	little_main_for_pixel(t_data *data, int x, int  y)
{
	int				colour;
	t_referential	ref;
	t_param			*param;
	t_pos			vec_dir;

	param = data->param;
	ref = set_referential(param->camera->vector);
	vec_dir = get_vec_dir(param, x, y);
	normed_vec(&vec_dir);
	// printf("vec_dir:\nx = [%f]\ny = [%f]\nz = [%f]\n", vec_dir.x, vec_dir.y, vec_dir.z);
	colour = pixel_color(data->param, vec_dir);
	my_mlx_pixel_put(data, x, y, colour);
}