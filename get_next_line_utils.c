/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:57:33 by mjhin             #+#    #+#             */
/*   Updated: 2021/11/29 14:06:17 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_str_stat(char *str_stat)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	while (str_stat[i] && str_stat[i] != '\n' )
		i++;
	if (!str_stat[i])
	{
		free(str_stat);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(str_stat) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (str_stat[i])
		s[j++] = str_stat[i++];
	s[j] = '\0';
	free(str_stat);
	return (s);
}

char	*ft_get_line(char *str_stat)
{
	size_t	i;
	char	*s;

	if (!str_stat[0])
		return (NULL);
	i = 0;
	while (str_stat[i] && str_stat[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str_stat[i] && str_stat[i] != '\n')
	{
		s[i] = str_stat[i];
		i++;
	}
	if (str_stat[i] == '\n')
	{
		s[i] = str_stat[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		new_s[i] = s1[i];
	while (s2[j] != '\0')
		new_s[i++] = s2[j++];
	new_s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new_s);
}
