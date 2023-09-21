/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:51:24 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/20 12:59:23 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// le centre de ma window est a (x = 0, y = 0, z = d)
// c'est un bonne indice pour la suite 
// d est une distance qu'on definie a l'avance en l'occurence ce sera probablement 1
// donc pour identifier le centre suffit de recup les donner de la cam et de rajouter d au z pour avoir le centre de la fennetre
// donc il faut recuperer le pixel du centre de la fennetre et lui donner la coor du centre de la window
// ensuite on cree un scale des coor en fonction du nombre de pixel


void	ft_minirt(t_object *list ,int x, int y)
{
	t_object *tmp;

	tmp = list;
	while (tmp->type != CAMERA)
		tmp = tmp->next;
	return ;
}