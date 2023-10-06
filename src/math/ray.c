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

t_pos *create_pos(double x, double y, double z)
{
	t_pos *tmp;

	tmp = NULL;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	return (tmp);
}

t_ray *create_ray(t_pos *origin, t_pos *direction)
{
	t_ray *ray;

	ray = NULL;
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

t_ray *ray_to_pixel(int x, int y)
{
	double	aspect_ratio;
	double 	p_x;
	double 	p_y;
	t_ray	*result;
	t_pos 	*direction;

	aspect_ratio = (double)WIDTH / (double)HEIGTH;
	p_x = (2 * (x + 0.5) / (double)WIDTH - 1) * aspect_ratio;
	p_y = (1 - 2 * (y + 0.5) / (double)HEIGTH);
	direction = create_pos(p_x, p_y, -1);
	normed_vec(direction);
	result = create_ray(create_pos(0,0,0), direction);
	return (result);
}

int intersect_sphere(t_ray *ray, t_sphere *sphere)
{

}

void	shoot_ray(t_data *data)
{
	t_sphere	*sphere;
	t_ray 		*sent;
	int			x;
	int			y;

	sphere = data->param->sphere;
	sphere->center = sphere->coor;
	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			sent = ray_to_pixel(x, y);
			if (intersect_sphere(sent, sphere))
				mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0xfffafa);
			x++;
		}
		y++;
	}
}