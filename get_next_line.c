/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:25:53 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/09 11:53:05 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

ssize_t	fill_buffer(int fd, char* buffer)
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

	len = ft_strlen(buffer);
	buffer_tmp = malloc(sizeof(*buffer_tmp) * (len - begin + 1));
	while (begin + i < len)
	{
		buffer_tmp[i] = buffer[begin + i];
		i++;
	}
	buffer_tmp[i] = '\0';
	return (buffer_tmp);
}

char	*put_in_save(char *buffer, char *buffer_save, ssize_t ret)
{
	//static char	*buffer_nl;

	//buffer_nl = NULL;
	if (buffer_save == NULL)
	{
		buffer_save = NULL;
		buffer_save = ft_strjoin(buffer_save, buffer);
	}
	buffer_save = ft_strjoin(buffer_save, buffer);
	if (ret != BUFFER_SIZE)
	{
		//buffer_nl = buffer_nl_save(buffer, ret);
		//printf("\n%s\n", buffer_nl);
		printf("OK");
	}
	return (buffer_save);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*buffer_save;
	long int		index;
	ssize_t			ret;

	index = BUFFER_SIZE;
	buffer_save = NULL;
	while (index == BUFFER_SIZE)
	{
		buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
			if (buffer == NULL)
				return (0);
		ret = fill_buffer(fd, buffer);
		if (ret == -1)
			return (0); // mouaiiiiiiis
		index = is_back_slash_n(buffer);
		buffer_save = put_in_save(buffer, buffer_save, index);
	}



	printf("\n------------The last buffer is :------------"
			"\n%s\n\n------------And the buffer_save is :-------------"
			"\n%s\n", buffer, buffer_save);
	return ("\n------------STOP-------------\n");
}
