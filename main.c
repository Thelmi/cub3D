/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:49:16 by thelmy            #+#    #+#             */
/*   Updated: 2024/12/17 12:23:27 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *game)
{
	game->map = NULL;
	game->copy = NULL;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->ea = NULL;
	game->flr_r = -1;
	game->flr_g = -1;
	game->flr_b = -1;
	game->cl_r = -1;
	game->cl_g = -1;
	game->cl_b = -1;
	game->floor_hex = 0;
	game->ceil_hex = 0;
	game->pl_view = 0;
	game->pl_x = -1;
	game->pl_y = -1;
	game->free_flag = 0;
	game->newline = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	game_init(&game);
	game = parsing(game, ac, av);
	free_textures(game);
	free_map(game);
	return (0);
}
