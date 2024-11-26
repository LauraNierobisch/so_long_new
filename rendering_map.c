/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:43 by lnierobi          #+#    #+#             */
/*   Updated: 2024/11/26 11:20:25 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_texture(t_game *game)
{
	game->exit_texture = mlx_load_png("images/exit.png");
	game->player_texture = mlx_load_png("images/player.png");
	game->collectible_texture = mlx_load_png("images/colectible.png");
	game->wall_texture = mlx_load_png("images/wall.png");
	game->backround_texture = mlx_load_png("images/floor.png");
}
void	rendering_textur(t_game *game)
{
	game->exit_image = mlx_texture_to_image(game->mlx, game->exit_texture);
	game->player_image = mlx_texture_to_image(game->mlx, game->player_texture);
	game->collectible_image = mlx_texture_to_image(game->mlx,
			game->collectible_texture);
	game->wall_image = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->backround_image = mlx_texture_to_image(game->mlx,
			game->backround_texture);
}
mlx_image_t	*texture_to_image(t_game *game, char map_char)
{
	if (map_char == '0')
	{
		return (game->backround_image);
	}
	else if (map_char == '1')
	{
		return (game->wall_image);
	}
	else if (map_char == 'E')
	{
		return (game->exit_image);
	}
	else if (map_char == 'P')
	{
		return (game->palyer_image);
	}
	else if (map_char == 'C')
	{
		return (game->collectible_image);
	}
	else
	{
		return (NULL);
	}
}

void	map_rendering(t_game *game)
{
	size_t i;
	size_t j;
	mlx_image_t *img;

	i = 0;
	load_textures(game);
	render_textures(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			img = mlx_texture_to_image(game, game->map[i][j]);
			if (img)
				mlx_image_to_window(game->mlx, img, j * 50, i * 50);
			j++;
		}
		i++;
	}
	clean_texture(game);
}