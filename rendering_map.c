/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:43 by lnierobi          #+#    #+#             */
/*   Updated: 2024/12/09 17:55:36 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_texture(t_texture *texture)
{
	texture->exit = mlx_load_png("images/exit.png");
	texture->player = mlx_load_png("images/player.png");
	texture->collectible = mlx_load_png("images/colectibel.png");
	texture->wall = mlx_load_png("images/wall.png");
	texture->floor = mlx_load_png("images/floor.png");
}

void	rendering_texture(t_image *image, t_texture *texture, mlx_t *mlx)
{
	image->coffee = mlx_texture_to_image(mlx, texture->collectible);
	image->exit = mlx_texture_to_image(mlx, texture->exit);
	image->player = mlx_texture_to_image(mlx, texture->player);
	image->wall = mlx_texture_to_image(mlx, texture->wall);
	image->backround = mlx_texture_to_image(mlx, texture->floor);
}

mlx_image_t	*texture_to_image(t_image *image, char map_char)
{
	if (map_char == '0')
	{
		return (image->backround);
	}
	else if (map_char == '1')
	{
		return (image->wall);
	}
	else if (map_char == 'E')
	{
		return (image->exit);
	}
	else if (map_char == 'P')
	{
		return (image->player);
	}
	else if (map_char == 'C')
	{
		return (image->coffee);
	}
	else
	{
		return (NULL);
	}
}

void	render(t_game *game, size_t i, size_t j)
{
	mlx_image_t	*img;
	mlx_image_t	*bg_pl;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			img = texture_to_image(&game->image, game->map[i][j]);
			bg_pl = texture_to_image(&game->image, '0');
			mlx_resize_image(img, 50, 50);
			if (img)
			{
				if (game->map[i][j] == 'P')
					mlx_image_to_window(game->mlx, bg_pl, j * 50, i * 50);
				mlx_image_to_window(game->mlx, img, j * 50, i * 50);
			}
			if (!img || (mlx_image_to_window(game->mlx, img, 0, 0) < 0))
				exit(1);
			j++;
		}
		i++;
	}
}

void	map_rendering(t_game *game)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	load_texture(&game->texture);
	rendering_texture(&game->image, &game->texture, game->mlx);
	render(game, i, j);
	delete_texture(&game->texture);
}
