/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:28:48 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/20 12:43:59 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	set_sphere_id(t_sphere *sphere)
{
	t_sphere	*tmp;
	int			id;

	tmp = sphere;
	id = 100;
	while (tmp)
	{
		tmp->id = id;
		tmp = tmp->next;
		id++;
	}
}

void	set_cylinder_id(t_cylinder *cylinder)
{
	t_cylinder	*tmp;
	int			id;

	tmp = cylinder;
	id = 50;
	while (tmp)
	{
		tmp->id = id;
		tmp = tmp->next;
		id++;
	}
}

void	set_plane_id(t_plane *plane)
{
	t_plane	*tmp;
	int		id;

	tmp = plane;
	id = 0;
	while (tmp)
	{
		tmp->id = id;
		tmp = tmp->next;
		id++;
	}
}

void	set_obj_id(t_data *data)
{
	set_sphere_id(data->param->sphere);
	set_cylinder_id(data->param->cylinder);
	set_plane_id(data->param->plane);
}
