/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/11/09 14:46:34 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

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
	free_tab(s_line);
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
		return (NULL);
	free(dup);
	dup = NULL;
	return (res);
}

t_param	*init_param(void)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->alight = NULL;
	param->camera = NULL;
	param->light = NULL;
	param->cylinder = NULL;
	param->plane = NULL;
	param->sphere = NULL;
	return (param);
}

int	check_param(t_param *param)
{
	if (!param->alight)
		return (1);
	if (!param->camera)
		return (1);
	if (!param->light)
		return (1);
	return (0);
}

/// Recupere le fd via la fonction open_fd et creer les objects
/// \param data structure principal
/// \param ac nb d'arguments
/// \param av args
/// \return a voir
int	parsing(t_data *data, int ac, char *av)
{
	int		fd;
	char	*line;

	fd = open_fd(data, ac, av);
	line = get_next_line(fd);
	data->param = init_param();
	while (line)
	{
		line = trim_gnl(line);
		if (check_line(line))
			print_error(data, "Tabs in .rt\n");
		init_file(data, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	if (check_param(data->param))
		print_error(data, "missing key argument(s) A / C or L");
	return (1);
}
