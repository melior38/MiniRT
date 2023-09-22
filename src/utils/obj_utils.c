/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/13 09:23:59 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_object	*create_alight(double ratio, t_rgb *rgb)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = AMBIENT_LIGHT;
	new->b_ratio = ratio;
	new->fov = NULL;
	new->bright = NULL;
	new->diameter = NULL;
	new->height = NULL;
	new->center_coor = NULL;
	new->vector = NULL;
	new->rgb = rgb;
	new->next = NULL;
	return (new);
}

t_object	*create_camera(t_axis *coor, t_axis *vector, int fov)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = CAMERA;
	new->b_ratio = NULL;
	new->fov = fov;
	new->bright = NULL;
	new->diameter = NULL;
	new->height = NULL;
	new->center_coor = coor;
	new->vector = vector;
	new->rgb = NULL;
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
	new->b_ratio = NULL;
	new->fov = NULL;
	new->bright = bright;
	new->diameter = NULL;
	new->height = NULL;
	new->center_coor = NULL;
	new->vector = NULL;
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
	new->b_ratio = NULL;
	new->fov = NULL;
	new->bright = NULL;
	new->diameter = NULL;
	new->height = NULL;
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
	new->b_ratio = NULL;
	new->fov = NULL;
	new->bright = NULL;
	new->diameter = diam;
	new->height = NULL;
	new->center_coor = NULL;
	new->vector = NULL;
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
	new->b_ratio = NULL;
	new->fov = NULL;
	new->bright = NULL;
	new->diameter = diam;
	new->height = height;
	new->center_coor = coor;
	new->vector = vector;
	new->rgb = rgb;
	new->next = NULL;
	return (new);
}
