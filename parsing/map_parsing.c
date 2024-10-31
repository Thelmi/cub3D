/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:23:17 by thelmy            #+#    #+#             */
/*   Updated: 2024/11/01 02:42:04 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	
}
