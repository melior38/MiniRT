/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/09 14:54:08 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	rgb_convertor(char *str, char rgb)
{
	int		i;
	char	*atoi_material;
	int		res;

	i = 0;
	if (rgb == 'r')
		i = 0;
	if (rgb == 'g')
		i = 4;
	if (rgb == 'b')
		i = 8;
	atoi_material = ft_substr(str, i, 3);
	res = ft_atoi(atoi_material);
	if (res <= 0 && res > 256)
		return (res);
	free(atoi_material);
	atoi_material = NULL;
	return (-1);
}

int	Ambient_light_set(t_ambient_light *A_light, char **arg_tab)
{
	int i;

	i = 1;
	while (arg_tab[i])
		i++;
	if (i != 2)
		return (1);
	A_light->light_ratio = ft_atof(arg_tab[1]);
	if (A_light->light_ratio > 1 || A_light->light_ratio < 0 
			|| A_light->light_ratio == 123.123)
		return (1);
	A_light->rgb->r = rgb_convertor(arg_tab[2], 'r');
	if (A_light->rgb->r < 0)
		return (1);
	A_light->rgb->g = rgb_convertor(arg_tab[2], 'g');
	if (A_light->rgb->g < 0)
		return (1);
	A_light->rgb->b = rgb_convertor(arg_tab[2], 'b');
	if (A_light->rgb->b < 0)
		return (1);
	return (0);
}

int	Camera_set(t_camera *camera, char **arg_tab)
{
	return (0);
}

int	Light_set(t_light *light, char **arg_tab)
{
	return (0);
}

int	plane_set(t_plane *plane, char **arg_tab)
{
	return (0);
}

int	sphere_set(t_sphere *sphere, char **arg_tab)
{
	return (0);
}

int	cylinder_set(t_cylinder *cylinder, char **arg_tab)
{
	return (0);
}