/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shade.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:22:15 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/20 17:58:31 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// faire en sorte de set un idea permettant de comfirmer si c un cylindre, un plane ou un cercle 
bool	loop_cy_shade(t_pos p1, t_pos p2, t_param *param, int id)
{
	t_cylinder	*tmp;
	t_cylinder	*closest;

	tmp = param->cylinder;
	closest = param->cy_choosed;
	while (tmp)
	{
		if (id == closest->id)
		{
			tmp = tmp->next;
			continue ;
		}
		else if (cy_intersection_between_points(p1, p2, tmp))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	loop_pl_shade(t_pos p1, t_pos p2, t_param *param, int id)
{
	t_plane	*tmp;
	t_plane	*closest;

	tmp = param->plane;
	closest = param->pl_choosed;
	while (tmp)
	{
		if (id == closest->id)
		{
			tmp = tmp->next;
			continue ;
		}
		else if (pl_intersection_between_points(p1, p2, tmp))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	loop_sp_shade(t_pos p1, t_pos p2, t_param *param, int id)
{
	t_sphere	*tmp;
	t_sphere	*closest;

	tmp = param->sphere;
	closest = param->sp_choosed;
	while (tmp)
	{
		if (id == closest->id)
		{
			tmp = tmp->next;
			continue ;
		}
		else if (sp_intersection_between_points(p1, p2, tmp))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
