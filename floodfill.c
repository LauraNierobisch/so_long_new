/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:51:46 by lnierobi          #+#    #+#             */
/*   Updated: 2024/11/29 17:04:10 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0'
		|| map[y][x] == '1')
		return;
	if (map[y][x] == 'F')
		return;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i] != NULL)
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			ft_free_map(&copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i] != NULL)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}
bool	find_player_position(char **map, int *player_x, int *player_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				*player_x = x;
				*player_y = y;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}
// bool	find_player_position_for_struct(char **map, t_game *game)
// {
// 	int	x;
// 	int	y;

// 	x = -1;
// 	y = 0;
// 	while (map[y] != NULL)
// 	{
// 		x = 0;
// 		while (map[y][x] != '\0')
// 		{
// 			if (map[y][x] == 'P')
// 			{
// 				game->player_position.x = x;
// 				game->player_position.y = y + 1;
// 				ft_printf("position x: %i", game->player_position.x);
// 				ft_printf("position y: %i", game->player_position.y);
// 				return (true);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}

// 	return (false);
// }
bool	check_accessible(char **map_copy, char **original_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (original_map[y] != NULL)
	{
		x = 0;
		while (original_map[y][x] != '\0')
		{
			if ((original_map[y][x] == 'C' || original_map[y][x] == 'E')
				&& map_copy[y][x] != 'F')
			{
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
bool	validate_map_accessibility(t_game *game)
{
	char	**map_copy;
	int		player_x;
	int		player_y;

	player_x = -1;
	player_y = -1;
	map_copy = copy_map(game->map);
	if (!map_copy)
		return (false);
	if (!find_player_position(game->map, &player_x, &player_y))
	{
		ft_free_map(&map_copy);
		return (false);
	}
	flood_fill(map_copy, player_x, player_y);
	if (!check_accessible(map_copy, game->map))
	{
		ft_free_map(&map_copy);
		return (false);
	}
	ft_free_map(&map_copy);
				ft_printf("FREE IN FLOOD_FILL\n");
	//find_player_position_for_struct(game->map, game);

	return (true);
}
