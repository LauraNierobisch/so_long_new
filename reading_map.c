/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:07 by lnierobi          #+#    #+#             */
/*   Updated: 2024/11/27 17:40:15 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reading_map(t_game *game, char *path)
{
	int maplines;
	int fd;
	char *line;
	char *map_string;
	char *tmp;

	map_string = NULL;
	maplines = 0;
	line = NULL;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;

	line = get_next_line(fd);
	if(!line)
	{
		ft_printf("Error: empthy map file\n");
		exit(1);
	}
	while (line != NULL)
	{
		maplines++;
		if (map_string == NULL)
			tmp = ft_strdup(line);
		else
			tmp = ft_strjoin(map_string, line);

		if (tmp == NULL)
		{
			free(line);
			free(map_string);
			close(fd);
			exit(1);
		}

		free(map_string);
		map_string = tmp;

		free(line);
		line = get_next_line(fd);
	}
	close(fd);

	game->map = ft_split(map_string, '\n');
	if (!game->map)
	{
		free(map_string);
		return ;
	}
	free(map_string);
}

// void with_map(t_game *game)
// {
// 	game->width = 0;

// 	while (game->map[game->width + 1] != NULL)
// 		game->width++;
// }
// void leng_map(t_game *game)
// {
// 	game->leng = 0;
// 	int i = 0;
// 	game->leng = ft_strlen(game->map[i]);
// }
