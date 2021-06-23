/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:19:57 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/23 16:44:30 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char *path_s, char *cmd)
{
	char	**path_split;
	char	*s1;
	char	*s2;
	int		i;

	if (!(path_split = ft_split(path_s, ':')))
	{
		write(STDERR_FILENO, "ft_split error.\n", 16);
		exit(0);
	}
	i = 0;
	while (path_split[i])
	{
		s1 = ft_strjoin(path_split[i++], "/");
		s2 = ft_strjoin(s1, cmd);
		free(s1);
		if (access(s2, F_OK) == 0)
		{
			ft_free(path_split);
			return (s2);
		}
		free(s2);
	}
	ft_free(path_split);
	return (cmd);
}

void	ft_exec_cmd(char *cmd, char *path_s)
{
	char	*path;
	char	**cmd_split;

	if (!(cmd_split = ft_split(cmd, ' ')))
	{
		write(STDERR_FILENO, "ft_split error.\n", 16);
		exit(0);
	}
	path = ft_get_path(path_s, cmd_split[0]);
	if (ft_strcmp(cmd_split[0], "tr") == 0)
		ft_check_cmd(cmd_split);
	execve(path, cmd_split, 0);
	free(path);
	free(cmd_split);
	write(STDERR_FILENO, "Command error : ", 16);
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, "\n", 1);
	exit(0);
}

void	ft_process_redirect(char *cmd, char *path_s)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		write(STDERR_FILENO, "pipe error.\n", 12);
		exit(0);
	}
	pid = fork();
	if (pid)
	{
		ft_process_dup2(pipe_fd, STDIN_FILENO);
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		ft_process_dup2(pipe_fd, STDOUT_FILENO);
		close(pipe_fd[0]);
		ft_exec_cmd(cmd, path_s);
	}
}

int		main(int argc, char *argv[], char *envp[])
{
	int	i;

	if (argc != 5)
	{
		write(STDERR_FILENO, "Wrong arguments.\n", 17);
		return (0);
	}
	if (ft_stdout(argv[4]) == -1 || ft_stdin(argv[1]) == -1)
		return (0);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	ft_process_redirect(argv[2], envp[i] + 5);
	ft_exec_cmd(argv[3], envp[i] + 5);
	return (0);
}
