/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/09/11 13:48:30 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//Ajouter des macro de couleur pour que ce soit plus clair (constante)
int	print_error(char *msg, int code)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (code);
}
/// Check args and open it
/// \param ac number of args
/// \param av args
int	open_fd(int ac, char **av)
{
	int		fd;
	int 	i;

	if (ac != 2)
		return (print_error("Usage ./minirt example\n",ERROR));
	i = ft_strlen(av[1]);
	if (ft_strncmp(av[1] + i - 3, ".rt", 4))
		return (print_error("Only .rt are allowed\n", ERROR));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_error("Open the noor pls\n", ERROR));
	return (fd);
}