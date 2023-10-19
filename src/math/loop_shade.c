/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_shade.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:22:15 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/19 17:00:45 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// faire en sorte de set un idea permettant de comfirmer si c un cylindre, un plane ou un cercle 
bool	loop_cy_shade(t_pos p1, t_pos p2, t_cylinder *shape, t_cylinder *closest)
{
	t_cylinder	*tmp;

	tmp = shape;
	while (tmp)
	{
		if (tmp != closest)
			if (cy_intersection_between_points(p1, p2, shape))
				return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	loop_pl_shade(t_pos p1, t_pos p2, t_plane *shape, t_plane *closest)
{
	t_plane	*tmp;

	tmp = shape;
	while (tmp)
	{
		if (tmp != closest)
			if (pl_intersection_between_points(p1, p2, shape))
				return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	loop_sp_shade(t_pos p1, t_pos p2, t_sphere *shape, t_sphere *closest)
{
	t_sphere	*tmp;

	tmp = shape;
	while (tmp)
	{
		if (tmp != closest)
			if (sp_intersection_between_points(p1, p2, shape))
				return (true);
		tmp = tmp->next;
	}
	return (false);
}
