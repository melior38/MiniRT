/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uobj_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/04 09:54:50 by asouchet         ###   ########.fr       */
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

	new = malloc(sizeof(t_alight));
	printf("alight address [%p]\n", &new);
	if (!new)
		return (NULL);
	new->rgb = NULL;
	if (data->param->alight)
		print_error(data, "Alight twice or more in .rt file\n");
	if (ft_atod(args[1], data) >= 0.0 && ft_atod(args[1], data) <= 1.0)
		new->ratio = ft_atod(args[1], data);
	else
	{
		print_error(data, "Alight Ratio not in range\n");
		return (new);
	}
	new->rgb = rgb_converter(data, args[2]);
	printf("alight->rgb address [%p]\n", new->rgb);
	return (new);
}

//[C] [-50.0,0,20] [0,0,1] [70]
t_camera	*create_camera(t_data *data, char **args)
{
	t_camera	*new;

	new = malloc(sizeof(t_camera));
	printf("camera address [%p]\n", &new);
	if (!new)
		return (NULL);
	if (data->param->camera)
		print_error(data, "Camera twice or more in .rt file\n");
	new->coor = ft_coor(args[1], data);
	new->vector = ft_vector(data, args[2]);
	if (ft_atod(args[3], data) >= 0 && ft_atod(args[3], data) <= 180)
		new->fov = ft_atod(args[3], data);
	else
		print_error(data, "Camera fov not in range\n");
	return (new);
}

//[L] [-40.0,50.0,0.0] [0.6] [10,0,255]
t_light	*create_light(t_data *data, char **args)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	printf("light address [%p]\n", &new);
	if (!new)
		return (NULL);
	if (data->param->light)
		print_error(data, "Light twice or more in .rt file\n");
	new->coor = ft_coor(args[1], data);
	if (ft_atod(args[2], data) >= 0.0 && ft_atod(args[2], data) <= 1.0)
		new->bright = ft_atod(args[2], data);
	else
		print_error(data, "Light brightness not in range\n");
	new->rgb = rgb_converter(data, args[3]);
	return (new);
}
