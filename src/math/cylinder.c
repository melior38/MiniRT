/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:19:13 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/19 16:50:33 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// t_pos		get_cylinder_normal(t_pos point, t_cylinder *cylinder)
// {
// 	t_pos ctp;
// 	t_pos normal;

// 	ctp = subs_vec(point, cylinder->coor);
// 	normal = subs_vec(ctp, scale_vec(cylinder->vector,
// 										dot_product(cylinder->vector, ctp)));
// 	normed_vec(&normal);
// 	return (normal);
// }

// void		check_t(double *t, t_cylinder *cylinder, t_ray ray)
// {
// 	t_pos q;
// 	t_pos p2;

// 	p2 = add_vec(cylinder->coor, scale_vec(cylinder->vector, cylinder->height));
// 	q = add_vec(ray.origin, scale_vec(ray.dir, *t));
// 	if (dot_product(cylinder->vector, subs_vec(q, cylinder->coor)) <= 0)
// 		*t = -1;
// 	if (dot_product(cylinder->vector, subs_vec(q, p2)) >= 0)
// 		*t = -1;
// }

// int			cyl_get_roots(double *t0, double *t1, t_cylinder *cylinder,
// 								t_ray ray)
// {
// 	t_pos	a_sqrt;
// 	t_pos	right;
// 	double	a;
// 	double	b;
// 	double	c;

// 	a_sqrt = subs_vec(ray.dir,
// 								scale_vec(cylinder->vector,
// 								dot_product(ray.dir, cylinder->vector)));
// 	a = dot_product(a_sqrt, a_sqrt);
// 	right = subs_vec(subs_vec(ray.origin, cylinder->coor),
// 						scale_vec(cylinder->vector,
// 							dot_product(subs_vec(ray.origin, cylinder->coor),
// 							cylinder->vector)));
// 	b = 2 * dot_product(a_sqrt, right);
// 	c = dot_product(right, right) - (cylinder->diam * cylinder->diam);
// 	if (!solve_quadratic(create_vec(a, b, c), t0, t1))
// 		return (0);
// 	return (1);
// }

// int			intersect_cylinder(t_ray ray, t_cylinder *cylinder, double *t)
// {
// 	double t0;
// 	double t1;

// 	if (!cyl_get_roots(&t0, &t1, cylinder, ray))
// 		return (0);
// 	if (t0 > 0)
// 		check_t(&t0, cylinder, ray);
// 	if (t1 > 0)
// 		check_t(&t1, cylinder, ray);
// 	if (t0 < 0 && t1 < 0)
// 		return (0);
// 	if (t1 < t0)
// 		if (t1 > 0)
// 			*t = t1;
// 		else
// 			*t = t0;
// 	else
// 	{
// 		if (t0 > 0)
// 			*t = t0;
// 		else
// 			*t = t1;
// 	}
// 	return (1);
// }

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

void	compute_cy_equation(t_ray ray, t_cylinder *cy, t_eq *eq)
{
	float	dot_prod;

	normed_vec(&cy->vector);
	eq->co = subs_vec(ray.origin, cy->coor);
	eq->a = dot_product(ray.dir, ray.dir) - pow(dot_product(ray.dir, cy->vector), 2);
	eq->b = 2 * (dot_product(ray.dir, eq->co) - dot_product(ray.dir,
				cy->vector) * dot_product(eq->co, cy->vector));
	eq->c = dot_product(eq->co, eq->co) - pow(dot_product(eq->co,
				cy->vector), 2) - pow(cy->diam, 2);
	eq->discriminant = pow(eq->b, 2) - (4 * eq->a * eq->c);
	if (eq->discriminant < 0)
		return ;
	eq->s1 = (-eq->b - sqrt(eq->discriminant)) / (2 * eq->a);
	eq->s2 = (-eq->b + sqrt(eq->discriminant)) / (2 * eq->a);
	dot_prod = dot_product(subs_vec(add_vec(ray.origin, scale_vec(ray.dir,
						eq->s1)), cy->coor), scale_vec(cy->vector, cy->height));
	if (dot_prod < 0 || dot_prod > dot_product(scale_vec(cy->vector,
				cy->height), scale_vec(cy->vector, cy->height)))
		eq->s1 = -1;
	dot_prod = dot_product(subs_vec(add_vec(ray.origin, scale_vec(ray.dir,
						eq->s2)), cy->coor), scale_vec(cy->vector, cy->height));
	if (dot_prod < 0 || dot_prod > dot_product(scale_vec(cy->vector,
				cy->height), scale_vec(cy->vector, cy->height)))
		eq->s2 = -1;
}

int	intersect_cylinder(t_ray ray, t_cylinder *cy, double *t)
{
	t_eq	eq;

	*t = -1;
	normed_vec(&cy->vector);
	compute_cy_equation(ray, cy, &eq);
	if (eq.discriminant < 0)
		return (0);
	if (eq.s1 > 0 && (eq.s2 < 0 || eq.s1 < eq.s2)
		&& (eq.s1 < *t || *t == -1))
	{
		// inter->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s1));
		*t = eq.s1;
		return (1);
	}
	else if (eq.s2 > 0 && (eq.s1 < 0 || eq.s2 < eq.s1)
		&& (eq.s2 < *t || *t == -1))
	{
		// inter->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s2));
		*t = eq.s2;
		return (1);
	}
	return (0);
}