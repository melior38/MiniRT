/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:28:51 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/09/28 16:08:27 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

//gnl.c
char	*get_next_line(int fd);
int		read_buffer(char *buffer);
void	free_buffer(char **buffer, int fd);
int		read_line(char **line, int fd, int i);
//gnl_utils.c
char	*ft_strlendup(const char *s, int i);
size_t	ft_strlcpys(char *dst, const char *src, size_t dstsize);
char	*ft_strlenjoin(char const *s1, char const *s2, int i);
#endif