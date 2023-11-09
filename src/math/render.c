/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/11/09 14:38:20 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_rgb	render(t_data *data, t_ray ray, int x, int y)
{
	t_o_type	res;
	t_rgb		color;

	init_ray(data, x, y, &ray);
	res = intersect_with_all(data->param, ray, &data->param->p.dist);
	if (res == SPHERE)
		color = get_pixel_color_sp(update_intersection(data->param,
					&data->param->p, ray), data->param,
				data->param->sp_choosed, ray);
	if (res == CYLINDER)
		color = get_pixel_color_cy(update_intersection(data->param,
					&data->param->p, ray), data->param,
				data->param->cy_choosed, ray);
	if (res == PLANE)
		color = get_pixel_color_pl(update_intersection(data->param,
					&data->param->p, ray), data->param,
				data->param->pl_choosed, ray);
	if (res == ERRORS)
		color = (t_rgb){0, 0, 0};
	return (color);
}
