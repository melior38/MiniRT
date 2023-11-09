/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:51:24 by asouchet          #+#    #+#             */
/*   Updated: 2023/11/09 14:43:31 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_pos	get_sphere_normal(t_pos point, t_sphere *sphere)
{
	t_pos	n;

	n = subs_vec(point, sphere->coor);
	normed_vec(&n);
	return (n);
}

int	get_roots(double *t0, double *t1, t_ray ray, t_sphere *sphere)
{
	t_pos	l;
	double	a;
	double	b;
	double	c;

	l = subs_vec(ray.origin, sphere->coor);
	a = dot_product(ray.dir, ray.dir);
	b = 2.0 * dot_product(ray.dir, l);
	c = dot_product(l, l) - (sphere->diam * sphere->diam);
	if (solve_quadratic(create_vec(a, b, c), t0, t1) == 0)
		return (0);
	return (1);
}

int	intersect_sphere(t_ray ray, t_sphere *sphere, double *t)
{
	double	t0;
	double	t1;

	if (get_roots(&t0, &t1, ray, sphere) == 0)
		return (0);
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (0);
	}
	*t = t0;
	return (1);
}

// Fonction pour calculer l'intersection entre un rayon et un plan
int	intersect_plane(t_ray ray, t_plane *plane, double *t)
{
	double	denominator;

	normed_vec(&plane->vector);
	denominator = dot_product(plane->vector, ray.dir);
	if (denominator == 0)
		return (0);
	*t = dot_product(subs_vec(plane->coor, ray.origin),
			plane->vector) / denominator;
	if (*t < 0)
		return (0);
	return (1);
}
