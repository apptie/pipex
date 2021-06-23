/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:39:44 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/23 15:58:35 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	while (*uc_s1 && *uc_s2 && i < n)
	{
		if (*uc_s1 != *uc_s2)
			return (*uc_s1 - *uc_s2);
		uc_s1++;
		uc_s2++;
		i++;
	}
	if (i == n)
	{
		uc_s1--;
		uc_s2--;
	}
	return (*uc_s1 - *uc_s2);
}
