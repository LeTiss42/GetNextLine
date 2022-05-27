/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:53:59 by mathis            #+#    #+#             */
/*   Updated: 2022/05/27 18:02:09 by mravera          ###   ########.fr       */
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
	if (gnl_strlen(frigo) == 0 && gnl_strlen(res) == 0)
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
	buff = malloc(gnl_strlen(res) + gnl_lento(frigo, '\n') + 2);
	if (!buff)
		return (0);
	while (res[++i])
		buff[i] = res[i];
	while (frigo[++j] != '\n' && frigo[j] != '\0')
		buff[i + j] = frigo[j];
	if (frigo[j] == '\n')
		buff[i + j++] = '\n';
	buff[i + j] = 0;
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

	fd1 = open("text3.txt", O_RDONLY);
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
