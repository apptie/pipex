/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:04:20 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/22 17:39:36 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void		ft_free_malloc(char *s)
{
	if (s)
	{
		free(s);
		s = 0;
	}
}

int			ft_strdup_static(char **static_buff, int fd, char *s)
{
	char		*result;
	int			i;

	if (!s)
		return (0);
	if (!(result = malloc(ft_strlen(s) + 1)))
	{
		ft_free_malloc(static_buff[fd]);
		return (-1);
	}
	i = -1;
	while (s[++i])
		result[i] = s[i];
	result[i] = 0;
	static_buff[fd] = result;
	return (1);
}

int			ft_strdup_line(char **line, char *s)
{
	char	*result;
	int		i;

	if (!s)
		return (0);
	if (!(result = malloc(ft_strlen(s) + 1)))
	{
		ft_free_malloc(*line);
		return (-1);
	}
	i = -1;
	while (s[++i])
		result[i] = s[i];
	result[i] = 0;
	*line = result;
	return (1);
}
