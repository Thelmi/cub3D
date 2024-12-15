/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:22:30 by maakhan           #+#    #+#             */
/*   Updated: 2024/12/14 12:21:17 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	tft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*t_strdup(const char *s1);
char	*ftt_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif