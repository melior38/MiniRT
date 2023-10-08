/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/05 13:15:03 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

/// Create t_pos
/// \param x value of x
/// \param y value of y
/// \param z value of z
/// \return t_pos with all the value
t_pos	*create_pos(double x, double y, double z)
{
	t_pos	*tmp;

	tmp = malloc(sizeof(t_pos));
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	return (tmp);
}

/// Create t_ray
/// \param origin origin point x,y,z
/// \param direction direction point x,y,z
/// \return t_ray with both coordinates
t_ray	*create_ray(t_pos *origin, t_pos *direction)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

///Substracte vector1 and 2 for a third one
/// \param vec1
/// \param vec2
/// \return result of subtraction
t_pos	*substract(t_pos *vec1, t_pos *vec2)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = vec1->x - vec2->x;
	result->y = vec1->y - vec2->y;
	result->z = vec1->z - vec2->z;
	return (result);
}

/// Allow to swap double
/// \param a pointer to a
/// \param b pointer to b
void	swap_doubles(double *a, double *b)
{
	double	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

/// Get the value from rgb to HEX
/// \param r red code
/// \param g green code
/// \param b blue code
/// \return HEX
unsigned long	creatergb(t_rgb *rgb)
{
	return (((rgb->r & 0xff) << 16) + ((rgb->g & 0xff) << 8) + (rgb->b & 0xff));
}
