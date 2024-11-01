/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:23:17 by thelmy            #+#    #+#             */
/*   Updated: 2024/11/01 07:27:27 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	empty_map(char *str, char *s, t_game game, int fd)
{
	if (!str || str[0] == '\n')
	{
		printf("new line in the middle of the map\n");
		if (str)
			free(str);
		if (s)
			free(s);
		free_textures(game);
		close(fd);
		exit(1);
	}
}

static char	*read_map_free(char *read, t_game game, int fd)
{
	char	*read_next;

	read_next = NULL;
	while (read)
	{
		read_next = get_next_line(fd);
		if (read_next == NULL)
			break ;
		empty_map(read_next, read, game, fd);
		letters_checker(read_next, read, game, fd);
		read = t_strjoin(read, read_next);
		free (read_next);
	}
	return (read);
}

void	valid_all_ones(char *read, t_game game, int fd)
{
	int	i;

	i = 0;
	while (read[i] == ' ' || read[i] == '\t')
		i++;
	while (read[i])
	{
		if (read[i] != '1' && read[i] != '\n')
		{
			free(read);
			free_textures(game);
			close(fd);
			printf("border is not valid\n");
			exit(1);
		}
		i++;
	}
}

static char	*nl_escaper(char *str, t_game game, int fd)
{
	if (!str)
	{
		if (str)
			free(str);
		free_textures(game);
		close(fd);
		printf("where is the map\n");
		exit(1);
	}
	while (str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd);
	}
	return (str);
}

t_game	map_parsing(t_game game, int fd)
{
	char	*read;
	char	*read_next;

	read = get_next_line(fd);
	read = nl_escaper(read, game, fd);
	valid_all_ones(read, game, fd);
	read = read_map_free(read, game, fd);
	return (game);
}
