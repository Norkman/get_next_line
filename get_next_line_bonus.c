/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:25:53 by nle-bret          #+#    #+#             */
/*   Updated: 2022/01/06 11:50:23 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	is_bsn(char *buffer)
{
	unsigned int	i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (buffer[i])
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
	free(buffer);
	return (buffer_tmp);
}

char	*ft_save_buffer(char **buffer, char *buffer_save, int fd)
{
	long int	index;
	ssize_t		ret;

	index = BUFFER_SIZE;
	*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer == NULL)
		return (0);
	while (index == BUFFER_SIZE)
	{
		ret = fill_buffer(fd, *buffer);
		if (ret == -1)
			return (0);
		buffer_save = ft_strjoin(buffer_save, *buffer);
		index = is_bsn(*buffer);
	}
	return (buffer_save);
}

char	*get_next_line(int fd)
{
	char			*buffer[4096];
	char			*buffer_save;
	static char		*buffer_nl[4096];

	buffer_save = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer_nl[fd] != NULL)
	{
		buffer_save = ft_strjoin(buffer_save, buffer_nl[fd]);
		if (is_bsn(buffer_nl[fd]) < ft_strlen(buffer_nl[fd]))
		{
			buffer_nl[fd] = ft_strcut(buffer_nl[fd], is_bsn(buffer_nl[fd]) + 1);
			return (buffer_save);
		}
		free(buffer_nl[fd]);
	}
	buffer_save = ft_save_buffer(&buffer[fd], buffer_save, fd);
	if (buffer_save == NULL)
	{
		free(buffer[fd]);
		return (NULL);
	}
	buffer_nl[fd] = buffer_nl_save(buffer[fd], is_bsn(buffer[fd]));
	return (buffer_save);
}
