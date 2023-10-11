/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:27:41 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/11 13:23:49 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// set the width and the heigth and also get the center point and the up_left point
// wich is the point on pixel x = 0 and y = 0
void	init_camera(t_camera *camera)
{
	double	win_ratio;

	//attention au sens des vecteur!!!!!!
	camera->ref = set_ref(camera->vector);
	camera->width = tan(camera->fov / 2 * M_PI / 180);
	win_ratio = (double)WIDTH / (double)HEIGTH;
	camera->heigth = camera->width / win_ratio;
	camera->center = add_vec(camera->coor, camera->ref.dir);
	camera->up_left = add_vec(subs_vec(camera->center, scale_vec(camera->ref.right, \
		camera->width / 2.0)), scale_vec(camera->ref.up, camera->heigth / 2.0));
}