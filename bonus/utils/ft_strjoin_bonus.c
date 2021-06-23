/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:37:45 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/22 17:14:57 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char *)malloc((size + 1) * sizeof(char))))
		return (0);
	ft_strlcpy(result, s1, size + 1);
	ft_strlcat(result, s2, size + 1);
	return (result);
}
