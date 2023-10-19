/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:42:17 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/19 15:52:49 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"


t_rgb	shade(t_intersection *p, t_rgb color, t_alight *al)
{
	if (fabs(0.0f - p->light_bright) > 0.0001f)
	{
		color = change_intensity(color,
				1.0f - (p->light_bright - al->ratio));
	}
	return (color);
}

t_rgb	get_pixel_color_sp(t_intersection *p, t_param *param, t_sphere *sp, t_ray ray)
{
	t_rgb	color;
	(void) ray;

	color = phong_sp(p, sp);
	if (!intersect_sphere(ray, sp, &param->p.dist))
		return((t_rgb) {0,0,0});
	if (is_intersection(p->light_pos, p->inter_point, param))
		color = shade(p, color, param->alight);
	return (color);
}

t_rgb	get_pixel_color_cy(t_intersection *p, t_param *param, t_cylinder *cy, t_ray ray)
{
	t_rgb	color;
	(void) ray;

	color = phong_cy(p, cy);
	if (!intersect_cylinder(ray, cy, &param->p.dist))
		return((t_rgb) {0,0,0});
	if (is_intersection(p->light_pos, p->inter_point, param))
		color = shade(p, color, param->alight);
	return (color);
}

t_rgb	get_pixel_color_pl(t_intersection *p, t_param *param, t_plane *pl, t_ray ray)
{
	t_rgb	color;
	(void) ray;

	color = phong_pl(p, pl);
	if (!intersect_plane(ray, pl, &param->p.dist))
		return((t_rgb) {0,0,0});
	if (is_intersection(p->light_pos, p->inter_point, param))
		color = shade(p, color, param->alight);
	return (color);
}
