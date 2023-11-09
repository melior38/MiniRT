/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:13:47 by asouchet          #+#    #+#             */
/*   Updated: 2023/11/09 14:42:27 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// les intersect fonctionne mais pas mes loop sphere a revoir shit
t_sphere	*loop_sphere(t_param *param, t_ray ray, double *t)
{
	t_sphere	*tmp;
	t_sphere	*ret;
	double		t_min;
	int			miss;

	*t = HUGE_VAL;
	tmp = param->sphere;
	ret = param->sphere;
	while (tmp)
	{
		miss = intersect_sphere(ray, tmp, &t_min);
		if (miss)
		{
			if (t_min < *t)
			{
				ret = tmp;
				ret->id = tmp->id;
				*t = t_min;
			}
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_cylinder	*loop_cylinder(t_param *param, t_ray ray, double *t)
{
	t_cylinder	*tmp;
	t_cylinder	*ret;
	double		t_min;
	int			miss;

	*t = HUGE_VAL;
	tmp = param->cylinder;
	ret = param->cylinder;
	while (tmp)
	{
		miss = intersect_cylinder(ray, tmp, &t_min);
		if (miss)
		{
			if (t_min < *t)
			{
				ret = tmp;
				ret->id = tmp->id;
				*t = t_min;
			}
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_plane	*loop_plane(t_param *param, t_ray ray, double *t)
{
	t_plane		*tmp;
	t_plane		*ret;
	double		t_min;
	int			miss;

	*t = HUGE_VAL;
	tmp = param->plane;
	ret = param->plane;
	while (tmp)
	{
		miss = intersect_plane(ray, tmp, &t_min);
		if (miss)
		{
			if (t_min < *t)
			{
				ret = tmp;
				ret->id = tmp->id;
				*t = t_min;
			}
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	init_var(double *t_min, double *t)
{
	*t = HUGE_VAL;
	*t_min = 0;
}

t_o_type	intersect_with_all(t_param *param, t_ray ray, double *t)
{
	double		t_min;
	t_o_type	res;

	init_var(&t_min, t);
	param->sp_choosed = loop_sphere(param, ray, &t_min);
	if (*t > t_min)
	{
		res = SPHERE;
		*t = t_min;
	}
	param->pl_choosed = loop_plane(param, ray, &t_min);
	if (*t > t_min)
	{
		res = PLANE;
		*t = t_min;
	}
	param->cy_choosed = loop_cylinder(param, ray, &t_min);
	if (*t > t_min)
	{
		res = CYLINDER;
		*t = t_min;
	}
	if (*t == HUGE_VAL)
		res = ERRORS;
	return (res);
}
