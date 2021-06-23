/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:27:52 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/22 17:14:14 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static size_t	ft_count_word(char const *s, char charset)
{
	size_t count;

	count = 0;
	while (*s)
	{
		if (*s != charset)
		{
			count++;
			while (*s != charset && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char		*ft_set_array(char const *s, int start, int end)
{
	int		i;
	int		j;
	char	*array;

	if (!(array = (char *)malloc((end - start + 2) * sizeof(char))))
		return (0);
	i = start;
	j = 0;
	while (i < end)
		array[j++] = s[i++];
	array[j] = 0;
	return (array);
}

void			ft_set_result(char const *s, char c, char **ret, int ret_idx)
{
	int pos[2];
	int free_idx;

	pos[0] = 0;
	pos[1] = 0;
	free_idx = 0;
	while (s[pos[1]])
	{
		if (s[pos[1]] != c)
		{
			pos[0] = pos[1];
			while (s[pos[1]] != c && s[pos[1]])
				pos[1]++;
			if (!(ret[ret_idx++] = ft_set_array(s, pos[0], pos[1])))
			{
				while (--ret_idx >= 0)
					free(ret[free_idx++]);
				free(ret);
				return ;
			}
		}
		else
			pos[1]++;
	}
	ret[ret_idx] = 0;
}

char			**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	if (!(result = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *))))
		return (0);
	ft_set_result(s, c, result, 0);
	return (result);
}
