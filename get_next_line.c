/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/11 20:03:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void	att_buffer(char **buffer, char	*read_buff)
{
	char	*tmp;

	tmp = *buffer;
	*buffer = ft_strjoin(tmp, read_buff);
	free(tmp);
	free(read_buff);
}

size_t	get_line_len(char	*buff, size_t	chars_read)
{
	size_t	len;

	len = 0;
	while (buff[len] != '\n' && buff[len] != '\0' && len < chars_read)
		++len;
	return (len);
}

char	*get_next_line(int	fd)
{
	static char	*buffer = NULL;
	char		*buff;
	char		*line;
	ssize_t		chars_read;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buff));
		if (!buff)
			return (NULL);
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			if (buffer)
				free(buffer);
			return (NULL);
		}
		buff[chars_read] = '\0';
		i = get_line_len(buff, (size_t)chars_read);
		if ( i == (size_t)chars_read)
		{
			if (!buffer)
			{
				buffer = ft_strdup(buff);
				free(buff);
				continue ;
			}
			else
			{
				att_buffer(&buffer, buff);
				continue ;
			}
		}
		if (buffer)
		{
			i = get_line_len(buffer, (size_t)chars_read);
			line = ft_substr(buffer, 0, (i + 1));
			free(buffer);
			buffer = ft_substr(buff, i, chars_read);
			free(buff);
		}
		else
		{
			line = ft_substr(buff, 0, i + 1);
			buffer = ft_substr(buff, i, ft_strlen(buff));
			free(buff);
		}
		break ;
	}
	return (line);
}
