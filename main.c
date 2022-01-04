/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:17:43 by nle-bret          #+#    #+#             */
/*   Updated: 2022/01/04 14:07:23 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int			fd;
	char		*src;
	//int			index;

	src = NULL;
	fd = open("text", O_RDONLY);
	while ((src = get_next_line(fd)))
	{
		printf("-%s", src);
		free(src);
	}
	close(fd);
	return (0);
}
