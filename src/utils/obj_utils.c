/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/27 09:44:27 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//[A] [0.2] [255,255,255]
t_alight	*create_alight(t_data *data, char **args)
{
	t_alight	*new;

	new = malloc(sizeof(t_alight));
	if (!new)
		return (NULL);
	if (ft_atod(args[1]) >= 0.0 && ft_atod(args[1]) <= 1.0)
		new->ratio = ft_atod(args[1]);
	else
	{
		data->error = 1;
		return (NULL);
	}
	new->rgb = rgb_converter(data, args[2]);
	return (new);
}

t_object	*create_camera(t_axis *coor, t_axis *vector, int fov)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = CAMERA;
	new->fov = fov;
	new->center_coor = coor;
	new->vector = vector;
	new->next = NULL;
	return (new);
}

t_object	*create_light(t_axis *coor, double bright, t_rgb *rgb)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = LIGHT;
	new->bright = bright;
	new->center_coor = coor;
	new->rgb = rgb;
	new->next = NULL;
	return (new);
}

t_object	*create_plane(t_axis *coor, t_axis *vector, t_rgb *rgb)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = PLAN;
	new->center_coor = coor;
	new->vector = vector;
	new->rgb = rgb;
	new->next = NULL;
	return (new);
}

t_object	*create_sphere(t_axis *coor, double diam, t_rgb *rgb)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = SPHERE;
	new->center_coor = coor;
	new->diameter = diam;
	new->rgb = rgb;
	new->next = NULL;
	return (new);
}

t_object	*create_cylinder(t_axis *coor, t_axis *vector, double diam,
				double height, t_rgb *rgb)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = CYLINDER;
	new->diameter = diam;
	new->height = height;
	new->center_coor = coor;
	new->vector = vector;
	new->rgb = rgb;
	new->next = NULL;
	return (new);
}
