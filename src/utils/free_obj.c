/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/11 11:03:48 by asouchet         ###   ########.fr       */
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
		free(lst);
		lst = lst_tmp;
	}
	param->cylinder = NULL;
}
