/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/19 14:07:41 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

bool	check_str_float(char *str)
{
	int i;
	int comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
		i++;
	if (i < 5)
		return (false);
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == ',' 
				|| str[i] == '.')
			i++;
		else
			return (false);
	}
	if (comma_count != 2)
		return (false);
	return (true);
}

bool	check_str_int(char *str)
{
	int i;
	int comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
		i++;
	if (i < 5)
		return (false);
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == ',')
			i++;
		else
			return (false);
	}
	if (comma_count != 2)
		return (false);
	return (true);
}

int	rgb_convertor(char *str, char rgb)
{
	int		i;
	char	**splited_rgb;
	int		res;
	int		index;

	if (check_str_int(str))
		return (-1);
	i = 0;
	if (rgb == 'r')
		index = 0;
	if (rgb == 'g')
		index = 1;
	if (rgb == 'b')
		index = 2;
	splited_rgb = ft_split(str, ',');
	res = ft_atoi(splited_rgb[index]);
	if (res >= 0 && res < 256)
	{
		free_tab(splited_rgb);
		return (res);
	}
	return (-1);
}

float	coor_convertor(char *str, char coor)
{
	int		i;
	char	**splited_coor;
	float		res;
	int		index;

	if (check_str_float(str))
		return (-1);
	i = 0;
	if (coor == 'x')
		index = 0;
	if (coor == 'y')
		index = 1;
	if (coor == 'z')
		index = 2;
	splited_coor = ft_split(str, ',');
	res = (float)ft_atod(splited_coor[index]);
	free_tab(splited_coor);
	return (res);
}

bool	Ambient_light_set(t_object *list, char **arg_tab)
{
	list->type = AMBIENT_LIGHT;
	if (get_ratio(&(list->b_ratio), arg_tab[1]) == false)
		return (false);
	if (get_rgb(list->rgb, arg_tab[2]) == false);
		return (false);
	return (0);
}

bool	Camera_set(t_object *list, char **arg_tab)
{
	if (get_coor(list->center_coor, arg_tab[1]))
		return (false);
	
	return (0);
}

bool	Light_set(t_object *list, char **arg_tab)
{
	int		i;

	i = 1;
	while (arg_tab[i])
		i++;
	if (i != 3)
		return (1);
	light->view_point->x = coor_convertor(arg_tab[1], 'x');
	light->view_point->y = coor_convertor(arg_tab[1], 'y');
	light->view_point->z = coor_convertor(arg_tab[1], 'z');
	if (light->view_point->x == 123.123001 || light->view_point->x == 123.123001
			 || light->view_point->x == 123.123001)
		return (1);
	light->brightness = ft_atof(arg_tab[2]);
	if (light->brightness == 123.123001)
		return (1);
	light->rgb->r = rgb_convertor(arg_tab[3], 'r');
	light->rgb->g = rgb_convertor(arg_tab[3], 'g');
	light->rgb->b = rgb_convertor(arg_tab[3], 'b');
	if (light->rgb->r < 0 || light->rgb->g < 0 || light->rgb->b < 0)
		return (1);
	return (0);
}

bool	plane_set(t_object *list, char **arg_tab)
{
	int		i;

	i = 1;
	while (arg_tab[i])
		i++;
	if (i != 3)
		return (1);
	plane->pl_coor->x = coor_convertor(arg_tab[1], 'x');
	plane->pl_coor->y = coor_convertor(arg_tab[1], 'y');
	plane->pl_coor->z = coor_convertor(arg_tab[1], 'z');
	if (plane->pl_coor->x == 123.123001 || plane->pl_coor->x == 123.123001
			 || plane->pl_coor->x == 123.123001)
		return (1);
	plane->normalized_vector->x = coor_convertor(arg_tab[2], 'x'); 
	plane->normalized_vector->y = coor_convertor(arg_tab[2], 'y'); 
	plane->normalized_vector->z = coor_convertor(arg_tab[2], 'z'); 
	if (plane->normalized_vector->x == 123.123001 || plane->normalized_vector->x == 123.123001
			 || plane->normalized_vector->x == 123.123001)
		return (1);
	else if ((plane->normalized_vector->x < -1.0 || plane->normalized_vector->x > 1.0) || 
			(plane->normalized_vector->y < -1.0 || plane->normalized_vector->y > 1.0) ||
			(plane->normalized_vector->z < -1.0 || plane->normalized_vector->z > 1.0))
		return (1);
	plane->rgb->r = rgb_convertor(arg_tab[3], 'r');
	plane->rgb->g = rgb_convertor(arg_tab[3], 'g');
	plane->rgb->b = rgb_convertor(arg_tab[3], 'b');
	if (plane->rgb->r < 0 || plane->rgb->g < 0 || plane->rgb->b < 0)
		return (1);
	return (0);
}

