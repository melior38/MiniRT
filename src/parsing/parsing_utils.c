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
		if ((line[i] <= '9' && line[i] >= '0') || line[i] == ' '
				|| line[i] == ',' || line[i] == '.')
			i++;
		else
			return (false);
	}
	return (true);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	init_file(t_data *data, char *line)
{
	int i;
	char **s_line;

	i = 0;
//	if (check_line(line) == false)
//		return (false);
	(void) data;
	s_line = ft_split(line, ' ');
	while (s_line[i])
	{
		printf("s_line[%d] [%s]\n", i, s_line[i]);
		i++;
	}
	if (ft_strcmp(s_line[0], "A") == 0)
		create_alight(ft_atod(s_line[1]), NULL);
}

int parsing(t_data *data, int ac, char *av)
{
	int		fd;
	char	*line;

	fd = open_fd(ac, av);
	line = get_next_line(fd);
	while (line)
	{
//		if (init_file(data, line) == false)
//			return (2);
		init_file(data, line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	return (0);
}
