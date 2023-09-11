/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:08:26 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/11 13:52:17 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

bool	get_vector(t_axis *axis, char *str)
{
	axis->x = coor_convertor(arg_tab[1], 'x');
	axis->y = coor_convertor(arg_tab[1], 'y');
	axis->z = coor_convertor(arg_tab[1], 'z');
	if (axis->x == 123.123001 || axis->x == 123.123001
			 || axis->x == 123.123001)
		return (false);
	else if ((axis->x < -1.0 || axis->x > 1.0) || 
			(axis->y < -1.0 || axis->y > 1.0) ||
			(axis->z < -1.0 || axis->z > 1.0))
		return (false);
	return (true);
}

bool	get_coor(t_axis *axis, char *str)
{
	axis->x = coor_convertor(str, 'x');
	axis->y = coor_convertor(str, 'y');
	axis->z = coor_convertor(str, 'z');
	if (axis->x == 123.123001 || axis->x 
			== 123.123001 || axis->x == 123.123001)
		return (false);
	else if ((axis->x < -1.0 || axis->x > 1.0) || 
			(axis->y < -1.0 || axis->y > 1.0) || 
			(axis->z < -1.0 || axis->z > 1.0))
		return (false);
	return (true);
}

bool	get_dimension(double *value, char *str)
{
	*value = ft_atod(str);
	if (*value > 1 || *value < 0 
			|| *value == 123.123001)
		return (false);
	return (true);
}

bool	get_rgb(t_rgb *rgb)
{
	rgb->r = rgb_convertor(str, 'r');
	rgb->g = rgb_convertor(str, 'g');
	rgb->b = rgb_convertor(str, 'b');
	if (rgb->r < 0 || rgb->g < 0 || rgb->b < 0)
		return (false);
	return (true);
}


