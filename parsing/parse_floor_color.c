/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:59:47 by thelmy            #+#    #+#             */
/*   Updated: 2024/11/01 01:08:16 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	invalid_rgb(char *line, t_game game, int fd)
{
	//if (line)
	//	free(line);
	free_textures(game);
	close(fd);
	printf("Error! RGB is invalid\n");
	exit(1);
}

t_game	parse_rgb(char *line, t_game game, int fd)
{
	int	i;
	int	j;
	int	comma_count;
	int	values[3];

	i = 0;
	if (commas_couter(line, game, fd) != 2)
		invalid_rgb(line, game, fd);
	j = 0;
	while (j < 3)
	{
		values[j++] = parse_single_value(line, &i, game, fd);
		if (j < 3)
		{
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			if (line[i] != ',')
				invalid_rgb(line, game, fd);
			i++;
		}
	}
	game = assigning_fl_rgb(game, values);
	return (check_last_characters(line, game, fd, i), game);
}

t_game	assigning_floor_color(char *line, t_game game, int fd)
{
	int	i;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (game.flr_r == -1)
	{
		line += i;
		game = parse_rgb(line, game, fd);
	}
	else
	{
		free(line);
		free_textures(game);
		close(fd);
		printf("Error! texture direction is doubled\n");
		exit(1);
	}
	return (game);
}
