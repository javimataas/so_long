/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:10:06 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/06/05 17:44:14 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// leaks
void	ft_leaks(void)
{
	system("leaks -q so_long");
}

// Check if argv[1] is a .ber file
int	ft_is_ber(char *file)
{
	int		file_len;
	int		ext_len;
	char	*aux;

	file_len = ft_strlen(file);
	ext_len = ft_strlen(".ber");
	if (file_len < ext_len)
		return (0);
	aux = file + (file_len - ext_len);
	if (ft_strcmp(aux, ".ber") == 0)
		return (1);
	else
		return (0);
}

// Creates the map from the file and inits the game
void	ft_run(char *file)
{
	char	**map;

	map = ft_load_map(file);
	if (!ft_correct_map(map))
	{
		ft_free_str_array(map);
		exit (1);
	}
	ft_free_str_array(map);
	map = ft_load_map(file);
	ft_init_game(map);
	ft_free_str_array(map);
}

// Main function, starts the program
int	main(int argc, char **argv)
{
	int	fd;

	atexit(ft_leaks);
	if (argc != 2)
	{
		ft_error(ERR_INVALID_ARGS);
		exit(1);
	}
	if (ft_is_ber(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_error(ERR_FILE_ACCESS);
			exit(1);
		}
		close(fd);
		ft_run(argv[1]);
		exit(0);
	}
	ft_error(ERR_FILE_EXT);
	exit(1);
}
