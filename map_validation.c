/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:55:19 by lnierobi          #+#    #+#             */
/*   Updated: 2024/11/28 12:47:13 by lnierobi         ###   ########.fr       */
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
				p_found++;
			j++;
		}
		i++;
	}
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
	if (c_found < 1)
	{
		return (false);
	}
	return (true);
}
void	map_validation(t_game *game)
{
	int i;
	i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}

	if (!left_side_wall(game))
	{
		ft_putstr_fd("Error left side wall\n", 2);
		exit(1);
	}
	if (!right_side_wall(game))
	{
		ft_putstr_fd("Error right side wall\n", 2);
		exit(1);
	}
	if (!down_wall(game))
	{
		ft_putstr_fd("Error down wall\n", 2);
		exit(1);
	}
	if (!top_wall(game))
	{
		ft_putstr_fd("Error top wall\n", 2);
		exit(1);
	}
	if (!colect_valid(game))
	{
		ft_putstr_fd("Error collectables\n", 2);
		exit(1);
	}
	if (!player_valid(game))
	{
		ft_putstr_fd("Error player\n", 2);
		exit(1);
	}
	if (!exit_valid(game))
	{
		ft_putstr_fd("Error exit\n", 2);
		exit(1);
	}
	if (!validate_map_accessibility(game))
	{
		ft_putstr_fd("Error: Map not accessible\n", 2);
		exit(1);
	}
	if (!checking_false_chars(game))
	{
		ft_putstr_fd("Error: wrong chars\n", 2);
		exit(1);
	}
}
// void map_validation(t_game *game)
// {
//     if (!left_side_wall(game))
//     {
//         ft_putstr_fd("Error left side wall\n", 2);
//         exit(1);
//     }
//     if (!right_side_wall(game))
//     {
//         ft_putstr_fd("Error right side wall\n", 2);
//         exit(1);
//     }
//     if (!down_wall(game))
//     {
//         ft_putstr_fd("Error down wall\n", 2);
//         exit(1);
//     }
//     if (!top_wall(game))
//     {
//         ft_putstr_fd("Error top wall\n", 2);
//         exit(1);
//     }
//     if (!colect_valid(game))
//     {
//         ft_putstr_fd("Error collectables\n", 2);
//         exit(1);
//     }
//     if (!validate_map_accessibility(game))
//     {
//         ft_putstr_fd("Error: Map not accessible\n", 2);
//         exit(1);
//     }
// }