bool	sphere_set(t_object *list, char **arg_tab)
{
	int		i;

	i = 1;
	while (arg_tab[i])
		i++;
	if (i != 3)
		return (1);
	sphere->sp_center->x = coor_convertor(arg_tab[1], 'x');
	sphere->sp_center->y = coor_convertor(arg_tab[1], 'y');
	sphere->sp_center->z = coor_convertor(arg_tab[1], 'z');
	if (sphere->sp_center->x == 123.123001 || sphere->sp_center->x == 123.123001
			 || sphere->sp_center->x == 123.123001)
		return (1);
	sphere->radius = (float)ft_atof(arg_tab[2]);
	if (sphere->radius > 1 || sphere->radius < 0 
			|| sphere->radius == 123.123001)
		return (1);
	sphere->colour->r = rgb_convertor(arg_tab[3], 'r');
	sphere->colour->g = rgb_convertor(arg_tab[3], 'g');
	sphere->colour->b = rgb_convertor(arg_tab[3], 'b');
	if (sphere->colour->r < 0 || sphere->colour->g < 0 || sphere->colour->b < 0)
		return (1);
	return (0);
}

bool	cylinder_set(t_object *list, char **arg_tab)
{
	int		i;

	i = 1;
	while (arg_tab[i])
		i++;
	if (i != 5)
		return (1);
	cylinder->cy_center->x = coor_convertor(arg_tab[1], 'x');
	cylinder->cy_center->y = coor_convertor(arg_tab[1], 'y');
	cylinder->cy_center->z = coor_convertor(arg_tab[1], 'z');
	if (cylinder->cy_center->x == 123.123001 || cylinder->cy_center->x == 123.123001
			 || cylinder->cy_center->x == 123.123001)
		return (1);
	cylinder->normalized_vector->x = coor_convertor(arg_tab[2], 'x'); 
	cylinder->normalized_vector->y = coor_convertor(arg_tab[2], 'y'); 
	cylinder->normalized_vector->z = coor_convertor(arg_tab[2], 'z'); 
	if (cylinder->normalized_vector->x == 123.123001 || cylinder->normalized_vector->x == 123.123001
			 || cylinder->normalized_vector->x == 123.123001)
		return (1);
	else if ((cylinder->normalized_vector->x < -1.0 || cylinder->normalized_vector->x > 1.0) || 
			(cylinder->normalized_vector->y < -1.0 || cylinder->normalized_vector->y > 1.0) ||
			(cylinder->normalized_vector->z < -1.0 || cylinder->normalized_vector->z > 1.0))
		return (1);
	cylinder->diameter = (float)ft_atof(arg_tab[3]);
	if (cylinder->diameter > 1 || cylinder->diameter < 0 
			|| cylinder->diameter == 123.123001)
		return (1);
	cylinder->height = (float)ft_atof(arg_tab[4]);
	if (cylinder->height > 1 || cylinder->height < 0 
			|| cylinder->height == 123.123001)
		return (1);
	cylinder->rgb->r = rgb_convertor(arg_tab[5], 'r');
	cylinder->rgb->g = rgb_convertor(arg_tab[5], 'g');
	cylinder->rgb->b = rgb_convertor(arg_tab[5], 'b');
	if (cylinder->rgb->r < 0 || cylinder->rgb->g < 0 || cylinder->rgb->b < 0)
		return (1);
	return (0);
}