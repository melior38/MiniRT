/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:46:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/28 10:47:24 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//Oui je sais, le tmp ne sert a rien sur alight, camera et light
//Jai juste copier coller par flemme
void	show_alight(t_data *data)
{
	t_alight	*tmp;

	tmp = data->param->alight;
	printf(WHITE);
	printf("ratio [%f]\n", tmp->ratio);
	printf(MAGENTA);
	printf("rgb [%d", tmp->rgb->r);
	printf(",%d,", tmp->rgb->g);
	printf("%d]\n", tmp->rgb->b);
	printf(RESET_COLOR);
}

void	show_camera(t_data *data)
{
	t_camera	*tmp;

	tmp = data->param->camera;
	printf(GREEN);
	printf("coords [%f", tmp->coor->x);
	printf(",%f,", tmp->coor->y);
	printf("%f]\n", tmp->coor->z);
	printf(CYAN);
	printf("vector [%f", tmp->vector->x);
	printf(",%f,", tmp->vector->y);
	printf("%f]\n", tmp->vector->z);
	printf(WHITE);
	printf("fov [%f]\n", tmp->fov);
	printf(RESET_COLOR);
}

void	show_light(t_data *data)
{
	t_light	*tmp;

	tmp = data->param->light;
	printf(GREEN);
	printf("coords [%f", tmp->coor->x);
	printf(",%f,", tmp->coor->y);
	printf("%f]\n", tmp->coor->z);
	printf(WHITE);
	printf("Brightness [%f]\n", tmp->bright);
	printf(MAGENTA);
	printf("rgb [%d", tmp->rgb->r);
	printf(",%d,", tmp->rgb->g);
	printf("%d]\n", tmp->rgb->b);
	printf(RESET_COLOR);
}

void	show_plane(t_data *data)
{
	t_plane	*tmp;
	int		i;

	tmp = data->param->plane;
	i = 1;
	while (tmp)
	{
		printf(WHITE);
		printf("id %d\n", i);
		printf(GREEN);
		printf("coords [%f", tmp->coor->x);
		printf(",%f,", tmp->coor->y);
		printf("%f]\n", tmp->coor->z);
		printf(CYAN);
		printf("vector [%f", tmp->vector->x);
		printf(",%f,", tmp->vector->y);
		printf("%f]\n", tmp->vector->z);
		printf(MAGENTA);
		printf("rgb [%d", tmp->rgb->r);
		printf(",%d,", tmp->rgb->g);
		printf("%d]\n", tmp->rgb->b);
		i++;
		tmp = tmp->next;
	}
	printf(RESET_COLOR);
}

void	show_sphere(t_data *data)
{
	t_sphere	*tmp;
	int			i;

	tmp = data->param->sphere;
	i = 1;
	while (tmp)
	{
		printf(WHITE);
		printf("id %d\n", i);
		printf(GREEN);
		printf("coords [%f", tmp->coor->x);
		printf(",%f,", tmp->coor->y);
		printf("%f]\n", tmp->coor->z);
		printf(WHITE);
		printf("diam [%f]\n", tmp->diam);
		printf(MAGENTA);
		printf("rgb [%d", tmp->rgb->r);
		printf(",%d,", tmp->rgb->g);
		printf("%d]\n", tmp->rgb->b);
		i++;
		tmp = tmp->next;
	}
	printf(RESET_COLOR);
}

void	show_cylinder(t_data *data)
{
	t_cylinder	*tmp;
	int			i;

	tmp = data->param->cylinder;
	i = 1;
	while (tmp)
	{
		printf(WHITE);
		printf("id %d\n", i);
		printf(GREEN);
		printf("coords [%f", tmp->coor->x);
		printf(",%f,", tmp->coor->y);
		printf("%f]\n", tmp->coor->z);
		printf(CYAN);
		printf("vector [%f", tmp->vector->x);
		printf(",%f,", tmp->vector->y);
		printf("%f]\n", tmp->vector->z);
		printf(WHITE);
		printf("diam [%f]\n", tmp->diam);
		printf(WHITE);
		printf("height [%f]\n", tmp->height);
		printf(MAGENTA);
		printf("rgb [%d", tmp->rgb->r);
		printf(",%d,", tmp->rgb->g);
		printf("%d]\n", tmp->rgb->b);
		i++;
		tmp = tmp->next;
	}
	printf(RESET_COLOR);
}
