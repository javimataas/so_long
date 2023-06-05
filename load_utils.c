/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:01:25 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/05 18:06:26 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_player(t_game *game)
{
	if (!game->texts->player)
		exit(1);
	game->player = mlx_texture_to_image(game->mlx, game->texts->player);
	if (!game->player)
		exit(1);
	if (mlx_image_to_window(game->mlx, game->player, game->cur_x * 32,
			game->cur_y * 32) < 0)
		exit(1);
}

void	ft_fill_obj(t_game *game, int y, int x)
{
	mlx_image_t	*aux;

	if (game->map[y][x] == '1')
	{
		game->wall = mlx_texture_to_image(game->mlx, game->texts->wall);
		if (mlx_image_to_window(game->mlx, game->wall, x * 32, y * 32))
			exit (1);
	}
	else if (game->map[y][x] == 'C')
	{
		aux = mlx_texture_to_image(game->mlx, game->texts->collectible);
		if ((mlx_image_to_window(game->mlx, aux, x * 32, y * 32)) < 0)
			exit (1);
		ft_col_list(game, aux);
	}
	else if (game->map[y][x] == 'E')
	{
		game->exit = mlx_texture_to_image(game->mlx, game->texts->exit);
		if (mlx_image_to_window(game->mlx, game->exit, x * 32, y * 32))
			exit (1);
	}
}

void	ft_fill_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			game->floor = mlx_texture_to_image(game->mlx, game->texts->floor);
			if (mlx_image_to_window(game->mlx, game->floor, x * 32, y * 32) < 0)
				exit(1);
			else
				ft_fill_obj(game, y, x);
			x++;
		}
		y++;
	}
}
