/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:29:53 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/30 18:56:22 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int error)
{
	if (error == ERR_INVALID_ARGS)
		ft_printf("Error, invalid arguments\n");
	else if (error == ERR_FILE_ACCESS)
		ft_printf("Error, the file could not be opened\n");
	else if (error == ERR_FILE_EXT)
		ft_printf("Error, invalid file extension\n");
	else if (error == ERR_EMPTY_FILE)
		ft_printf("Error, empty file\n");
	else if (error == ERR_NOT_RECT)
		ft_printf("Error, the map must be rectangular\n");
	else if (error == ERR_NO_WALLS)
		ft_printf("Error, the map isn't surrounded by walls\n");
	else if (error == ERR_INV_CHARS)
	{
		ft_printf("Error, the map can only contain 1's, "
			"0's, C's, an E and a P\n");
	}
	else if (error == ERR_NO_PATH)
		ft_printf("Error, the player can't reach the exit\n");
	else if (error == ERR_GRAPH)
		ft_printf("Error, graphics could not be loaded\n");
	return (0);
}
