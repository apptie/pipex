/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:58:18 by jimikim           #+#    #+#             */
/*   Updated: 2021/06/22 18:59:55 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}
