/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/04 09:53:56 by asouchet         ###   ########.fr       */
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
	int	i;

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
		data->alight = create_alight(data, s_line);
	if (ft_strncmp(line, "C ", 2) == 0)
		data->camera = create_camera(data, s_line);
	if (ft_strncmp(line, "L ", 2) == 0)
		data->light = create_light(data, s_line);
	if (ft_strncmp(line, "sp ", 3) == 0)
		parse_sphere(data, s_line);
	if (ft_strncmp(line, "pl ", 3) == 0)
		parse_plane(data, s_line);
	if (ft_strncmp(line, "cy ", 3) == 0)
		parse_cylinder(data, s_line);
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
	while (line)
	{
		line = trim_gnl(line);
		init_file(data, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	return (1);
}
