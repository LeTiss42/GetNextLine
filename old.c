/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:40:50 by mathis            #+#    #+#             */
/*   Updated: 2022/05/17 21:00:11 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*res;
	char		buff[BUFFER_SIZE + 1];
	size_t		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) != 0))
		return (NULL);
	buff[BUFFER_SIZE] = 0;
	if (!res)
		res = gnl_calloc(1, sizeof(char));
	if (read (fd, buff, 1) == 0)
		return (0);
	while (buff[i] != '\n' && buff[i] != 0 && i < BUFFER_SIZE - 1)
		read (fd, buff + (++i), 1);
	while (++i <= BUFFER_SIZE)
		buff[i] = 0;
	res = gnl_join(res, buff);
	return (res);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	printf("<<%s>>\n", get_next_line(fd));
	return (1);
}
