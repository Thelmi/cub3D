/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:51:59 by thelmy            #+#    #+#             */
/*   Updated: 2024/11/01 02:27:53 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_game
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_hex;
	int		flr_r;
	int		flr_g;
	int		flr_b;
	int		ceil_hex;
	int		cl_r;
	int		cl_g;
	int		cl_b;
}			t_game;

t_game	map_parsing(t_game game, int fd);
t_game		parsing(t_game game, int ac, char **av);
t_game		map_file_parsing(t_game game, int fd);
int			t_strncmp(char *s1, char *s2, size_t n);
size_t		t_strlen(char *str);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
t_game		textures_parsing(char *line, t_game game, int fd);
char		*ft_strdup(char *s1);
void		free_textures(t_game game);
t_game		assigning_floor_color(char *line, t_game game, int fd);
int			ft_isdigit(int c);
t_game		parse_rgb(char *line, t_game game, int fd);
int			ft_atoi(char *str);
int			invalid_rgb(char *line, t_game game, int fd);
void		check_last_characters(char *line, t_game game, int fd, int i);
t_game		assigning_fl_rgb(t_game game, int *values);
int			parse_single_value(char *line, int *i, t_game game, int fd);
int			commas_couter(char *line, t_game game, int fd);
int			is_valid_char(char c);
t_game		assigning_ceil_color(char *line, t_game game, int fd);
//t_game	map_parsing(t_game game, int fd);
#endif