/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:25 by lnierobi          #+#    #+#             */
/*   Updated: 2024/12/09 16:03:16 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

// void	leaks(void)
// {
// 	system("leaks so_long");
// 		atexit((void *)leaks);
// }

void	check_success(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->map[game->player_position.x][game->player_position.y] == 'E'
		&& game->num_colectibles == 0)
		game_sucess(game);
}

int	exit_mlx(t_game *game)
{
	ft_free_map(&game->map);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (1);
	argc = 0;
	reading_map(&game, argv[1]);
	map_validation(&game);
	game.mlx = mlx_init(game.width * BLOCK, game.height * BLOCK, "so_long",
			true);
	if (!game.mlx)
		exit_mlx(&game);
	map_rendering(&game);
	mlx_key_hook(game.mlx, &player_movement, &game);
	mlx_loop_hook(game.mlx, &check_success, &game);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.image.coffee);
	mlx_delete_image(game.mlx, game.image.exit);
	mlx_delete_image(game.mlx, game.image.player);
	mlx_delete_image(game.mlx, game.image.wall);
	mlx_delete_image(game.mlx, game.image.backround);
	mlx_terminate(game.mlx);
	ft_free_map(&game.map);
	return (0);
}
