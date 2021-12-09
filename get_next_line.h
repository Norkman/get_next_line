/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:22:58 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/08 16:07:56 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H # include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char		*get_next_line(int fd);
char		*get_buffer(char *buff); 
int			ft_find(int fd, char *buffer);
#endif

