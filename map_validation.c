/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:55:19 by lnierobi          #+#    #+#             */
/*   Updated: 2024/10/21 18:16:35 by lnierobi         ###   ########.fr       */
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
	while (game->map[i])
	{
		while (game->map[i][j])
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
	while (game->map[i])
	{
		while (game->map[i][j] == 'P')
			p_found++;
		j++;
	}
	i++;
	if (p_found != 1)
	{
		return (false);
	}
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
	while (game->map[i])
	{
		while (game->map[i][j] == 'C')
			c_found++;
		j++;
	}
	i++;
	if (c_found < 1)
	{
		return (false);
	}
	return (true);
}
void	map_validation(t_game *game)
{
	if (!left_side_wall(game))
	{
		ft_putstr_fd("Error left side wall\n",2);
		return;
	}
	if (!right_side_wall(game))
	{
		ft_putstr_fd("Error right side wall\n",2);
		return;
	}
	if(!down_wall(game))
	{
		ft_putstr_fd("Error down wall\n",2);
		return;
	}
	if(!top_wall(game))
	{
		ft_putstr_fd("Error top wall\n",2);
		return;
	}
	if(!colect_valid(game))
	{
		ft_putstr_fd("Error collectables\n",2);
	}

	return;
}