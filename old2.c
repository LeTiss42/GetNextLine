/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:02:41 by mathis            #+#    #+#             */
/*   Updated: 2022/05/19 01:28:11 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*res;
	char		buff[BUFFER_SIZE + 1];
	size_t		i;
	size_t		j;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) != 0))
		return (NULL);
	if (!res)
		res = gnl_calloc(1, sizeof(char));
	j = gnl_strlen(res);
	while (!(read(fd, buff + i, 1) == 0 && buff[0] != 0 && res[j] == 0))
	{
		buff[i + 1] = 0;
		if (buff[i] == '\n' || buff[i] == 0)
		{
			res = gnl_join(res, buff);
			buff[0] = 0;
			return (res + j);
		}
		if (++i >= BUFFER_SIZE)
		{
			i = 0;
			res = gnl_join(res, buff);
			buff[0] = 0;
		}
	}
	return (0);
}
