/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/24 10:34:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

//	get_next_line
char	*get_next_line(int fd);

//	utils
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char	*dest, const char *src, size_t dest_size);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_substr(char const *str, unsigned int start, size_t len);

#endif
