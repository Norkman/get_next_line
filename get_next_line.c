/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:25:53 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/08 16:16:30 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	//char		*str;
	char		*buffer;
	int			index;

	index = 0;
	buffer = NULL;
	buffer = get_buffer(buffer);	
	index = ft_find(fd, buffer);

	printf("\n%d", index);
	return ("\nSTOP\n");
}
