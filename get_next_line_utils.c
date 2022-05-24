/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:41:24 by mathis            #+#    #+#             */
/*   Updated: 2022/05/24 02:26:44 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	gnl_lento(char *s, char x)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != x)
		i++;
	return (i);
}

void	*gnl_calloc(size_t count, size_t size)
{
	size_t	tot;
	void	*res;
	size_t	i;

	i = 0;
	tot = count * size;
	res = malloc(tot);
	if (res == 0)
		return (0);
	if (tot > 2147483647)
		return (0);
	while (i < tot)
		((char *)res)[i++] = 0;
	return (res);
}

char	*gnl_join(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	free(s1);
	s1 = NULL;
	return (res);
}
