/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:07 by lnierobi          #+#    #+#             */
/*   Updated: 2024/10/21 18:05:43 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reading_map(t_game *game, char *path)
{
	int		maplines;
	int		fd;
	char	*line;
	char	*map_string;
	char	*tmp;

	map_string = NULL;
	maplines = 0;
	line = NULL;
	// char **map;
	fd = open(path, O_RDONLY);
	ft_printf(" %i\n", fd);
	// wie wollen das nicht in printf einlesen sondenrn in x und y damit ich flood fillen kann.
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	// ft_printf("%s", line);
	while (line != NULL)
	{
		maplines++;
		if (map_string == NULL)
			tmp = line;
		else
			tmp = ft_strjoin(map_string, line);
		// ft_printf("ass\n");
		if (tmp == NULL)
		{
			free(line);
			return (close(fd), free(map_string));
		}
		// free(map_string);
		ft_printf("%s", line);
		map_string = tmp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = ft_split(map_string, '\n');
	if (!game->map)
	{
		free(map_string);
	}
	free(map_string);
}
