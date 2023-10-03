/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:32:28 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/03 15:50:51 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// we need to norm the camera vec
t_referential	set_referential(t_axis *cam_vec)
{
	t_axis	tmp;
	t_referential ref;

	normed_vec(cam_vec);
	if (cam_vec->x || cam_vec->z)
		tmp = add_vec(*cam_vec, (t_axis){0,1,0});
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

void	get_win_scale(t_param *param)
{
	t_axis	center;
	t_axis	*cam;
	t_axis	tmp;

	cam = param->camera->coor;
	param->hx = tan(param->camera->fov);
	param->hy = (param->hx  * (double)(HEIGTH) / (double)(WIDTH));
	param->dir.pixel_size = (param->hx * 2.0) / (double)(WIDTH);
	center = add_vec(*cam, param->ref.z);
	param->dir.shift_x = scale_vec(param->ref.x, param->dir.pixel_size);
	param->dir.shift_y = scale_vec(param->ref.y, param->dir.pixel_size);
	tmp = subs_vec(param->ref.z, add_vec(scale_vec(param->ref.x, \
			param->hx), scale_vec(param->ref.y,param->hy)));
	param->corner = add_vec(tmp, *cam);
}

// return un t_axis mais pour les test va return un int 
int	pixel_color(t_param *param, t_axis pixel)
{
	(void) param;
	printf("pixel.x = {%f} \npixel.y = {%f}\npixel.z = {%f}\n", pixel.x, pixel.y, pixel.z);
	if (pixel.z > pixel.y && pixel.z > pixel.x)
		return (my_mlx_get_color_value(pixel.z * 50, pixel.z, pixel.z));
	else if (pixel.x > pixel.y && pixel.x > pixel.z)
		return (my_mlx_get_color_value(pixel.x, pixel.x * 50, pixel.x));
	else if (pixel.y > pixel.z && pixel.y > pixel.x)
		return (my_mlx_get_color_value(pixel.y, pixel.y, pixel.y * 50));
	else 
		return (my_mlx_get_color_value(0, 0, 0));
}

void	little_main_for_pixel(t_data *data, t_axis pixel, int x, int  y)
{
	int				colour;
	t_referential	ref;
	t_param			*param;

	param = data->param;
	ref = set_referential(param->camera->vector);
	colour = pixel_color(data->param, pixel);
	my_mlx_pixel_put(data, x, y, colour);
}