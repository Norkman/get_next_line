/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:32:41 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/08 16:12:51 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_buffer(char *buff)
{
	static long int	size_of_buffer;
	//static char		*buff_temp;

	size_of_buffer = 50;
	buff = malloc(sizeof(*buff) * (size_of_buffer + 1));
	if (buff == NULL)
		return (NULL);
	size_of_buffer = size_of_buffer * 2;
	return (buff);
}

int		ft_find(int fd, char *buffer)
{
	long int		i;

	i = 1;
	i = read(fd, buffer, 1);
	if (i == -1)
	{
		return (0);
	}
	return (1);
}
