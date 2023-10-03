/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/11 13:48:30 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	free_camera(t_camera *camera)
{
	free(camera->coor);
	camera->coor = NULL;
	free(camera->vector);
	printf("fov camera address [%p]\n", &camera->fov);
	camera->vector = NULL;
}

void	free_light(t_light *light)
{
	free(light->coor);
	light->coor = NULL;
	free(light->rgb);
	light->rgb = NULL;
	printf("bright light address [%p]\n", &light->bright);
}
