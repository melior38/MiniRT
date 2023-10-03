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

void	free_plane(t_param *param)
{
	while (param->plane)
	{
		free(param->plane->coor);
		param->plane->coor = NULL;
		free(param->plane->vector);
		param->plane->vector = NULL;
		free(param->plane->rgb);
		param->plane->rgb = NULL;
		free(param->plane);
		param->plane = NULL;
		param->plane = param->plane->next;
	}
}

void	free_sphere(t_param *param)
{
	while (param->sphere)
	{
		free(param->sphere->coor);
		param->sphere->coor = NULL;
		free(param->sphere->rgb);
		param->sphere->rgb = NULL;
		free(param->sphere);
		param->sphere = NULL;
		param->sphere = param->sphere->next;
	}
}

void	free_cylinder(t_param *param)
{
	while (param->cylinder)
	{
		free(param->cylinder->coor);
		param->cylinder->coor = NULL;
		free(param->cylinder->vector);
		param->cylinder->vector = NULL;
		free(param->cylinder->rgb);
		param->cylinder->rgb = NULL;
		free(param->cylinder);
		param->cylinder = NULL;
		param->cylinder = param->cylinder->next;
	}
}
