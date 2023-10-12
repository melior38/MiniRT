/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_uobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/11 11:03:25 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	free_camera(t_camera *camera)
{
	free(camera);
}

void	free_light(t_light *light)
{
	free(light);
}
