/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:55:19 by lnierobi          #+#    #+#             */
/*   Updated: 2024/12/10 12:48:36 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	exit_valid(t_game *game)
{
	int	e_found;
	int	i;
	int	j;

	e_found = 0;
	i = 0;
	j = 1;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				e_found++;
			j++;
		}
		i++;
	}
	if (e_found != 1)
	{
		return (false);
	}
	return (true);
}

bool	player_valid(t_game *game)
{
	int	p_found;
	int	i;
	int	j;

	p_found = 0;
	i = 0;
	j = 1;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_position.x = i;
				game->player_position.y = j;
				p_found++;
			}
			j++;
		}
		i++;
	}
	if (p_found != 1)
		return (false);
	return (true);
}

bool	colect_valid(t_game *game)
{
	int	c_found;
	int	i;
	int	j;

	c_found = 0;
	i = 0;
	j = 1;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				c_found++;
			j++;
		}
		i++;
	}
	game->num_colectibles = c_found;
	if (c_found < 1)
	{
		return (false);
	}
	return (true);
}

void	map_validation(t_game *game)
{
	int	i;

	i = 0;
	if (!left_side_wall(game))
	{
		ft_putstr_fd("Error left side wall\n", 2);
		exit_mlx(game);
	}
	if (!right_side_wall(game))
	{
		ft_putstr_fd("Error right side wall\n", 2);
		exit_mlx(game);
	}
	if (!down_wall(game))
	{
		ft_putstr_fd("Error down wall\n", 2);
		exit_mlx(game);
	}
	if (!top_wall(game))
	{
		ft_putstr_fd("Error top wall\n", 2);
		exit_mlx(game);
	}
	map_validation_2(game);
}

void	map_validation_2(t_game *game)
{
	if (!colect_valid(game))
	{
		ft_putstr_fd("Error collectables\n", 2);
		exit_mlx(game);
	}
	if (!player_valid(game))
	{
		ft_putstr_fd("Error player\n", 2);
		exit_mlx(game);
	}
	if (!exit_valid(game))
	{
		ft_putstr_fd("Error exit\n", 2);
		exit_mlx(game);
	}
	if (!validate_map_accessibility(game))
	{
		ft_putstr_fd("Error: Map not accessible\n", 2);
		exit_mlx(game);
	}
	if (!checking_false_chars(game))
	{
		ft_putstr_fd("Error: wrong chars\n", 2);
		exit_mlx(game);
	}
}
