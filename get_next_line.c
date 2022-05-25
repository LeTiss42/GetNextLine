/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:53:59 by mathis            #+#    #+#             */
/*   Updated: 2022/05/25 14:37:26 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	frigo[BUFFER_SIZE + 1];
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, 0, 0) != 0))
		return (NULL);
	res = gnl_calloc(1, sizeof(char));
	if (gnl_strlen(frigo) != 0)
		res = vide_frigo(res, frigo);
	if (gnl_strlen(frigo) == 0)
		frigo[read(fd, frigo, BUFFER_SIZE)] = 0;
	if (gnl_strlen(frigo) == 0)
		return (NULL);
	while (!gnl_ischr(res, '\n') && gnl_strlen(frigo) > 0)
	{
		res = vide_frigo(res, frigo);
		if (gnl_strlen(frigo) == 0)
			frigo[read(fd, frigo, BUFFER_SIZE)] = 0;
	}
	return (res);
}

char	*vide_frigo(char *res, char *frigo)
{
	char	*buff;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	buff = malloc(gnl_strlen(res) + gnl_lento(frigo, '\n') + 1);
	if (!buff)
		return (0);
	while (res[++i])
		buff[i] = res[i];
	while (frigo[++j] != '\n' && frigo[j])
		buff[i + j] = frigo[j];
	if (frigo[j] == '\n')
		buff[i + j++] = '\n';
	i = 0;
	while (frigo[j])
		frigo[i++] = frigo[j++];
	frigo[i] = 0;
	free(res);
	res = NULL;
	return (buff);
}

#include <fcntl.h>

int	main(void)
{
	int		fd1;

	fd1 = open("text.txt", O_RDONLY);
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));

	return (1);
}