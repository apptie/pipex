/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:52:25 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/22 17:38:27 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_set_static(char **static_buff, int fd, char *buff)
{
	char	*result;
	int		i;
	int		j;

	if (!static_buff[fd])
	{
		if (ft_strdup_static(static_buff, fd, buff) < 0)
			return (-1);
		return (1);
	}
	i = -1;
	j = 0;
	if (!(result = malloc(ft_strlen(static_buff[fd]) + ft_strlen(buff) + 1)))
	{
		ft_free_malloc(static_buff[fd]);
		return (-1);
	}
	while (static_buff[fd][++i])
		result[i] = static_buff[fd][i];
	free(static_buff[fd]);
	while (buff[j])
		result[i++] = buff[j++];
	result[i] = 0;
	static_buff[fd] = result;
	return (1);
}

int		ft_set_line(char **static_buff, int fd, int buff_idx, char **line)
{
	char	*tmp_line;
	int		length;

	static_buff[fd][buff_idx] = 0;
	if (ft_strdup_line(line, static_buff[fd]) < 0)
		return (-1);
	length = ft_strlen(static_buff[fd] + buff_idx + 1);
	if (!length)
	{
		free(static_buff[fd]);
		static_buff[fd] = 0;
	}
	else
	{
		if (ft_strdup_line(&tmp_line, static_buff[fd] + buff_idx + 1) < 0)
			return (-1);
		free(static_buff[fd]);
		static_buff[fd] = tmp_line;
	}
	return (1);
}

int		ft_check_newline(char *static_buff)
{
	int		i;

	i = 0;
	while (static_buff[i])
	{
		if (static_buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_check_static(char **static_buff, int fd, char **line)
{
	int	buff_idx;

	buff_idx = 0;
	if (static_buff[fd] &&
			((buff_idx = ft_check_newline(static_buff[fd])) >= 0))
		return (ft_set_line(static_buff, fd, buff_idx, line));
	else if (static_buff[fd])
	{
		if (ft_strdup_line(line, static_buff[fd]) < 0)
			return (-1);
		free(static_buff[fd]);
		static_buff[fd] = 0;
	}
	else
	{
		if (ft_strdup_line(line, "") < 0)
			return (-1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*static_buff[256];
	int				read_size;
	int				buff_idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = 0;
		if (ft_set_static(static_buff, fd, buff) < 0)
			return (-1);
		buff_idx = 0;
		while (static_buff[fd][buff_idx])
		{
			if (static_buff[fd][buff_idx] == '\n')
				return (ft_set_line(static_buff, fd, buff_idx, line));
			buff_idx++;
		}
	}
	if (read_size >= 0)
		return (ft_check_static(static_buff, fd, line));
	return (read_size);
}
