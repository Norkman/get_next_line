/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:32:41 by nle-bret          #+#    #+#             */
/*   Updated: 2022/01/05 15:58:59 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long int	ft_strlen(const char *a)
{
	long int	i;

	i = 0;
	if (a == NULL)
		return (0);
	while (a[i])
		i++;
	return (i);
}

void	*ft_memcpy(char *dst, const char *src, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (!dst && !src)
		return (0);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == '\n')
		{
			dst2[i] = src2[i];
			return (dst);
		}
		i++;
	}
	return (dst);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (len + 1 < size)
	{
		ft_memcpy(dst, src, len + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	long int		len1;
	long int		len2;
	
	len1 = ft_strlen(s1);
	if (s2[0] != '\0')
		len2 = is_back_slash_n(s2) + 1;
	else
		len2 = 0;
	if (len1 + len2 == 0)
		return (NULL);
	str = malloc(sizeof(*str) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	if (s1)
		free(s1);
	return (str);
}

char	*ft_strcut(char	*str, long int index)
{
	char		*little;
	long int	i;
	long int	len;

	i = 0;
	len = ft_strlen(str);
	little = malloc(sizeof(*little) * (len - index + 1));
	while (index + i < len)
	{
		little[i] = str[index + i];
		i++;
	}
	little[i] = '\0';
	free(str);
	return (little);
}
