/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/04 09:55:08 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//Error :
//1 error lightning ambient ratio
//2 error rgb
//3 error vector
//4 error fov
//5 error bright

//[pl] [0.0,0.0,-10.0] 0.0,1.0,0.0] [0,0,225]
t_plane	*create_plane(t_data *data, char **args)
{
	t_plane	*new;

	new = malloc(sizeof(t_plane));
	if (!new)
		return (NULL);
	new->coor = ft_coor(args[1], data);
	new->vector = ft_vector(data, args[2]);
	new->rgb = rgb_converter(data, args[3]);
	new->next = NULL;
	return (new);
}

//[sp] [0.0,0.0,20.6] [12.6] [10,0,255]
t_sphere	*create_sphere(t_data *data, char **args)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	if (!new)
		return (NULL);
	new->coor = ft_coor(args[1], data);
	new->diam = ft_atod(args[2], data);
	new->radius = new->diam / 2;
	new->rgb = rgb_converter(data, args[3]);
	new->center = NULL;
	new->next = NULL;
	return (new);
}

//[cy] [50.0,0.0,20.6] [0.0,0.0,1.0] [14.2] [21.42] [10,0,255]
t_cylinder	*create_cylinder(t_data *data, char **args)
{
	t_cylinder	*new;

	new = malloc(sizeof(t_cylinder));
	if (!new)
		return (NULL);
	new->coor = ft_coor(args[1], data);
	new->vector = ft_vector(data, args[2]);
	new->diam = ft_atod(args[3], data);
	new->height = ft_atod(args[4], data);
	new->rgb = rgb_converter(data, args[5]);
	new->next = NULL;
	return (new);
}
