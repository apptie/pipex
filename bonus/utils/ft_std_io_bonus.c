/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_io_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:50:44 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/23 00:02:19 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_stdin(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		write(STDERR_FILENO, "ft_stdin error.\n", 16);
		return (-1);
	}
	close(fd);
	return (0);
}

int	ft_stdout(const char *file, int flag)
{
	int	fd;

	if (flag)
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		write(STDERR_FILENO, "ft_stdout error.\n", 17);
		return (-1);
	}
	close(fd);
	return (0);
}
