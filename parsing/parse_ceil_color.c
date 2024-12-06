/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ceil_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:58:09 by thelmy            #+#    #+#             */
/*   Updated: 2024/11/27 15:33:12 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_game	assigning_cl_rgb(t_game game, int *values)
{
	game.cl_r = values[0];
	game.cl_g = values[1];
	game.cl_b = values[2];
	game.ceil_hex = game.cl_r * (pow(256, 2))
		+ (game.cl_g * 256) + game.cl_b;
	return (game);
}

static t_game	parse_ceil_rgb(char *line, t_game game, int fd)
{
	int	i;
	int	j;
	int	comma_count;
	int	values[3];

	(void)comma_count;
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
	game = assigning_cl_rgb(game, values);
	return (check_last_characters(line, game, fd, i), game);
}

t_game	assigning_ceil_color(char *line, t_game game, int fd)
{
	int	i;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (game.cl_r == -1)
	{
		line += i;
		game = parse_ceil_rgb(line, game, fd);
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
