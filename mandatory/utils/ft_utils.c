/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:06:38 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/23 14:14:13 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **target)
{
	int	i;

	i = 0;
	if (target)
	{
		while (target[i])
		{
			free(target[i]);
			target[i] = 0;
			i++;
		}
		free(target);
		target = 0;
	}
}

void	ft_process_dup2(int pipe_fd[2], int io)
{
	if (dup2(pipe_fd[io], io) == -1)
	{
		write(STDERR_FILENO, "dup2 error.\n", 12);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(0);
	}
}

int		ft_split_length(char **target)
{
	int	i;

	i = 0;
	while (target[i])
		i++;
	return (i);
}

void	ft_check_cmd(char **cmd_split)
{
	if (ft_split_length(cmd_split) == 4 &&
			ft_strcmp(cmd_split[2], "'") == 0 &&
			ft_strcmp(cmd_split[3], "'") == 0)
	{
		cmd_split[2] = "' '";
		cmd_split[3] = 0;
	}
}
