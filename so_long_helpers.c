/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:10:43 by lnierobi          #+#    #+#             */
/*   Updated: 2024/12/10 13:08:19 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_sucess(t_game *game)
{
	mlx_delete_image(game->mlx, game->image.coffee);
	mlx_delete_image(game->mlx, game->image.exit);
	mlx_delete_image(game->mlx, game->image.player);
	mlx_delete_image(game->mlx, game->image.wall);
	mlx_delete_image(game->mlx, game->image.backround);
	mlx_terminate(game->mlx);
	ft_free_map(&game->map);
	exit(0);
}

void	split_map(t_game *game, char *map_string)
{
	game->map = ft_split(map_string, '\n');
	if (!game->map)
	{
		free(map_string);
		exit(1);
	}
	free(map_string);
}

void	path_name_checker(char *path)
{
	char	*str;
	int		i;
	int		j;

	str = "ber";
	j = 0;
	i = ft_strlen(path) - 3;
	if (path[i] == str[j])
	{
		i++;
		j++;
	}
	else
	{
		ft_putstr_fd("Error wrong map name\n", 2);
		exit(1);
	}
}

void	reading_map(t_game *game, char *path)
{
	int		fd;
	char	*map_string;

	path_name_checker(path);
	fd = open_file(path);
	map_string = read_lines(fd);
	close(fd);
	validate_map(map_string);
	split_map(game, map_string);
}

void	delete_texture(t_texture *texture)
{
	mlx_delete_texture(texture->exit);
	mlx_delete_texture(texture->player);
	mlx_delete_texture(texture->wall);
	mlx_delete_texture(texture->floor);
	mlx_delete_texture(texture->collectible);
}
