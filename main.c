/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:56:25 by lnierobi          #+#    #+#             */
/*   Updated: 2024/10/21 18:08:26 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
		return (1);
	t_game	game;
	argc = 0;
	reading_map(&game, argv[1]);
	map_validation(&game);
	return (0);
}