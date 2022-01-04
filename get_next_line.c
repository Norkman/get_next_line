/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:25:53 by nle-bret          #+#    #+#             */
/*   Updated: 2022/01/04 14:04:58 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	fill_buffer(int fd, char *buffer)
{
	int	ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret != -1)
	{
		buffer[ret] = '\0';
		return (ret);
	}
	return (-1);
}

int	is_back_slash_n(char *buffer)
{
	long int	i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*buffer_nl_save(char *buffer, ssize_t begin)
{
	char		*buffer_tmp;
	long int	len;
	long int	i;

	i = 0;
	len = ft_strlen(buffer);
	buffer_tmp = malloc(sizeof(*buffer_tmp) * (len - begin + 1));
	if (buffer_tmp == NULL)
		return (NULL);
	while (begin + i < len)
	{
		buffer_tmp[i] = buffer[begin + i + 1];
		i++;
	}
	buffer_tmp[i] = '\0';
	return (buffer_tmp);
}

char	*ft_save_buffer(char **buffer, char *buffer_save, int fd)
{
	char		*buffer_tmp;
	long int	index;
	ssize_t		ret;

	index = BUFFER_SIZE;
	buffer_tmp = malloc(sizeof(*buffer_tmp) * (BUFFER_SIZE + 1));
	if (buffer_tmp == NULL)
		return (0);
	while (index == BUFFER_SIZE)
	{
		ret = fill_buffer(fd, buffer_tmp);
		if (ret == -1)
			return (0);
		buffer_save = ft_strjoin(buffer_save, buffer_tmp);
		index = is_back_slash_n(buffer_tmp);
	}
	*buffer = buffer_tmp;
	return (buffer_save);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*buffer_save;
	static char		*buffer_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_save = NULL;
	if (buffer_nl != NULL)
	{
		buffer_save = ft_strjoin(buffer_save, buffer_nl);
		if (is_back_slash_n(buffer_nl) < ft_strlen(buffer_nl))
		{
			buffer_nl = ft_strcut(buffer_nl, is_back_slash_n(buffer_nl) + 1);
			return (buffer_save);
		}
		free(buffer_nl);
	}
	buffer_save = ft_save_buffer(&buffer, buffer_save, fd);
	buffer_nl = buffer_nl_save(buffer, is_back_slash_n(buffer));
	free(buffer);
	return (buffer_save);
}
