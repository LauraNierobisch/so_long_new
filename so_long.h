/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:58:00 by lnierobi          #+#    #+#             */
/*   Updated: 2024/12/09 14:35:54 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>

# define BLOCK 50

typedef struct s_position
{
	size_t			x;
	size_t			y;
}					t_position;

typedef struct s_texture
{
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
}					t_texture;

typedef struct s_image
{
	mlx_image_t		*coffee;
	mlx_image_t		*exit;
	mlx_image_t		*player;
	mlx_image_t		*wall;
	mlx_image_t		*backround;
}					t_image;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				maplines;
	int				fd;
	char			*line;
	char			*map_string;
	char			*tmp;
	int				width;
	int				height;
	int				leng;
	int				num_colectibles;
	int				move_count;
	t_texture		texture;
	t_position		player_position;
	t_image			image;
}					t_game;

bool				top_wall(t_game *game);
bool				down_wall(t_game *game);
bool				right_side_wall(t_game *game);
bool				left_side_wall(t_game *game);
bool				exit_valid(t_game *game);
bool				colect_valid(t_game *game);
void				reading_map(t_game *game, char *path);
void				map_validation(t_game *game);
void				load_texture(t_texture *texture);
void				rendering_texture(t_image *image, t_texture *texture,
						mlx_t *mlx);
mlx_image_t			*texture_to_image(t_image *image, char map_char);
void				map_rendering(t_game *game);
void				delete_texture(t_texture *texture);
bool				validate_map_accessibility(t_game *game);
bool				check_accessible(char **map_copy, char **original_map);
bool				find_player_position(char **map, int *player_x,
						int *player_y);
void				ft_free_map(char ***map);
char				**copy_map(char **map);
void				flood_fill(char **map, int x, int y);
bool				checking_false_chars(t_game *game);
void				player_movement(mlx_key_data_t key, void *param);
void				go_up(t_game *game);
void				go_down(t_game *game);
void				go_right(t_game *game);
void				go_left(t_game *game);
void				game_sucess(t_game *game);
bool				nl_valid(char *mapstring);
#endif