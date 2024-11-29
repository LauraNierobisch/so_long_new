/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:32 by lnierobi          #+#    #+#             */
/*   Updated: 2024/11/28 14:59:51 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement(mlx_key_data_t key, void* param)
{
	char	**map_copy;
	t_game *game;
	game = param;
	game->move_count = 0; 
	map_copy = copy_map(game->map);

	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		ft_free_map(&game->map);
		exit(0);
	}
	else if(key.key == MLX_KEY_UP && key.action == MLX_PRESS && game->map[x - 1][y] != '1')
	{
		go_up(game);
	}
	else if(key.key == MLX_KEY_DOWN && key.action == MLX_PRESS && game->map[x + 1][y] != '1')
	{
		go_down(game);
	}
	else if(key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS && game->map[x - 1][y] != '1')
	{
		go_right(game);
	}
	else if(key.key == MLX_KEY_LEFT && key.action == MLX_PRESS && game->map[x + 1][y] != '1')
	{
		go_left(game);
	}
}

void go_up(t_game *game)
{
	if(game->map[game ->player_position->y] == 'E' && game->collectibles_number-> == 0)
		game_sucess(game);
	if(game ->map[game->player_position->x][game->player_position->y]== 'E')
	{
		mlx_image_to_window(game->mlx, game->exit_image, game->player_position->y * 50, game->player_position-> * 50)
	}
	else 
	{
		mlx_image_to_window(game->mlx, game->backround_image, game->player_position->y * 50, game-> player_position->x * 50);
		game->player_position->x--;
	}
	if(game->map[game->player_position->x][game->player_position->y] == 'C')
	{
		game->num_colectibles--;
		mlx_image_to_window(game->mlx, game->background_image, game->player_position->y * 50, game->player_position-> * 50);
		game->map[game->player_position->][game->player_position->] = '0';
	}
	mlx_image_to_window(game->mlx, game->player_image, game->player_poition->y *50, game -> player_position->x * 50);
	game->move_count++;
	ft_printf("count of moves: %d\n", game->move_count);
}