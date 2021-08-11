/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/11 11:23:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//	get_next_line functions
char	*get_next_line(int	fd);

//	utils functions
size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char	*s1);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize);
char	*ft_strjoin(const char	*s1, const char	*s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
