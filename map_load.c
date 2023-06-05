/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:58 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/25 19:06:42 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rows_count(char *file)
{
	int		count;
	int		fd;
	char	*row;

	count = 0;
	fd = open(file, O_RDONLY);
	row = get_next_line(fd);
	while (row)
	{
		count++;
		free(row);
		row = get_next_line(fd);
	}
	free(row);
	close(fd);
	return (count);
}

char	*ft_strjoin_map(char *old_map, char *line)
{
	char	*map;

	map = ft_strjoin(old_map, line);
	free(old_map);
	return (map);
}

char	**ft_load_map(char *file)
{
	char	**map;
	char	*row;
	char	*row_line;
	int		fd;

	fd = open(file, O_RDONLY);
	row = get_next_line(fd);
	row_line = malloc(0);
	while (row)
	{
		row_line = ft_strjoin_map(row_line, row);
		free(row);
		row = get_next_line(fd);
	}
	close(fd);
	map = ft_split(row_line, '\n');
	free(row_line);
	return (map);
}
