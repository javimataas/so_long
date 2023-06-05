/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:47:19 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/30 17:57:58 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_empty_map(char **map)
{
	if (!map[0])
		return (1);
	return (0);
}

int	ft_check_walls(char **map)
{
	int	cols;
	int	rows;
	int	i;

	i = 0;
	rows = ft_strscount(map) - 1;
	cols = ft_strlen(map[0]);
	while (map[0][i] == '1')
		i++;
	if (i != cols)
		return (0);
	i = 1;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[rows][i] == '1')
		i++;
	if (i != cols)
		return (0);
	return (1);
}

int	ft_correct_map(char **map)
{
	if (ft_empty_map(map))
		return (ft_error(ERR_EMPTY_FILE));
	if (!ft_rectangular_map(map))
		return (ft_error(ERR_NOT_RECT));
	if (!ft_check_walls(map))
		return (ft_error(ERR_NO_WALLS));
	if (!ft_valid_chars(map))
		return (ft_error(ERR_INV_CHARS));
	if (!ft_path(map))
		return (ft_error(ERR_NO_PATH));
	return (1);
}
