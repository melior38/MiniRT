/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:02:09 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/19 14:48:16 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

// void	init_tab(int *tab)
// {
// 	if (!tab[0])
// 		tab[0] = 0;
// 	if (!tab[1])
// 		tab[1] = 0;
// 	if (!tab[2])
// 		tab[2] = 0;
// 	if (!tab[3])
// 		tab[3] = 0;
// 	if (!tab[4])
// 		tab[4] = 0;
// 	if (!tab[5])
// 		tab[5] = 0;
// 	return ;
// }

// int	tab_check(int *tab)
// {
// 	if (tab[0] > 1)
// 		return (1);
// 	if (tab[1] > 1)
// 		return (1);
// 	if (tab[2] > 1)
// 		return (1);
// 	if (tab[3] > 1)
// 		return (1);
// 	if (tab[4] > 1)
// 		return (1);
// 	if (tab[5] > 1)
// 		return (1);
// 	return (0);
// }

// int	init_file(t_data *data, char *line)
// {
// 	int	tab[6];
// 	char **splited_line;

// 	init_tab(tab);
// 	splited_line =	ft_split(line, ' ');
// 	if (!strcmp(splited_line[0], "A"))
// 	{
// 		if (Ambient_light_set(data->param->A_light, splited_line))
// 			return (1);
// 		tab[0] += 1;
// 	}	
// 	if (!strcmp(splited_line[0], "C"))
// 	{
// 		if (Camera_set(data->param->camera, splited_line))
// 			return (1);
// 		tab[1] += 1;
// 	}
// 	if (!strcmp(splited_line[0], "L"))
// 	{
// 		if (Light_set(data->param->light, splited_line))
// 			return (1);
// 		tab[2] += 1;
// 	}
// 	if (!strcmp(splited_line[0], "pl"))
// 	{
// 		if (plane_set(data->param->plane, splited_line))
// 			return (1);
// 		tab[3] += 1;
// 	}
// 	if (!strcmp(splited_line[0], "sp"))
// 	{
// 		if (sphere_set(data->param->spheres, splited_line))
// 			return (1);
// 		tab[4] += 1;
// 	}
// 	if (!strcmp(splited_line[0], "cy"))
// 	{
// 		if (cylinder_set(data->param->cylinders, splited_line))
// 			return (1);
// 		tab[5] += 1;
// 	}
// 	if (tab_check(tab))
// 		return (1);
// 	// free_tab(splited_line);
// 	return (0);
// }

typedef struct s_sphere {
	t_axis	*sp_center;
	float	radius;
	t_rgb	*colour;

}				t_sphere;

typedef struct s_plane {
	t_axis	*pl_coor;
	t_axis	*vector;
	t_rgb	*rgb;

}				t_plane;

typedef struct s_cylinder {
	t_axis	*cy_center;
	t_axis	*vector;
	float	diameter;
	float	height;
	t_rgb	*rgb;

}				t_cylinder;

typedef struct s_light {
	t_axis	*view_point;
	float	brightness;
	t_rgb	*rgb;

}				t_light;

typedef struct s_ambient_light {
	t_rgb	*rgb;
	float	light_ratio;

}				t_ambient_light;

typedef struct s_camera {
	t_axis	*view_coor;
	t_axis	*vector;
	int		FOV;

}				t_camera;
