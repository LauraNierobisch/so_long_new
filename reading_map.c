/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:52:07 by lnierobi          #+#    #+#             */
/*   Updated: 2024/12/10 12:08:15 by lnierobi         ###   ########.fr       */
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

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Wrong path to map\n");
		exit(1);
	}
	return (fd);
}

void	free_stuff(char *line, char *map_string, int fd)
{
	free(line);
	free(map_string);
	close(fd);
	exit(1);
}

char	*read_lines(int fd)
{
	char	*line;
	char	*map_string;
	char	*tmp;

	map_string = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error: empty map file\n");
		exit(1);
	}
	while (line != NULL)
	{
		if (map_string == NULL)
			tmp = ft_strdup(line);
		else
			tmp = ft_strjoin(map_string, line);
		if (!tmp)
			free_stuff(line, map_string, fd);
		free(map_string);
		map_string = tmp;
		free(line);
		line = get_next_line(fd);
	}
	return (map_string);
}

void	validate_map(char *map_string)
{
	if (!nl_valid(map_string))
	{
		ft_putstr_fd("Error empthy line\n", 2);
		free(map_string);
		exit(1);
	}
}
