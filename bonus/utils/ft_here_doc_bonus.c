/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:08:09 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/23 16:45:09 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_clear_tmp(void)
{
	char	*argv[4];

	argv[0] = "rm";
	argv[1] = "-f";
	argv[2] = "./temp";
	argv[3] = 0;
	if (fork() == 0)
		execve("/bin/rm", argv, 0);
}

int			ft_heredoc_stdin(char *limiter)
{
	int		fd;
	char	*buff;

	buff = NULL;
	if ((fd = open("./temp", O_CREAT | O_RDWR |
					O_TRUNC, 0644)) == -1)
	{
		write(STDERR_FILENO, "ft_heredoc_stdin error.\n", 24);
		return (-1);
	}
	write(STDOUT_FILENO, "pipe heredoc> ", 14);
	while (get_next_line(STDIN_FILENO, &buff) != 0)
	{
		if (ft_strcmp(buff, limiter) == 0)
			break ;
		write(STDOUT_FILENO, "pipe heredoc> ", 14);
		write(fd, buff, ft_strlen(buff));
		write(fd, "\n", 1);
	}
	close(fd);
	if (ft_stdin("./temp") == -1)
		return (-1);
	ft_clear_tmp();
	return (1);
}
