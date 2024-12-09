/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:59 by lnierobi          #+#    #+#             */
/*   Updated: 2024/12/09 15:52:34 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	top_wall(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != '\0')
	{
		if (game->map[0][i] != '1')
			return (false);
		if (game->map[0][i + 1] == '\n')
			break ;
		i++;
	}
	return (true);
}

bool	checking_false_chars(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] != '1' && game->map[j][i] != 'E'
				&& game->map[j][i] != '0' && game->map[j][i] != 'P'
				&& game->map[j][i] != 'C')
			{
				return (false);
			}
			i++;
		}
		j++;
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
	{
		last++;
	}
	while (game->map[last][i] != '\0')
	{
		if (game->map[last][i] != '1')
		{
			return (false);
		}
		i++;
	}
	game->width = i;
	return (true);
}

bool	right_side_wall(t_game *game)
{
	int	i;
	int	len;
	int	flag;

	flag = 0;
	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (i == 0)
			flag = len;
		if (game->map[i][len - 1] != '1')
			return (false);
		else if (len != flag)
			return (false);
		if (game->map[i + 1] == NULL)
			break ;
		i++;
	}
	game->height = i + 1;
	return (true);
}

bool	left_side_wall(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1')
			return (false);
		i++;
	}
	return (true);
}
