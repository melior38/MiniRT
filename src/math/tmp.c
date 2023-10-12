/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/05 13:15:03 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	lstadd_back(t_listobj **lst, t_listobj *new)
{
	t_listobj *current;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	parse_cylinder(t_data *data, char **line)
{
	t_listobj	*object;

	object = malloc(sizeof(t_listobj));
	if (!object)
		return ;
	object->type = CYLINDER;
	object->ptr = create_cylinder(data, line);
	object->next = NULL;
	lstadd_back(&data->obj, object);
}

void	parse_plane(t_data *data, char **line)
{
	t_listobj	*object;

	object = malloc(sizeof(t_listobj));
	if (!object)
		return ;
	object->type = PLANE;
	object->ptr = create_plane(data, line);
	object->next = NULL;
	lstadd_back(&data->obj, object);
}

void	parse_sphere(t_data *data, char **line)
{
	t_listobj	*object;

	object = malloc(sizeof(t_listobj));
	if (!object)
		return ;
	object->type = SPHERE;
	object->ptr = create_sphere(data, line);
	object->next = NULL;
	lstadd_back(&data->obj, object);
}