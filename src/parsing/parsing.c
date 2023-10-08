/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/03 16:06:24 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//Ajouter des macro de couleur pour que ce soit plus clair (constante)
void	print_error(t_data	*data, char *msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	free_struct(data);
	exit (1);
}

/// Check args and open it
/// \param ac number of args
/// \param av args
int	open_fd(t_data *data, int ac, char *av)
{
	int		fd;
	size_t	i;

	if (ac != 2)
		print_error(data, "Usage ./minirt example\n");
	i = ft_strlen(av);
	if (ft_strncmp(av + i - 3, ".rt", 4))
		print_error(data, "Only .rt are allowed\n");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		print_error(data, "Open the noor pls\n");
	return (fd);
}
