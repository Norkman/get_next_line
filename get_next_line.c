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

ssize_t	fill_buffer(int fd, char* buffer, long int size_of_bufer)
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
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			printf ("\n\nHERE !!!!\n\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	put_in_save(char *buffer, ssize_t ret)
{
	long int	len;
	char		*save_buffer;

	len = ft_strlen(save_buffer);
	save_buffer = malloc(sizeof(*save_buffer) * (len + ret + 1));
	if (save_buffer == NULL)
		return (NULL);
	save_buffer = ft_strjoin(save_buffer, buffer);
}

char	*get_next_line(int fd)
{
	static long int	BUFFER_SIZE;
	char			*buffer;
	int				index;
	ssize_t			ret;

	index = 1;
	BUFFER_SIZE = 50;
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (0);
	while (index == 1)
	{
		ret = fill_buffer(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (0); // mouaiiiiiiis
		index = is_back_slash_n(buffer);
		put_in_save(buffer, BUFFER_SIZE, ret);
		index = 0;
	}

	printf("\n%d", index);
	printf("\n%s", buffer);
	return ("\nSTOP\n");
}
