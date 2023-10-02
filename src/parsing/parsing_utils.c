/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/28 15:36:49 by asouchet         ###   ########.fr       */
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

bool	check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] <= '9' && line[i] >= '0') || line[i] == ' '
				|| line[i] == ',' || line[i] == '.')
			i++;
		else
			return (false);
	}
	return (true);
}

void	init_file(t_data *data, char *line)
{
	char	**s_line;

	s_line = ft_split(line, ' ');
	if (ft_strncmp(line, "A ", 2) == 0)
		data->param->alight = create_alight(data, s_line);
	if (ft_strncmp(line, "C ", 2) == 0)
		data->param->camera = create_camera(data, s_line);
	if (ft_strncmp(line, "L ", 2) == 0)
		data->param->light = create_light(data, s_line);
	if (ft_strncmp(line, "sp ", 3) == 0)
		sp_addb(&data->param->sphere, create_sphere(data, s_line));
	if (ft_strncmp(line, "pl ", 3) == 0)
		pl_addb(&data->param->plane, create_plane(data, s_line));
	if (ft_strncmp(line, "cy ", 3) == 0)
		cyl_addb(&data->param->cylinder, create_cylinder(data, s_line));
}

char	*trim_gnl(char *line)
{
	char	*res;
	char	*dup;

	dup = ft_strdup(line);
	if (line == NULL)
		return (NULL);
	free(line);
	line = NULL;
	res = ft_strtrim(dup, "\n");
	if (res == NULL)
		return NULL;
	free(dup);
	dup = NULL;
	return (res);
}

/// Recupere le fd via la fonction open_fd et creer les objects
/// \param data structure principal
/// \param ac nb d'arguments
/// \param av args
/// \return a voir
int parsing(t_data *data, int ac, char *av)
{
	int		fd;
	char	*line;
	t_param	*param;

	fd = open_fd(ac, av);
	line = get_next_line(fd);
	param = malloc(sizeof(t_param));
	if (!param)
		exit(1); // a mieux faire mais la je suis pas sur ce soucis la
	param->cylinder = NULL;
	param->plane = NULL;
	param->sphere = NULL;
	data->param = param;
	while (line)
	{
		printf("error [%d] line [%.*s]\n", data->error, (int)ft_strlen(line)
		- 1,line);
		line = trim_gnl(line);
		init_file(data, line);
		if (data->error != 0)
		{
			ft_printf("Error...\n"); //A coder une sortie d'erreur
			free(line);
			return(0);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	return (1);
}
