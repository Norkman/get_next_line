/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:32:41 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/09 11:57:47 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_buffer(char *buffer)
{
	static long int	size_of_buffer;
	static char		*buffer_tmp;

	size_of_buffer = 50;
	buffer_tmp = malloc(sizeof(*buffer_tmp) * (size_of_buffer + 1));
	if (buffer_tmp == NULL)
		return (NULL);
	buffer = buffer_tmp;
	buffer[size_of_buffer] = '\0';
	size_of_buffer = size_of_buffer * 2;
	return (buffer);
}

int		ft_find(int fd, char *buffer)
{
	long int		i;

	i = 1;
	i = read(fd, buffer, 1);
	if (i == -1)
	{
		return (-1);
	}
	return (0);
}
