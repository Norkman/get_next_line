/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:22:58 by nle-bret          #+#    #+#             */
/*   Updated: 2022/01/21 16:21:53 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

long int	ft_strlen(const char *a);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
int			is_bsn(char *buffer);
void		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strcut(char	*str, long int len);

#endif
