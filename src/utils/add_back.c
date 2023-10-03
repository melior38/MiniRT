/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/03 14:16:24 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	pl_addb(t_plane **lst, t_plane *new)
{
	t_plane	*current;
	static int i;

	if (!i)
		i = 0;
	if (i == 0)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	sp_addb(t_sphere **lst, t_sphere *new)
{
	t_sphere	*current;
	static int i;

	if (!i)
		i = 0;
	if (i == 0)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	cyl_addb(t_cylinder **lst, t_cylinder *new)
{
	t_cylinder	*current;
	static int i;

	if (!i)
		i = 0;
	if (i == 0)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
