/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:19:13 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/18 15:33:13 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_pos		get_cylinder_normal(t_pos point, t_cylinder *cylinder)
{
	t_pos ctp;
	t_pos normal;

	ctp = subs_vec(point, cylinder->coor);
	normal = subs_vec(ctp, scale_vec(cylinder->vector,
										dot_product(cylinder->vector, ctp)));
	normed_vec(&normal);
	return (normal);
}

void		check_t(double *t, t_cylinder *cylinder, t_ray ray)
{
	t_pos q;
	t_pos p2;

	p2 = add_vec(cylinder->coor, scale_vec(cylinder->vector, cylinder->height));
	q = add_vec(ray.origin, scale_vec(ray.dir, *t));
	if (dot_product(cylinder->vector, subs_vec(q, cylinder->coor)) <= 0)
		*t = -1;
	if (dot_product(cylinder->vector, subs_vec(q, p2)) >= 0)
		*t = -1;
}

int			cyl_get_roots(double *t0, double *t1, t_cylinder *cylinder,
								t_ray ray)
{
	t_pos	a_sqrt;
	t_pos	right;
	double	a;
	double	b;
	double	c;

	a_sqrt = subs_vec(ray.dir,
								scale_vec(cylinder->vector,
								dot_product(ray.dir, cylinder->vector)));
	a = dot_product(a_sqrt, a_sqrt);
	right = subs_vec(subs_vec(ray.origin, cylinder->coor),
						scale_vec(cylinder->vector,
							dot_product(subs_vec(ray.origin, cylinder->coor),
							cylinder->vector)));
	b = 2 * dot_product(a_sqrt, right);
	c = dot_product(right, right) - (cylinder->diam * cylinder->diam);
	if (!solve_quadratic(create_vec(a, b, c), t0, t1))
		return (0);
	return (1);
}

int			intersect_cylinder(t_ray ray, t_cylinder *cylinder, double *t)
{
	double t0;
	double t1;

	if (!cyl_get_roots(&t0, &t1, cylinder, ray))
		return (0);
	if (t0 > 0)
		check_t(&t0, cylinder, ray);
	if (t1 > 0)
		check_t(&t1, cylinder, ray);
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t1 < t0)
		if (t1 > 0)
			*t = t1;
		else
			*t = t0;
	else
	{
		if (t0 > 0)
			*t = t0;
		else
			*t = t1;
	}
	return (1);
}

t_pos	get_n_cylinder(t_cylinder *cylinder, t_intersection *p)
{
	t_pos		n;
	t_pos		pc;
	t_pos		v;
	float		dot_v_pc;

	pc = subs_vec(p->inter_point, cylinder->coor);
	v = cylinder->vector;
	dot_v_pc = dot_product(v, pc);
	v = scale_vec(v, dot_v_pc);
	n = subs_vec(pc, v);
	return (n);
}
