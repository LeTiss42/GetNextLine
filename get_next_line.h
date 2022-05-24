/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:40:14 by mathis            #+#    #+#             */
/*   Updated: 2022/05/24 01:57:36 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	gnl_strlen(char *s);
size_t	gnl_lento(char *s, char x);
void	*gnl_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*gnl_join(char *s1, char *s2);
char	*gnl_cutpaste(char *s1, char *buff, char *frigo);

#endif