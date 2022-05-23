/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:02:41 by mathis            #+#    #+#             */
/*   Updated: 2022/05/19 03:00:08 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*res;
	char		buff[2];
	size_t		j;

	buff[0] = 0;
	buff[1] = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, 0, 0) != 0))
		return (NULL);
	if (!res)
		res = gnl_calloc(1, sizeof(char));
	j = gnl_strlen(res);
	while (read(fd, buff, 1) > 0)
	{
		if (buff[0] == '\n')
			return ((res = gnl_join(res, buff)) + j);
		else
			res = gnl_join(res, buff);
	}
	if (buff[0] == 0)
		return (0);
	return (res + j);
}
/*
#include <fcntl.h>

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	//printf("<<%s>>\n", get_next_line(fd));
	//printf("<<%s>>\n", get_next_line(fd));
	//printf("<<%s>>\n", get_next_line(fd));
	//printf("<<%s>>\n", get_next_line(fd));
	//printf("<<%s>>\n", get_next_line(fd));
	//printf("<<%s>>\n", get_next_line(fd));
	//printf("<<%s>>\n", get_next_line(fd));
	
	printf("||1 =>%s", get_next_line(fd));
	printf("||2 =>%s", get_next_line(fd));
	printf("||3 =>%s", get_next_line(fd));
	printf("||4 =>%s", get_next_line(fd));
	printf("||5 =>%s", get_next_line(fd));
	printf("||6 =>%s", get_next_line(fd));
	printf("||7 =>%s", get_next_line(fd));
	printf("||8 =>%s", get_next_line(fd));
	return (1);
}
*/