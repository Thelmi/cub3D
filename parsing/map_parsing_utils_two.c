/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:42:57 by thelmy            #+#    #+#             */
/*   Updated: 2024/12/19 20:40:11 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_and_exit(char **str, int fd, t_game game, char *read)
{
	int	i;

	i = 0;
	printf("Error, more than one player\n");
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
	if (read)
		free(read);
	free_textures(game);
	close (fd);
	exit (1);
}

static int	is_pl_view(char c, t_game *game, int i, int j)
{
	if ((c == 'N' || c == 'W' || c == 'E' || c == 'S')
		&& (game->pl_y == -1 && game->pl_x == -1))
	{
		game->pl_x = j;
		game->pl_y = i;
	}
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

t_game	locate_check_players(char **arr, t_game game, int fd, char *read)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j])
			{
				if (is_pl_view(arr[i][j], &game, i, j) && ++count)
				{
					if (count == 1)
						game.pl_view = arr[i][j];
				}
			}
			j++;
		}
	}
	if (count > 1)
		free_and_exit(arr, fd, game, read);
	return (game);
}
