/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:41:23 by thelmy            #+#    #+#             */
/*   Updated: 2024/12/06 13:42:20 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_textures(t_game game)
{
	if (game.no)
		free(game.no);
	if (game.so)
		free(game.so);
	if (game.we)
		free(game.we);
	if (game.ea)
		free(game.ea);
}

static void	assigning_texture(char *line, char **texture, int fd, t_game game)
{
	int	i;

	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (*texture == NULL)
	{
		line += i;
		*texture = ft_strdup(line);
		if (*texture == NULL)
		{
			free(line);
			(close(fd), printf("Error! Memory allocation failed\n"), exit(1));
		}
	}
	else
	{
		free(line);
		free_textures(game);
		close(fd);
		printf("Error! texture direction is doubled\n");
		exit(1);
	}
}

t_game	textures_parsing(char *line, t_game game, int fd)
{
	if (line[0] == 'N' && line[1] == 'O' && line [2] == ' ')
		assigning_texture(line, &(game.no), fd, game);
	else if (line[0] == 'S' && line[1] == 'O' && line [2] == ' ')
		assigning_texture(line, &(game.so), fd, game);
	else if (line[0] == 'W' && line[1] == 'E' && line [2] == ' ')
		assigning_texture(line, &(game.we), fd, game);
	else if (line[0] == 'E' && line[1] == 'A' && line [2] == ' ')
		assigning_texture(line, &(game.ea), fd, game);
	else if (line[0] == 'F' && line [1] == ' ')
		game = assigning_floor_color(line, game, fd);
	else if (line[0] == 'C' && line [1] == ' ')
		game = assigning_ceil_color(line, game, fd);
	else
	{
		free_textures(game);
		free(line);
		printf(" check the map textures again\n");
		exit(1);
	}
	return (game);
}
