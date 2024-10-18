/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:59 by lnierobi          #+#    #+#             */
/*   Updated: 2024/10/18 11:40:07 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <so_long.h>

bool	top_wall(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (false);
	}
	return (true);
}

bool	down_wall(t_game *game)
{
	int	i;
	int	last;

	i = 0;
	last = 0;
	while (game->map[last + 1] != NULL)
		last++;
	while (game->map[last][i] != '\0')
	{
		if (game->map[last][i] != '1')
			return (false);
		i++;
	}
	return (true);
}
bool	right_side_wall(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map[i]);
	while (game->map[i][len - 1])
	{
		if (game->map[i][len - 1] != '1')
		{
			return (false);
		}
		i++;
	}
	return (true);
}
bool	left_side_wall(t_game *game)
{
	int i;
	i = 0;
	if (game->map[i][0] != '1')
		return (false);
	i++;
	return (true);
}