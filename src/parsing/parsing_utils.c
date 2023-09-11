/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/11 08:10:53 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	check_rt_file(char *av)
{
	int	i;
	int	check;

	check = 1;
	i = 0;
	while (av[i])
		i++;
	i = i - 4;
	if (av[i] != '.')
		i++;
	else
		return (check);
	if (av[i] == '.')
	{
		i++;
		if (av[i] == 'r')
			{
				i++;
				if (av[i] == 't')
					check = 0;
			}
	}
	return (check);
}

void	init_tab(int *tab)
{
	if (!tab[0])
		tab[0] = 0;
	if (!tab[1])
		tab[1] = 0;
	if (!tab[2])
		tab[2] = 0;
	if (!tab[3])
		tab[3] = 0;
	if (!tab[4])
		tab[4] = 0;
	if (!tab[5])
		tab[5] = 0;
	return ;
}

int	tab_check(int *tab)
{
	if (tab[0] > 1)
		return (1);
	if (tab[1] > 1)
		return (1);
	if (tab[2] > 1)
		return (1);
	if (tab[3] > 1)
		return (1);
	if (tab[4] > 1)
		return (1);
	if (tab[5] > 1)
		return (1);
	return (0);
}

	// le but est de checker tout les parametres 1 fois et dans n'importe quel ordre
	// donc sa implique un strcmp sur les 2 premier char (on peut peut etre split le resultat et ducoup strncmp le premier tab)
	// puis faire une foret de if pour tout les cas puis ensuite apres un passage initialiser une var qui confirme le passage dans le if
int	init_file(t_data *data, char *line)
{
	int	tab[6];
	char **splited_line;

	init_tab(tab);
	splited_line =	ft_split(line, ' ');
	if (!strcmp(splited_line[0], "A"))
	{
		if (Ambient_light_set(data->param->A_light, splited_line))
			return (1);
		tab[0] += 1;
	}	
	if (!strcmp(splited_line[0], "C"))
	{
		if (Camera_set(data->param->camera, splited_line))
			return (1);
		tab[1] += 1;
	}
	if (!strcmp(splited_line[0], "L"))
	{
		if (Light_set(data->param->light, splited_line))
			return (1);
		tab[2] += 1;
	}
	if (!strcmp(splited_line[0], "pl"))
	{
		if (plane_set(data->param->plane, splited_line))
			return (1);
		tab[3] += 1;
	}
	if (!strcmp(splited_line[0], "sp"))
	{
		if (sphere_set(data->param->spheres, splited_line))
			return (1);
		tab[4] += 1;
	}
	if (!strcmp(splited_line[0], "cy"))
	{
		if (cylinder_set(data->param->cylinders, splited_line))
			return (1);
		tab[5] += 1;
	}
	if (tab_check(tab))
		return (1);
	// free_tab(splited_line);
	return (0);
}

// changer les noms de fonctions c illisible bruh?
int parsing(t_data *data, char *av)
{
	int		fd;
	char	*line;

	if (check_rt_file(av))
		return (1);
	fd = open(av, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (init_file(data, line))
			return (2);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	return (0);
}
