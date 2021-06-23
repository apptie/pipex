/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:32:08 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/23 14:17:35 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int			ft_stdin(const char *file);
int			ft_stdout(const char *file);

char		**ft_split(char const *s, char c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(char *s);

void		ft_free(char **target);
void		ft_process_dup2(int pipe_fd[2], int io);
int			ft_split_length(char **target);
void		ft_check_cmd(char **cmd_split);

#endif
