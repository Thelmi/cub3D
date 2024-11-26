/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:06:49 by thelmy            #+#    #+#             */
/*   Updated: 2024/11/26 15:09:49 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_cub_extention(char *haystack, char *needle)
{
	size_t	i;
	size_t	needlen;
	size_t	len;

	i = 0;
	len = t_strlen(haystack);
	needlen = t_strlen(needle);
	if (!*needle)
		return (0);
	while (i < needlen)
	{
		if (t_strncmp(&haystack[len - 4], needle, needlen) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	not_cub_extention(char *str)
{
	if (!(is_cub_extention(str, ".cub") && t_strlen(str) > 4))
	{
		printf("Error! the file should have a .cub extention\n");
		exit (1);
	}
}

t_game	parsing(t_game game, int ac, char **av)
{
	int		fd;

	fd = 0;
	if (ac != 2)
	{
		printf("Error! only two arguements are allowed\n");
		exit(1);
	}
	if (is_cub_extention(av[1], ".cub") && t_strlen(av[1]) > 4)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening a file");
			exit(1);
		}
		game = map_file_parsing(game, fd);
		close(fd);
	}
	not_cub_extention(av[1]);
	return (game);
}
