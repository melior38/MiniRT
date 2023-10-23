/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:19:13 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/23 14:51:42 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_pos	get_n_cylinder(t_cylinder *cylinder, t_inter p)
{
	t_pos		n;
	t_pos		pc;
	t_pos		v;
	double		dot_v_pc;

	pc = subs_vec(p.inter_point, cylinder->coor);
	v = cylinder->vector;
	dot_v_pc = dot_product(v, pc);
	v = scale_vec(v, dot_v_pc);
	n = subs_vec(pc, v);
	return (n);
}

void	compute_cy_equation(t_ray ray, t_cylinder *cy, t_eq *eq)
{
	double	dot_prod;

	normed_vec(&cy->vector);
	eq->co = subs_vec(ray.origin, cy->coor);
	eq->a = dot_product(ray.dir, ray.dir) - pow(dot_product(ray.dir, cy->vector), 2.0);
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
		*t = eq.s1;
		return (1);
	}
	else if (eq.s2 > 0 && (eq.s1 < 0 || eq.s2 < eq.s1)
		&& (eq.s2 < *t || *t == -1))
	{
		*t = eq.s2;
		return (1);
	}
	return (0);
}