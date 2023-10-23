/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:43 by asouchet          #+#    #+#             */
/*   Updated: 2023/10/02 08:46:47 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int		allowed_symbol(char c)
{
	if (c == ' ' | c == '\n' | c == '.' || c == ',' ||
		(c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') || c == '-')
		return (1);
	return (0);
}

int		check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!allowed_symbol(line[i]))
			return (1);
		i++;
	}
	return (0);
}