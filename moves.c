/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:15:48 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/05 20:16:32 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	if (game->map[game->cur_y - 1][game->cur_x] == '1')
		return ;
	if (game->map[game->cur_y - 1][game->cur_x] == 'C')
		ft_take_col(game, game->cur_y - 1, game->cur_x);
	game->player->instances[0].y -= 32;
	game->cur_y -= 1;
	game->moves++;
	game->p_key = 1;
	ft_printf("Move count: %d\n", game->moves);
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->cur_y + 1][game->cur_x] == '1')
		return ;
	if (game->map[game->cur_y + 1][game->cur_x] == 'C')
		ft_take_col(game, game->cur_y + 1, game->cur_x);
	game->player->instances[0].y += 32;
	game->cur_y += 1;
	game->moves++;
	game->p_key = 1;
	ft_printf("Move count: %d\n", game->moves);
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->cur_y][game->cur_x - 1] == '1')
		return ;
	if (game->map[game->cur_y][game->cur_x - 1] == 'C')
		ft_take_col(game, game->cur_y, game->cur_x - 1);
	game->player->instances[0].x -= 32;
	game->cur_x -= 1;
	game->moves++;
	game->p_key = 1;
	ft_printf("Move count: %d\n", game->moves);
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->cur_y][game->cur_x + 1] == '1')
		return ;
	if (game->map[game->cur_y][game->cur_x + 1] == 'C')
		ft_take_col(game, game->cur_y, game->cur_x + 1);
	game->player->instances[0].x += 32;
	game->cur_x += 1;
	game->moves++;
	game->p_key = 1;
	ft_printf("Move count: %d\n", game->moves);
}

void	ft_end_game(t_game *game)
{
	if (game->tot_col == 0)
	{
		mlx_close_window(game->mlx);
		ft_printf("GAME ENDED!!!\n");
	}
	else
		ft_printf("PENDING COLLECTIBLES!!!\n");
}
