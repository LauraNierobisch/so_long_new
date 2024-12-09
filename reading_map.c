/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:07 by lnierobi          #+#    #+#             */
/*   Updated: 2024/12/09 14:32:43 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	nl_valid(char *mapstring)
{
	int	i;

	i = 0;
	if (mapstring[0] == '\n')
		return (false);
	while (mapstring[i])
	{
		if (mapstring[i] == '\n' && mapstring[i + 1] == '\n')
		{
			return (false);
		}
		i++;
	}
	if (mapstring[i - 1] == '\n')
	{
		return (false);
	}
	return (true);
}

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
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Wrong path to map\n");
		exit(1);
	}
	line = get_next_line(fd);
	if (!line)
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
	if (!nl_valid(map_string))
	{
		free(map_string);
		exit(1);
	}
	game->map = ft_split(map_string, '\n');
	if (!game->map)
	{
		free(map_string);
		exit(1);
	}
	free(map_string);
}

