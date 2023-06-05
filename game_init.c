/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:39:25 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/05 18:00:57 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_data(t_game *game, char **map)
{
	t_point	pos;

	pos = ft_get_player_pos(map);
	game->map = map;
	game->cur_y = pos.y;
	game->cur_x = pos.x;
	game->size_y = ft_get_rows(map);
	game->size_x = ft_get_cols(map);
	game->p_key = 0;
	game->moves = 0;
	game->tot_col = ft_get_char_count(map, 'C');
	game->cur_col = 0;
}

void	ft_finish(t_game *game)
{
	if (game->map[game->cur_y][game->cur_x] == 'E')
		ft_end_game(game);
	game->p_key = 0;
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;
	t_game	*game;

	game = param;
	mlx = game->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (!game->p_key)
	{
		if (mlx_is_key_down(mlx, MLX_KEY_UP))
			ft_move_up(game);
		if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			ft_move_down(game);
		if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
			ft_move_left(game);
		if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
			ft_move_right(game);
	}
	else if (!mlx_is_key_down(game->mlx, MLX_KEY_UP)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_finish(game);
}

void	ft_init_window(t_game *game)
{
	t_textures	textures;

	game->mlx = mlx_init(game->size_x * 32,
			game->size_y * 32, "so_long", 0);
	if (!game->mlx)
	{
		ft_error(ERR_GRAPH);
		exit(1);
	}
	game->texts = &textures;
	ft_load_textures(game);
	ft_fill_map(game);
	ft_load_player(game);
	ft_free_textures(&textures);
	mlx_loop_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
}

void	ft_init_game(char **map)
{
	t_game	game;

	ft_init_data(&game, map);
	ft_init_window(&game);
}
