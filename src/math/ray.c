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

/// Creer un rayon et le renvoit
/// \param x coordoonnees x de la fenetre
/// \param y coordoonnees y de la fenetre
/// \return rayon sur les coordoonnes donne
t_ray	*ray_to_pixel(int x, int y, t_pos *coor)
{
	double	p_x;
	double	p_y;
	t_ray	*result;
	t_pos	*direction;
//	t_matrix	m;
	//Ajouter vec dir

	//normalized pixel x and y
	p_x = 2.0 * ((double)x / (double)WIDTH) - 1.0;
	p_y = 1.0 - 2.0 * ((double)y / (double)HEIGTH);
	//Creation vecteur directionnel
	direction = create_pos(p_x, p_y, -1);
	//init_matrix(ref, m);
	//Norme du vectuer directionnel
	//direction *= matrice_pos;
	normed_vec(direction);
	//Recupere les coor de la camera
	//Et le vecteur directionnel pour creer le rayon
	result = create_ray(create_pos(coor->x, coor->y, coor->z), direction);
	return (result);
}

int	intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	double	tca; 	//tangent closest approach.
	double	thc; 	//tangent hit distance
	double	d2;		//square distance between sphere center and tca
	double	t0;		//distance ray hit sphere
	double	t1;		//distance exit sphere
	t_pos	*l;

	l = substract(sphere->center, ray->origin);
	tca = dot_product(*l, *ray->direction);
	if (tca < 0)
		return (0);
	d2 = dot_product(*l, *l) - tca * tca;
	if (d2 > (sphere->radius * sphere->radius))
		return (0);
	thc = sqrt(sphere->radius * sphere->radius - d2);
	t0 = tca - thc;
	t1 = tca + thc;
	if (t0 > t1)
		swap_doubles(&t0, &t1);
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (0);
	}
	return (1);
}

void	shoot_ray(t_data *data)
{
	t_sphere		*sphere;
	t_ray			*sent;
	int				x;
	int				y;

	sphere = data->param->sphere;
	sphere->center = sphere->coor;
	//Creer matrice avec camera->vector, check vec operation
	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			//Creer le rayon
			sent = ray_to_pixel(x, y, data->param->camera->coor);
			//Check si le rayon a une sphere dans la trajectoire
			if (intersect_sphere(sent, sphere))
				mlx_pixel_put(data->mlx, data->mlx_win, x, y,
					(int)creatergb(sphere->rgb));
			x++;
		}
		y++;
	}
}
