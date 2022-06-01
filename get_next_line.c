/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:05:22 by mjhin             #+#    #+#             */
/*   Updated: 2021/11/29 13:58:36 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_str(int fd, char *str_stat)
{
	char	*mass;
	int		byte_read;

	mass = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!mass)
		return (NULL);
	byte_read = read(fd, mass, 0);
	if (byte_read == -1)
	{
		free(mass);
		return (NULL);
	}
	byte_read = 1;
	while (!ft_strchr(str_stat, '\n') && byte_read != 0)
	{
		byte_read = read(fd, mass, BUFFER_SIZE);
		mass[byte_read] = '\0';
		str_stat = ft_strjoin(str_stat, mass);
	}
	free(mass);
	return (str_stat);
}

char	*get_next_line(int fd)
{
	static char	*str_stat;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_stat = ft_read_str(fd, str_stat);
	if (!str_stat)
		return (NULL);
	line = ft_get_line(str_stat);
	str_stat = ft_str_stat(str_stat);
	return (line);
}
