/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:59:47 by thelmy            #+#    #+#             */
/*   Updated: 2024/12/06 13:57:43 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	invalid_rgb(char *line, t_game game, int fd)
{
	if (line)
		free(line);
	free_textures(game);
	close(fd);
	printf("Error! RGB is invalid\n");
	exit(1);
}

t_game	parse_rgb(char *line, t_game game, int fd)
{
	int	i;
	int	j;
	int	values[3];

	i = 0;
	if (commas_couter(line, game, fd) != 2)
		game.free_flag = 1;
	j = 0;
	while (j < 3)
	{
		values[j++] = parse_single_value(line, &i, &game, fd);
		if (j < 3)
		{
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			if (line[i] != ',')
				game.free_flag = 1;
			i++;
		}
	}
	game = assigning_fl_rgb(game, values);
	return (check_last_characters(line, &game, fd, i), game);
}

t_game	assigning_floor_color(char *line, t_game game, int fd)
{
	int		i;
	char	*ptr;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (game.flr_r == -1)
	{
		ptr = line;
		ptr += i;
		game = parse_rgb(ptr, game, fd);
		if (game.free_flag)
			invalid_rgb(line, game, fd);
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
