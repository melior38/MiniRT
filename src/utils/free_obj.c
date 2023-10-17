/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/17 13:03:22 by asouchet         ###   ########.fr       */
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
	free(param->pl_head);
	param->pl_head = NULL;
}

void	free_sphere(t_param *param)
{
	t_sphere	*lst;
	t_sphere	*lst_tmp;

	lst = param->sphere;
	while (lst)
	{
		lst_tmp = lst->next;
		free(lst);
		lst = lst_tmp;
	}
	param->sphere = NULL;
	free(param->sp_head);
	param->sp_head = NULL;
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
	free(param->cy_head);
	param->cy_head = NULL;
}
