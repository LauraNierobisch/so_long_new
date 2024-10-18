/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:55:19 by lnierobi          #+#    #+#             */
/*   Updated: 2024/10/18 11:40:45 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

bool	exit_valid(t_game *game)
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
	int c_found = 0;
	int i = 0;
	int j = 1;

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