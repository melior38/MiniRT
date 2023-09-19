/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:05:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/13 09:23:59 by asouchet         ###   ########.fr       */
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

void redirect_function(void (*parse_struct)(t_param *, char **), t_param *param, char **s_line)
{
	parse_struct(param, s_line);
}

bool	check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] <= '9' && line >= '0') || line[i] == ' '
				|| line[i] == ',' || line[i] == '.')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	init_file(t_data *data, char *line)
{
	int i;
	char **s_line;

	i = 0;
	if (check_line(line) == false)
		return (false);
	s_line = ft_split(line, ' ');
	if (!ft_strncmp(line, 'A ', 2))
		redirect_function(Ambient_light_set(data->param, s_line), data->param, s_line);
	if (!ft_strncmp(line, 'C ', 2))
		redirect_function(Camera_set(data->param, s_line), data->param, s_line);
	if (!ft_strncmp(line, 'L ', 2))
		redirect_function(Light_set(data->param, s_line), data->param, s_line);
	if (!ft_strncmp(line, 'sp ', 3))
		redirect_function(spheres_set(data->param, s_line), data->param, s_line);
	if (!ft_strncmp(line, 'cy ', 3))
		redirect_function(cylinders_set(data->param, s_line), data->param, s_line);
	if (!ft_strncmp(line, 'pl ', 3))
		redirect_function(plane_set(data->param, s_line), data->param, s_line);
	if (data->param->error)
		return (false);
	return (true);
}

int parsing(t_data *data, int ac, char *av)
{
	int		fd;
	char	*line;

	fd = open_fd(ac, av);
	line = get_next_line(fd);
	while (line)
	{
		if (init_file(data, line) == false)
			return (2);
		// printf("%s", line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	return (0);
}
