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
# define GET_NEXT_LINE_H 
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define BUFFER_SIZE 50

int		ft_strlen(const char *a);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		is_back_slash_n(char *buffer);
void	ft_strlcpy(char *dst, const char *src, size_t size);

#endif

