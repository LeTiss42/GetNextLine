/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:40:50 by mathis            #+#    #+#             */
/*   Updated: 2022/05/24 02:21:46 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	frigo[BUFFER_SIZE + 1];
	char		buff[BUFFER_SIZE + 1];
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, 0, 0) != 0))
		return (NULL);
	res = gnl_calloc(1, sizeof(char));
	buff[read(fd, buff, BUFFER_SIZE)] = 0;
	printf("buff 1 =%s\nfrigo 1 =%s\n", buff, frigo);
	if (gnl_strlen(buff) == 0 && gnl_strlen(frigo) == 0)
		return (NULL);
	while (gnl_lento(res, '\n') > gnl_strlen(res))
		res = gnl_cutpaste(res, buff, frigo);
	printf("res =%s\n", res);
	printf("frigo =%s\n", frigo);
	return (res);
}

char	*gnl_cutpaste(char *s1, char *buff, char *frigo)
{
	char		*res;
	int			i;
	int			j;

	i = -1;
	j = -1;
	res = malloc(gnl_strlen(s1) + gnl_lento(buff, '\n') + 1);
	while (s1[++i])
		res[i] = s1[i];
	while (buff[++j] && buff[j] != '\n')
		res [i + j] = buff[j];
	if (buff[j] == '\n')
	{
		res [i + j] = '\n';
		res [i + j + 1] = 0;
		i = 0;
		while (buff[j])
			frigo[i++] = buff[j++];
	}
	frigo[i] = 0;
	free (s1);
	s1 = NULL;
	return (res);
}

#include <fcntl.h>

int	main(void)
{
	int		fd1;

	fd1 = open("text.txt", O_RDONLY);
	printf("<<%s>>\n", get_next_line(fd1));
	printf("<<%s>>\n", get_next_line(fd1));
	//printf("<<%s>>\n", get_next_line(fd1));
	//printf("<<%s>>\n", get_next_line(fd1));
	//printf("<<%s>>\n", get_next_line(fd1));
	//printf("<<%s>>\n", get_next_line(fd1));
	return (1);
}
