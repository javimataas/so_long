/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:58:13 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/25 19:24:49 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strscount(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	ft_rectangular_map(char **map)
{
	int	cols;
	int	rows;
	int	i;

	i = 0;
	rows = ft_strscount(map);
	cols = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != cols)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_valid(char c)
{
	return (c == 'E' || c == 'P' || c == 'C'
		|| c == '1' || c == '0');
}

int	ft_extra_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_is_valid(map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_valid_chars(char **map)
{
	int	c_players;
	int	c_exits;
	int	c_collectibles;

	c_players = ft_get_char_count(map, 'P');
	c_exits = ft_get_char_count(map, 'E');
	c_collectibles = ft_get_char_count(map, 'C');
	if (c_players != 1 || c_exits != 1 || c_collectibles < 1)
		return (0);
	return (!ft_extra_chars(map));
}
