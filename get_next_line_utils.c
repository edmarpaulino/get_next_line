/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/11 11:21:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(const char	*s1)
{
	size_t	len;
	char	*ptr;

	len = (ft_strlen(s1) + 1);
	ptr = (char *)malloc(len * sizeof(*s1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize)
	{
		while (--dstsize && *src)
			*(dst++) = *(src++);
		*dst = '\0';
	}
	return (src_len);
}

char	*ft_strjoin(const char	*s1, const char	*s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(*new_str));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, (s1_len + 1));
	ft_strlcpy((new_str + s1_len), s2, (s2_len + 1));
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_start_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	s_start_len = ft_strlen((s + start));
	if (s_start_len < len)
		len = s_start_len;
	++len;
	sub = (char *)malloc(len * sizeof(*sub));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (s + start), len);
	return (sub);
}
