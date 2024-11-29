/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:32 by lnierobi          #+#    #+#             */
/*   Updated: 2024/11/29 17:08:32 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement(mlx_key_data_t key, void* param)
{

	t_game	*game;
	game = (t_game *)param;
	game->move_count = 0;

	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		ft_free_map(&game->map);
		exit(0);
	}
	else if(key.key == MLX_KEY_UP && key.action == MLX_PRESS && game->map[game->player_position.x-1][game->player_position.y] != '1')
	{
		go_up(game);
	}
	else if(key.key == MLX_KEY_DOWN && key.action == MLX_PRESS && game->map[game->player_position.x + 1][game->player_position.y] != '1')
	{
		go_down(game);
	}
	else if(key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS && game->map[game->player_position.x][game->player_position.y + 1] != '1')
	{
		go_right(game);
	}
	else if(key.key == MLX_KEY_LEFT && key.action == MLX_PRESS && game->map[game->player_position.x][game->player_position.y - 1] != '1')
	{
		go_left(game);
	}
}

void go_up(t_game *game)
{
		if(game->map[game->player_position.x][game->player_position.y] == 'E' && game->num_colectibles == 0)
		game_sucess(game);
	ft_printf("Bevor Bewegung: x = %i, y = %i\n", game->player_position.x, game->player_position.y);
	if(game ->map[game->player_position.x][game->player_position.y]== 'E')
	{
		mlx_image_to_window(game->mlx, game->image.exit, game->player_position.y * 50, game->player_position.x * 50);
		game->player_position.x--;
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image.backround, game->player_position.y * 50, game->player_position.x * 50);
		game->player_position.x--;
	}
	if(game->map[game->player_position.x][game->player_position.y] == 'C')
	{
		game->num_colectibles--;
		mlx_image_to_window(game->mlx, game->image.backround, game->player_position.y * 50, game->player_position.x * 50);
		game->map[game->player_position.x][game->player_position.y] = '0';
	}
	mlx_image_to_window(game->mlx, game->image.player, game->player_position.y *50, game->player_position.x * 50);
	game->move_count++;
	ft_printf("Nach Bewegung: x = %i, y = %i\n", game->player_position.x, game->player_position.y);
	ft_printf("count of moves: %d\n", game->move_count);
}
void go_down(t_game *game)
{
	if(game->map[game->player_position.x][game->player_position.y] == 'E' && game->num_colectibles == 0)
		game_sucess(game);
	ft_printf("Bevor Bewegung: x = %i, y = %i\n", game->player_position.x, game->player_position.y);
	if(game ->map[game->player_position.x][game->player_position.y]== 'E')
	{
	ft_printf("go down after player on exit");
		mlx_image_to_window(game->mlx, game->image.exit, game->player_position.y * 50, game->player_position.x * 50);
		game->player_position.x++;
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image.backround, game->player_position.y * 50, game->player_position.x * 50);
		game->player_position.x++;
	}
	if(game->map[game->player_position.x][game->player_position.y] == 'C')
	{
		game->num_colectibles--;
		mlx_image_to_window(game->mlx, game->image.backround, game->player_position.y * 50, game->player_position.x * 50);
		game->map[game->player_position.x][game->player_position.y] = '0';
	}
	mlx_image_to_window(game->mlx, game->image.player, game->player_position.y *50, game->player_position.x * 50);
	game->move_count++;
	ft_printf("Nach Bewegung: x = %i, y = %i\n", game->player_position.x, game->player_position.y);
	ft_printf("count of moves: %d\n", game->move_count);
}
void go_right(t_game *game)
{
	if(game->map[game->player_position.x][game->player_position.y] == 'E' && game->num_colectibles == 0)
		game_sucess(game);
	ft_printf("Bevor Bewegung: x = %i, y = %i\n", game->player_position.x, game->player_position.y);
	if(game ->map[game->player_position.x][game->player_position.y]== 'E')
	{
		mlx_image_to_window(game->mlx, game->image.exit, game->player_position.y * 50, game->player_position.x * 50);
		game->player_position.y++;
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image.backround, game->player_position.y * 50, game->player_position.x * 50);
		game->player_position.y++;
	}
	if(game->map[game->player_position.x][game->player_position.y] == 'C')
	{
		game->num_colectibles--;
		mlx_image_to_window(game->mlx, game->image.backround, game->player_position.y * 50, game->player_position.x * 50);
		game->map[game->player_position.x][game->player_position.y] = '0';
	}
	mlx_image_to_window(game->mlx, game->image.player, game->player_position.y *50, game->player_position.x * 50);
	game->move_count++;
	ft_printf("Nach Bewegung: x = %i, y = %i\n", game->player_position.x, game->player_position.y);
	ft_printf("count of moves: %d\n", game->move_count);
}
void go_left(t_game *game)
{
	if(game->map[game->player_position.x][game->player_position.y] == 'E' && game->num_colectibles == 0)
		game_sucess(game);
	ft_printf("Bevor Bewegung: x = %i, y = %i\n", game->player_position.x, game->player_position.y);
	if(game ->map[game->player_position.x][game->player_position.y]== 'E')
	{
		mlx_image_to_window(game->mlx, game->image.exit, game->player_position.y * 50, game->player_position.x * 50);
		game->player_position.y--;
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image.backround, game->player_position.y * 50, game->player_position.x * 50);
		game->player_position.y--;
	}
	if(game->map[game->player_position.x][game->player_position.y] == 'C')
	{
		game->num_colectibles--;
		mlx_image_to_window(game->mlx, game->image.backround, game->player_position.y * 50, game->player_position.x * 50);
		game->map[game->player_position.x][game->player_position.y] = '0';
	}
	mlx_image_to_window(game->mlx, game->image.player, game->player_position.y *50, game->player_position.x * 50);
	game->move_count++;
	ft_printf("Nach Bewegung: x = %i, y = %i\n", game->player_position.x, game->player_position.y);
	ft_printf("count of moves: %d\n", game->move_count);
}
void game_sucess(t_game *game)
{
	ft_free_map(&game->map);
	exit(0);
}
// void game_sucess(t_game *game)
// {
// 	int i = 0;

// 	if(game)
// }