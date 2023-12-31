/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/11/09 14:46:26 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	free_param(t_param *param)
{
	if (param->alight)
	{
		free(param->alight);
		param->alight = NULL;
	}
	if (param->camera)
		free_camera(param->camera);
	if (param->light)
		free_light(param->light);
	if (param->plane)
		free_plane(param);
	if (param->sphere)
		free_sphere(param);
	if (param->cylinder)
		free_cylinder(param);
	free(param);
	param = NULL;
}

int	free_struct(t_data *data)
{
	free_param(data->param);
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->img);
	data->img = NULL;
	free(data->addr);
	data->addr = NULL;
	exit(0);
}
