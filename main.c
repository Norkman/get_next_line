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
	//char		car;
	//int	i;

	fd = open("text", O_RDONLY);
	//i = 1;
	//car = 0;
	src = get_next_line(fd);
	printf("%s", src);
	/*
	while (i != 0)
	{
		i = read(fd, &car, 1);
		printf("%ld", i);
	}
	*/
	close(fd);
	return (0);
}
