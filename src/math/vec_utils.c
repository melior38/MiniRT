/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:57:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/23 14:31:44 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MiniRT.h"


// donne la norm d'un vecteur (sa longueur)
double	vec_norm(t_axis vec)
{
	return (sqrt(pow(vec.x, 2)+ pow(vec.y, 2) + pow(vec.z, 2)));
}

// donne la version du vecteur normer
void	normed_vec(t_axis *vec)
{
	double norm;

	norm = vec_norm(*vec);
	vec->x /= norm;
	vec->y /= norm;
	vec->z /= norm;
}

// le cross product nous permet de recuperer les vecteur referentielle
t_axis	cross_product(t_axis vec1, t_axis vec2)
{
	t_axis	res;
	
	res.x = vec1.y * vec2.z - vec1.z * vec2.y;
	res.y = vec1.z * vec2.x - vec1.x * vec2.z;
	res.z = vec1.x * vec2.y - vec1.y * vec2.x;
    return (res);
}

// addition de 2 vecteur et return le resultat
t_axis	add_vec(t_axis vec1, t_axis vec2)
{
	t_axis res;

	res.x = vec1.x + vec2.x;
	res.y = vec1.y + vec2.y;
	res.z = vec1.z + vec2.z;
	return (res);
}

// soustraction de 2 vecteur et return le resultat attention au sens
t_axis	subs_vec(t_axis vec1, t_axis vec2)
{
	t_axis res;

	res.x = vec1.x - vec2.x;
	res.y = vec1.y - vec2.y;
	res.z = vec1.z - vec2.z;
	return (res);
}

// le scaling d'un vecteur 
t_axis	scale_vec(t_axis vec, double scaling)
{
	t_axis res;

	res.x = vec.x * scaling;
	res.x = vec.y * scaling;
	res.x = vec.z * scaling;
	return (res);
}