/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:29:39 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/05 19:18:07 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_textures(t_game *game)
{
	game->texts->floor = mlx_load_png("textures/floor.png");
	game->texts->wall = mlx_load_png("textures/wall.png");
	game->texts->collectible = mlx_load_png("textures/collectible.png");
	game->texts->player = mlx_load_png("textures/player.png");
	game->texts->exit = mlx_load_png("textures/exit.png");
}

void	ft_free_textures(t_textures *texts)
{
	mlx_delete_texture(texts->floor);
	mlx_delete_texture(texts->wall);
	mlx_delete_texture(texts->collectible);
	mlx_delete_texture(texts->player);
	mlx_delete_texture(texts->exit);
}
