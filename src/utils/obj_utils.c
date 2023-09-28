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

//Error :
//1 error lightning ambient ratio
//2 error rgb
//3 error vector
//4 error fov
//5 error bright

//[A] [0.2] [255,255,255]
t_alight	*create_alight(t_data *data, char **args)
{
	t_alight	*new;

	printf("Creating ambient light\n");
	new = malloc(sizeof(t_alight));
	if (!new)
		return (NULL);
	if (ft_atod(args[1]) >= 0.0 && ft_atod(args[1]) <= 1.0)
		new->ratio = ft_atod(args[1]);
	else
	{
		data->error = 1;
		return (new);
	}
	new->rgb = rgb_converter(data, args[2]);
	return (new);
}
//[C] [-50.0,0,20] [0,0,1] [70]
t_camera	*create_camera(t_data *data, char **args)
{
	t_camera	*new;

	printf("Creating camera\n");
	new = malloc(sizeof(t_camera));
	if (!new)
		return (NULL);
	new->coor = ft_coor(args[1]);
	new->vector = ft_vector(data, args[2]);
	if (ft_atoi(args[3]) >= 0 && ft_atoi(args[3]) <= 180)
		new->fov = ft_atod(args[3]);
	else
		data->error = 4;
	return (new);
}

//[L] [-40.0,50.0,0.0] [0.6] [10,0,255]
t_light	*create_light(t_data *data, char **args)
{
	t_light	*new;

	printf("Creating light\n");
	new = malloc(sizeof(t_light));
	if (!new)
		return (NULL);
	new->coor = ft_coor(args[1]);
	if (ft_atod(args[2]) >= 0.0 && ft_atod(args[2]) <= 1.0)
		new->bright = ft_atod(args[2]);
	else
		data->error = 5;
	new->rgb = rgb_converter(data, args[3]);
	return (new);
}

//[pl] [0.0,0.0,-10.0] 0.0,1.0,0.0] [0,0,225]
t_plane	*create_plane(t_data *data, char **args)
{
	t_plane	*new;

	printf("Creating plane\n");
	new = malloc(sizeof(t_plane));
	if (!new)
		return (NULL);
	new->coor = ft_coor(args[1]);
	new->vector = ft_vector(data, args[2]);
	new->rgb = rgb_converter(data, args[3]);
	new->next = NULL;
	return (new);
}

//[sp] [0.0,0.0,20.6] [12.6] [10,0,255]
t_sphere	*create_sphere(t_data *data, char **args)
{
	t_sphere	*new;

	printf("Creating sphere\n");
	new = malloc(sizeof(t_sphere));
	if (!new)
		return (NULL);
	new->coor = ft_coor(args[1]);
	new->diam = ft_atod(args[2]);
	new->rgb = rgb_converter(data, args[3]);
	new->next = NULL;
	return (new);
}

//[cy] [50.0,0.0,20.6] [0.0,0.0,1.0] [14.2] [21.42] [10,0,255]
t_cylinder	*create_cylinder(t_data *data, char **args)
{
	t_cylinder	*new;

	printf("Creating cylinder\n");
	new = malloc(sizeof(t_cylinder));
	if (!new)
		return (NULL);
	new->coor = ft_coor(args[1]);
	new->vector = ft_vector(data, args[2]);
	new->diam = ft_atod(args[3]);
	new->height = ft_atod(args[4]);
	new->rgb = rgb_converter(data, args[5]);
	new->next = NULL;
	return (new);
}
