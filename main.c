/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:25 by lnierobi          #+#    #+#             */
/*   Updated: 2024/11/28 14:54:43 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	t_game game;
	argc = 0;
	reading_map(&game, argv[1]);
	map_validation(&game);
	game.mlx = mlx_init(game.width * BLOCK, game.height * BLOCK, "so_long", true);
	if (!game.mlx)
		exit(1);
	// function which deletes all and free
	map_rendering(&game);
	// ft_printf("ass\n");
	mlx_key_hook(game.mlx, &player_movement, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	mlx_delete_image(game.mlx, game.image.coffee);
	mlx_delete_image(game.mlx, game.image.exit);
	mlx_delete_image(game.mlx, game.image.player);
	mlx_delete_image(game.mlx, game.image.wall);
	mlx_delete_image(game.mlx, game.image.backround);
	mlx_delete_texture(game.texture.collectible);
	mlx_delete_texture(game.texture.exit);
	mlx_delete_texture(game.texture.player);
	mlx_delete_texture(game.texture.wall);
	mlx_delete_texture(game.texture.floor);
	ft_free_map(&game.map);
	return (0);
}