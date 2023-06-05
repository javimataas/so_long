/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:28:10 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/05 20:17:16 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

# define ERR_INVALID_ARGS 1
# define ERR_FILE_ACCESS 2
# define ERR_FILE_EXT 3
# define ERR_EMPTY_FILE 4
# define ERR_NOT_RECT 5
# define ERR_NO_WALLS 6
# define ERR_INV_CHARS 7
# define ERR_NO_PATH 8
# define ERR_GRAPH 9

typedef struct s_point
{
	int	y;
	int	x;
}	t_point;

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
}	t_textures;

typedef struct s_game
{
	char		**map;
	mlx_t		*mlx;
	t_textures	*texts;
	int			size_y;
	int			size_x;
	int			cur_y;
	int			cur_x;
	int			p_key;
	int			moves;
	int			cur_col;
	int			tot_col;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	**collectible;
}	t_game;

char	**ft_load_map(char *file);

int		ft_correct_map(char **map);

int		ft_strscount(char **strs);
int		ft_rectangular_map(char **map);
int		ft_valid_chars(char **map);
int		ft_get_char_count(char **map, char c);
int		ft_get_rows(char **map);
int		ft_get_cols(char **map);

void	ft_take_col(t_game *game, int y, int x);
void	ft_col_list(t_game *game, mlx_image_t *image);

t_point	ft_get_player_pos(char **map);
int		ft_path(char **map);

int		ft_error(int error);

void	ft_init_game(char **map);
void	ft_load_player(t_game *game);
void	ft_fill_obj(t_game *game, int y, int x);
void	ft_fill_map(t_game *game);

void	ft_free_textures(t_textures *texts);
void	ft_load_textures(t_game *game);

void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

void	ft_end_game(t_game *game);

#endif
