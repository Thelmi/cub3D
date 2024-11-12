/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:56:13 by krazikho          #+#    #+#             */
/*   Updated: 2024/02/11 18:52:25 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_buff(char *buff)
{
	int		i;
	int		j;
	char	*newbuff;

	i = 0;
	j = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	newbuff = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!newbuff)
		return (NULL);
	i++;
	while (buff[i])
		newbuff[j++] = buff[i++];
	newbuff[j] = '\0';
	free(buff);
	return (newbuff);
}

char	*get_linee(char *buff_joint)
{
	int		pos;
	char	*output;

	pos = 0;
	if (!buff_joint[pos])
		return (NULL);
	while (buff_joint[pos] && buff_joint[pos] != '\n')
		pos++;
	output = (char *)malloc(sizeof(char) * (pos + 2));
	if (!output)
		return (NULL);
	pos = 0;
	while (buff_joint[pos] && buff_joint[pos] != '\n')
	{
		output[pos] = buff_joint[pos];
		pos++;
	}
	output[pos] = buff_joint[pos];
	pos++;
	output[pos] = '\0';
	return (output);
}

char	*find_line(int fd, char *buff_joint)
{
	char	*buff;
	int		len;

	buff = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	len = 1;
	while (!ft_strchr(buff_joint, '\n') && (len != 0))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(buff);
			free(buff_joint);
			return (NULL);
		}
		buff[len] = '\0';
		buff_joint = ft_strjoin(buff_joint, buff);
	}
	free(buff);
	return (buff_joint);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer = find_line(fd, buffer);
	if (!buffer)
	{
		return (NULL);
	}
	output = get_linee(buffer);
	buffer = update_buff(buffer);
	return (output);
}
