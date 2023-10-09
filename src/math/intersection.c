/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:51:24 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/09 15:44:21 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// le centre de ma window est a (x = 0, y = 0, z = d)
// c'est un bonne indice pour la suite 
// d est une distance qu'on definie a l'avance en l'occurence ce sera probablement 1
// donc pour identifier le centre suffit de recup les donner de la cam et de rajouter d au z pour avoir le centre de la fennetre
// donc il faut recuperer le pixel du centre de la fennetre et lui donner la coor du centre de la window
// ensuite on cree un scale des coor en fonction du nombre de pixel


void	swap_doubles(double *a, double *b)
{
	double buffer;
	buffer = *a;
	*a = *b;
	*b = buffer;
}
// esquisse de ce qu'il y a a faire
t_pos		get_sphere_normal(t_pos point, t_sphere *sphere)
{
	t_pos n;
	t_pos *coor;

	coor = sphere->coor;
	n = subs_vec(point, *coor);
	normalize_vector(&n);
	return (n);
}

int			get_roots(double *t0, double *t1, t_ray ray, t_sphere *sphere)
{
	t_pos	l;
	double	a;
	double	b;
	double	c;
	t_pos *coor;

	coor = sphere->coor;

	l = subs_vec(ray.origin, *coor);
	a = dot_product(ray.dir, ray.dir);
	b = 2.0 * dot_product(ray.dir, l);
	c = dot_product(l, l) - (sphere->diam * sphere->diam);
	if (solve_quadratic(create_vec(a, b, c), t0, t1) == 0)
		return (0);
	return (1);
}

HUGE_VAL

int			intersect_sphere(t_ray ray, t_sphere *sphere, double *t)
{
	double t0;
	double t1;

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
