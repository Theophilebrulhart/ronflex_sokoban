/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:44:57 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/15 19:18:16 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"
# include "editor.h"
# include "files_management.h"
# include "game.h"
# include "mlx/mlx.h"
#include "mlx_hook.h"
#include "next_level.h"

void	ronflex_editor(t_game *game, int i, int j)
{
	game->x_position = j;
	game->y_position = i;
	mlx_put_image_to_window(game->mlx, game->win, game->ronflex_orientation, game->x_position * SIZE_BLOCK, game->y_position * SIZE_BLOCK);
}

void	map_editor(t_game *game)
{
	int	y;
	int	x;
	game->box_ok = mlx_xpm_file_to_image(game->mlx, "./sprites/box_ok.xpm", &game->width, &game->heigth);
	game->box = mlx_xpm_file_to_image(game->mlx, "./sprites/box.xpm", &game->width, &game->heigth);
	game->superball = mlx_xpm_file_to_image(game->mlx, "./sprites/superball.xpm", &game->width, &game->heigth);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &game->width, &game->heigth);
	game->ronflex_down = mlx_xpm_file_to_image(game->mlx, "./sprites/charac/ronflex_down.xpm", &game->width, &game->heigth);
	game->ronflex_left = mlx_xpm_file_to_image(game->mlx, "./sprites/charac/ronflex_left.xpm", &game->width, &game->heigth);
	game->ronflex_right = mlx_xpm_file_to_image(game->mlx, "./sprites/charac/ronflex_right.xpm", &game->width, &game->heigth);
	game->ronflex_up = mlx_xpm_file_to_image(game->mlx, "./sprites/charac/ronflex_up.xpm", &game->width, &game->heigth);
	game->ronflex_orientation = game->ronflex_down;
	game->cursor.img = mlx_new_image(game->mlx, SIZE_BLOCK, SIZE_BLOCK);
	game->cursor.addr = (int *)mlx_get_data_addr(game->cursor.img, &game->cursor.bpp, &game->cursor.l_size, &game->cursor.endian);
	game->cursor.x_position = 6;
	game->cursor.y_position = 6;
	game->ronflex_check = 0;
	game->editor_check = 1;
	y = 0;
	while (y < SIZE_BLOCK)
	{
		x = 0;
		while (x < SIZE_BLOCK)
		{
			game->cursor.addr[y * SIZE_BLOCK + x] = 0x79DDDDDD;
			x++;
		}
		y++;
	}
	mlx_hook(game->win, 2, 1L<<0, map_change, game);
	y = 0;
	while (y < NBR_BLOCK_HEIGTH)
	{
		x = 0;
		while (x < NBR_BLOCK_WIDTH)
		{
			if ((x == 0 || x == 11) || (y == 0 || y == 11))
				game->map[y][x] = WALL;
			else {
				game->map[y][x] = VOID;
			}
				
			x++;
		}
		y++;
	}
	printf("cursor.x_position ; %d \n", game->cursor.x_position);
	printf("cursor.y_position ; %d \n", game->cursor.y_position);
	display_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->cursor.img, game->cursor.x_position * SIZE_BLOCK, game->cursor.y_position * SIZE_BLOCK);

	
	
	
}