/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/27 09:43:28 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// we need to norm the camera vec
t_referential	set_referential(t_axis *cam_ve)
{
	(void) cam_ve;
	t_axis cam_vec = {0,0,1};
	t_axis	tmp;
	t_referential ref;

	if (cam_vec.x || cam_vec.z)
		tmp = add_vec(cam_vec, (t_axis){0,1,0});
	else
	{
		tmp.x = cam_vec.y / vec_norm(cam_vec);
		tmp.y = 0;
		tmp.z = 0;
	}
	ref.x = cross_product(tmp, cam_vec);
	ref.y = cross_product(ref.x, cam_vec);
	ref.z = cam_vec;
	return (ref);
}

// t_axis	get_W_center(t_axis cam_coor, t_referential ref)
// {
// 	return (add_vec(cam_coor, ref.z));
// }

// void	get_win_scale(t_param *para, double fov)
// {
// 	param->hx = tan(fov / 2) * 1;
// 	param->hy = (param->hx / (WIDTH - 1.0)) * (HEIGTH - 1.0);
// }

// return un t_axis mais pour les test va return un int 
int	shifting_pixel(t_param *param, int x, int y, t_referential ref)
{
	(void)	param;
	t_vec_dir	ret;
	t_axis	res;
	double	hx;
	double	hy;
	double	fov = 110.0;
	t_vec_dir	vec;

 	hx = tan(fov / 2) * 1;
	hy = (hx / (WIDTH)) * (HEIGTH);
	vec.qx = scale_vec(ref.x, (hx * 2.0) / (double)x);
	vec.qy = scale_vec(ref.y, (hy * 2.0) / (double)y);

	ret.qx = scale_vec(vec.qx, x / 16);
	ret.qy = scale_vec(vec.qy, y / 9);
	res = add_vec(vec.qx, vec.qy);
	// param->vec.qx = scale_vec(param->ref.x, (param->hx * 2.0) / WIDTH);
	// param->vec.qy = scale_vec(param->ref.y, (param->hy * 2.0) / HEIGTH);

	// ret.qx = scale_vec(param->vec.qx, x);
	// ret.qy = scale_vec(param->vec.qy, y);
	// res = add_vec(param->vec.qx, param->vec.qy);
	int tmp1 = (int)res.x;
	int tmp2 = (int)res.y;
	int tmp3 = (int)res.z;

	printf("res.x = {%f} \nres.y = {%f}\nres.z = {%f}\n", res.x, res.y, res.z);
	tmp1 = tmp1 / 10;
	tmp2 = tmp2 / 10;
	tmp3 = tmp3 / 10;
	if (res.z > res.y && res.z > res.x)
		return (my_mlx_get_color_value(0, 0, tmp3 * 200));
	else if (res.x > res.y && res.x > res.z)
		return (my_mlx_get_color_value(tmp1 * 200, 0, 0));
	else if (res.y > res.z && res.y > res.x)
		return (my_mlx_get_color_value(0, 200 * tmp2, 0));
	else 
		return (my_mlx_get_color_value(0, 0, 0));
	return (0);
}

void	little_main_for_pixel(t_data *data, int x, int y)
{
	int colour;
	t_referential ref;
	t_axis	test = {0,1,0};
	t_param *param = NULL;

	// printf("x = {%d}\ny = {%d}\n", x, y);
	ref = set_referential(&test);
	// get_win_scale((double)camera->fov);
	colour = shifting_pixel(param, x, y, ref);
	// data->param->ref = set_referential(data->param->camera->vector);
	// get_win_scale(data->param, (double)data->param->camera->fov);
	// colour = shifting_pixel(data->param, x, y);
	my_mlx_pixel_put(data, x, y, colour);
}