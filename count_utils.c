/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:15:21 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/05 13:58:58 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_char_count(char **map, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_get_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_get_cols(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	return (i);
}

void	ft_take_col(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	game->tot_col--;
	game->map[y][x] = '0';
	ft_printf("Collectibles picked: %d\n", game->cur_col - game->tot_col);
	while (game->collectible[i])
	{
		if (game->collectible[i]->instances[0].y == y * 32
			&& game->collectible[i]->instances[0].x == x * 32)
		{
			ft_printf("Collectible picked\n");
			game->collectible[i]->enabled = 0;
			break ;
		}
		i++;
	}
}

void	ft_col_list(t_game *game, mlx_image_t *image)
{
	if (game->cur_col == 0)
	{
		game->collectible = malloc(sizeof(mlx_image_t *) * (game->tot_col + 1));
		if (!game->collectible)
			exit(1);
		game->collectible[0] = image;
		game->cur_col++;
		game->collectible[game->tot_col] = 0;
	}
	else
	{
		game->collectible[game->cur_col] = image;
		game->cur_col++;
	}
}
