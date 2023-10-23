/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:46:23 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/23 14:49:07 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// Return whether or not there is an intersection with a sphere
// between two points.
bool	sp_intersection_between_points(t_pos p1, t_pos p2, t_sphere *shape)
{
	t_ray	ray;
	t_pos	dir;
	t_pos	co;
	t_eq	eq;
	double	len;

	dir = subs_vec(p2, p1);
	len = vec_norm(dir);
	ray.origin = p1;
	normed_vec(&ray.dir);
	co = subs_vec(ray.origin, shape->coor);
	eq.a = 1;
	eq.b = 2.0 * dot_product(co, ray.dir);
	eq.c = dot_product(co, co) - pow(shape->diam, 2);
	eq.discriminant = pow(eq.b, 2) - (4 * eq.a * eq.c);
	if (eq.discriminant < 0)
		return (false);
	eq.s1 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
	eq.s2 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);
	if ((eq.s1 > 0 && eq.s1 < len) || (eq.s2 > 0 && eq.s2 < len))
		return (true);
	return (false);
}

// Return whether or not there is an intersection with a plane
// between two points.
bool	pl_intersection_between_points(t_pos p1, t_pos p2, t_plane *shape)
{
	t_ray	ray;
	t_pos	dir;
	double	t;
	double	ray_n_dot_product;

	ray.dir = subs_vec(p2, p1);
	dir = ray.dir;
	ray.origin = p1;
	normed_vec(&ray.dir);
	normed_vec(&shape->vector);
	ray_n_dot_product = dot_product(ray.dir, shape->vector);
	if (ray_n_dot_product == 0)
		return (false);
	t = dot_product(subs_vec(shape->coor, ray.origin),
			shape->vector) / ray_n_dot_product;
	if (t > 0 && t < vec_norm(dir))
		return (true);
	return (false);
}

// Return whether or not there is an intersection with a cylinder
// between two points.
bool	cy_intersection_between_points(t_pos p1, t_pos p2, t_cylinder *shape)
{
	t_ray		ray;
	t_pos		dir;
	double		len;
	t_eq		eq;

	normed_vec(&shape->vector);
	dir = subs_vec(p2, p1);
	len = vec_norm(dir);
	ray.origin = p1;
	ray.dir = dir;
	normed_vec(&ray.dir);
	compute_cy_equation(ray, shape, &eq);
	if (eq.discriminant < 0)
		return (false);
	if ((eq.s1 > 0 && eq.s1 < len) || (eq.s2 > 0 && eq.s2 < len))
		return (true);
	return (false);
}

bool	is_intersection(t_pos p1, t_pos p2, t_param *param, int id)
{
	if (loop_cy_shade(p1, p2, param, id))
		return (true);
	if (loop_pl_shade(p1, p2, param, id))
		return (true);
	if (loop_sp_shade(p1, p2, param, id))
		return (true);
	return (false);
}
