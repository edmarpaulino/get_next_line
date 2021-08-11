/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/11 16:59:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int	fd)
{
	static char	*buffer = NULL;
	char		*buff;
	char		*temp;
	char		*line;
	ssize_t		sz;
	size_t		buffer_len;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buff));
		if (!buff)
			return (NULL);
		sz = read(fd, buff, BUFFER_SIZE);
		if (sz <= 0)
		{
			if (buffer)
				free(buffer);
			return (NULL);
		}
		i = 0;
		buff[sz] = '\0';
		while (buff[i] != '\n' && buff[i] != '\0')
			++i;
		if (i == sz)
		{
			if (!buffer)
			{
				buffer = ft_strdup(buff);
				free(buff);
				continue ;
			}
			else
			{
				temp = buffer;
				buffer = ft_strjoin(temp, buff);
				free(temp);
				free(buff);
				continue ;
			}
		}
		if (buffer)
		{
			buffer_len = ft_strlen(buffer);
			line = ft_strdup(buffer);
			free(buffer);
			temp = line;
			line = ft_strjoin(temp, buff);
			free(temp);
			temp = line;
			line = ft_substr(temp, 0, buffer_len + i + 1);
			free(temp);
			buffer = ft_substr(buff, i + 1, ft_strlen(buff));
			free(buff);
		}
		else
		{
			line = ft_strdup(buff);
			buffer = ft_substr(buff, i + 1, ft_strlen(buff));
			free(buff);
		}
		break ;
	}
	return (line);
}
