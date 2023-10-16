/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/16 16:09:47 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	pl_addb(t_plane **lst, t_plane *new, t_plane *pl_head)
{
	t_plane	*current;

	if (*lst == NULL)
	{
		*lst = new;
		pl_head = new;
	}
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	sp_addb(t_sphere **lst, t_sphere *new, t_sphere *sp_head)
{
	t_sphere	*current;

	if (*lst == NULL)
	{
		*lst = new;
		sp_head = new;
	}
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	cyl_addb(t_cylinder **lst, t_cylinder *new, t_cylinder *cy_head)
{
	t_cylinder	*current;

	if (*lst == NULL)
	{
		*lst = new;
		cy_head = lst;
	}
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
