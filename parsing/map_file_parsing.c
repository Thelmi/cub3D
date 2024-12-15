/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:04:48 by thelmy            #+#    #+#             */
/*   Updated: 2024/12/14 11:54:15 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_textures_exit(char *line, t_game game, int fd)
{
	free(line);
	free_textures(game);
	close(fd);
	printf("Error! check the map textures again\n");
	exit(1);
}

static int	is_whitespaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static char	*trimspaces(char *line, int fd)
{
	int		i;
	int		len;
	char	*str;

	if (!line)
		return (NULL);
	i = 0;
	len = t_strlen(line) - 1;
	while (len > 0 && is_whitespaces(line[len]))
		len--;
	while (line[i] && is_whitespaces(line[i]))
		i++;
	if (!len)
		return (NULL);
	str = malloc(sizeof(char) * ((len - i) + 2));
	if (!str)
	{
		close(fd);
		return (free(line), NULL);
	}
	ft_strlcpy(str, line + i, (len - i) + 2);
	if (line)
		free(line);
	return (str);
}

static char	*escape_whitespaces(char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (line);
}

t_game	map_file_parsing(t_game game, int fd)
{
	char	*line;
	int		count;

	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		if (line[0] == '\n' || line[0] == ' ')
		{
			line = escape_whitespaces(line, fd);
			printf("line: %s\n", line);
			continue ;
		}
		line = trimspaces(line, fd);
		//printf("trimed line: %s\n", line);
		if (line && line[0] != '\0' && ++count)
			game = textures_parsing(line, game, fd);
		free(line);
		if (count == 6)
			break ;
		line = get_next_line(fd);
	}
	if (count != 6 || game.floor_hex == game.ceil_hex)
		free_textures_exit(line, game, fd);
	game = map_parsing(game, fd);
	return (game);
}
