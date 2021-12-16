/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:17:43 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/08 13:34:40 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int			fd;
	char		*src;
	int			max;
	int 		i;

	src = NULL;
	i = 0;
	max = 5;
	fd = open("text", O_RDONLY);
	while (i < max)
	{
		src = get_next_line(fd);
		printf("\n ====>  %s\n", src);
		free(src);
		i++;
	}
	close(fd);
	return (0);
}
