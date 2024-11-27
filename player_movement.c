/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:32 by lnierobi          #+#    #+#             */
/*   Updated: 2024/11/27 19:39:53 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	player_movement(mlx_key_data_t key, void* param)
{
	char	**map_copy;
	t_game *game;
	game = param;
	map_copy = copy_map(game->map);

	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		ft_free_map(game->map);
}