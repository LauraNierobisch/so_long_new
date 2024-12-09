/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:10:43 by lnierobi          #+#    #+#             */
/*   Updated: 2024/12/09 17:55:04 by lnierobi         ###   ########.fr       */
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

void	reading_map(t_game *game, char *path)
{
	int		fd;
	char	*map_string;

	fd = open_file(path);
	map_string = read_lines(fd);
	close(fd);
	validate_map(map_string);
	split_map(game, map_string);
}

void	ft_free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i] != NULL)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

void	delete_texture(t_texture *texture)
{
	mlx_delete_texture(texture->exit);
	mlx_delete_texture(texture->player);
	mlx_delete_texture(texture->wall);
	mlx_delete_texture(texture->floor);
	mlx_delete_texture(texture->collectible);
}
