/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/13 14:44:02 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char	*str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(const char	*str)
{
	size_t	len;
	char	*dup;

	len = (ft_strlen(str) + 1);
	dup = (char *)malloc(len * sizeof(*str));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, len);
	return (dup);
}

size_t	ft_strlcpy(char	*dest, const char	*src, size_t	dest_size)
{
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (dest_size)
	{
		while (--dest_size && *src)
			*(dest++) = *(src++);
		*dest = '\0';
	}
	return (src_len);
}

char	*ft_strjoin(const char	*str1, const char	*str2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*new_str;

	if (!str1 && !str2)
		return (NULL);
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	new_str = (char *)malloc((str1_len + str2_len + 1) * sizeof(*new_str));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str1, (str1_len + 1));
	ft_strlcpy((new_str + str1_len), str2, (str2_len + 1));
	return (new_str);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_start_len;

	if (!str)
		return (NULL);
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	s_start_len = ft_strlen((str + start));
	if (s_start_len < len)
		len = s_start_len;
	++len;
	sub = (char *)malloc(len * sizeof(*sub));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (str + start), len);
	return (sub);
}
