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
	t_plane *lst;
	t_plane *lst_tmp;

	lst = param->plane;
	while (lst)
	{
		lst_tmp = lst->next;
		free(lst->coor);
		if (lst->vector)
			free(lst->vector);
		if (lst->rgb)
			free(lst->rgb);
		free(lst);
		lst = lst_tmp;
	}
	param->plane = NULL;
}

void	free_sphere(t_param *param)
{
	t_sphere	*lst;
	t_sphere	*lst_tmp;

	lst = param->sphere;
	while (lst)
	{
		lst_tmp = lst->next;
		free(lst->coor);
		if (lst->rgb)
			free(lst->rgb);
		free(lst);
		lst = lst_tmp;
	}
	param->sphere = NULL;
}

void	free_cylinder(t_param *param)
{
	t_cylinder	*lst;
	t_cylinder	*lst_tmp;

	lst = param->cylinder;
	while (lst)
	{
		lst_tmp = lst->next;
		free(lst->coor);
		if (lst->vector)
			free(lst->vector);
		if (lst->rgb)
			free(lst->rgb);
		free(lst);
		lst = lst_tmp;
	}
	param->cylinder = NULL;
}
