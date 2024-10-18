/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:58:00 by lnierobi          #+#    #+#             */
/*   Updated: 2024/10/18 11:41:04 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx42/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_position;
{
	size_t x;
	size_t y;
}			t_position;
typedef struct s_game
{
	char **map;
}	t_game;

bool	top_wall(t_game *game);
bool	down_wall(t_game *game);
bool	right_side_wall(t_game *game);
bool	left_side_wall(t_game *game);
bool	exit_valid(t_game *game);
bool	exit_valid(t_game *game);
bool	colect_valid(t_game *game);

#endif