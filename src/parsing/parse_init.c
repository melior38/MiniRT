/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/19 17:42:24 by asouchet         ###   ########.fr       */
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
//	int		i;
	char	**splited_rgb;
	int		res;
	int		index;

	if (check_str_int(str))
		return (-1);
//	i = 0;
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
//	int		i;
	char	**splited_coor;
	float		res;
	int		index;

	if (check_str_float(str))
		return (-1);
//	i = 0;
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

//bool	Ambient_light_set(t_object *list, char **arg_tab)
//{
//	list->type = AMBIENT_LIGHT;
//	if (get_ratio(&(list->b_ratio), arg_tab[1]) == false)
//		return (false);
//	if (get_rgb(list->rgb, arg_tab[2]) == false);
//		return (false);
//	return (true);
//}
//
//bool	Camera_set(t_object *list, char **arg_tab)
//{
//	list->type = CAMERA;
//	if (get_coor(list->center_coor, arg_tab[1]) == false)
//		return (false);
//	if (get_vector(list->vector, arg_tab[2]) == false)
//		return (false);
//	list->fov = ft_atoi(arg_tab[3]);
//	return (true);
//}
//
//bool	Light_set(t_object *list, char **arg_tab)
//{
//	list->type = LIGHT;
//	if (get_coor(list->center_coor, arg_tab[1]) == false)
//		return (false);
//	if (get_ratio(&(list->b_ratio), arg_tab[2]) == false)
//		return (false);
//	if (get_rgb(list->rgb, arg_tab[3]) == false);
//		return (false);
//	return (true);
//}
//
//bool	plane_set(t_object *list, char **arg_tab)
//{
//	list->type = PLAN;
//	if (get_coor(list->center_coor, arg_tab[1]) == false)
//		return (false);
//	if (get_vector(list->vector, arg_tab[2]) == false)
//		return (false);
//	if (get_rgb(list->rgb, arg_tab[3]) == false);
//		return (false);
//	return (true);
//}
//
//bool	sphere_set(t_object *list, char **arg_tab)
//{
//	list->type = SPHERE;
//	if (get_coor(list->center_coor, arg_tab[1]) == false)
//		return (false);
//	if (get_dimension(&(list->diameter), arg_tab[2]) == false)
//		return (false);
//	if (get_rgb(list->rgb, arg_tab[3]) == false);
//		return (false);
//	return (true);
//}
//
//bool	cylinder_set(t_object *list, char **arg_tab)
//{
//	list->type = CYLINDER;
//	if (get_coor(list->center_coor, arg_tab[1]) == false)
//		return (false);
//	if (get_vector(&(list->vector), arg_tab[2]) == false)
//		return (false);
//	if (get_dimension(&(list->height), arg_tab[2]) == false)
//		return (false);
//	if (get_dimension(&(list->diameter), arg_tab[2]) == false)
//		return (false);
//	if (get_rgb(list->rgb, arg_tab[5]) == false)
//		return (false);
//	return (true);
//}
