/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:34 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/14 00:18:20 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"
# include "editor.h"
# include "files_management.h"
# include "game.h"
# include "mlx/mlx.h"
#include "mlx_hook.h"
#include "next_level.h"

void display_game(t_game *game)
{
	int	i;
	int j;
	int	x;
	int	y;

	i = 0;
	game->objectif = 0;
	while (i < NBR_BLOCK_HEIGTH)
	{
		j = 0;
		while (j < NBR_BLOCK_WIDTH)
		{
			if (game->map[i][j] == VOID || game->map[i][j] == SUPERBALL || game->map[i][j] == RONFLEX)
			{
				y = 0;
				while (y < SIZE_BLOCK)
				{
					x = 0;
					while (x < SIZE_BLOCK)
					{
						mlx_pixel_put(game->mlx, game->win, j * SIZE_BLOCK + y, i * SIZE_BLOCK + x, 0x00343434);
						x++;
					}
					y++;	
				}
			}
			if (game->map[i][j] == RONFLEX)
			{
				game->x_position = j;
				game->y_position = i;
				game->map[i][j] = VOID;
	 			mlx_put_image_to_window(game->mlx, game->win, game->ronflex_orientation, game->x_position * SIZE_BLOCK, game->y_position * SIZE_BLOCK);
			}
			printf("%d", game->map[i][j]);
			if (game->map[i][j] == BOX)
				mlx_put_image_to_window(game->mlx, game->win, game->box, j * SIZE_BLOCK, i * SIZE_BLOCK);
			if (game->map[i][j] == WALL)
				mlx_put_image_to_window(game->mlx, game->win, game->wall, j * SIZE_BLOCK, i * SIZE_BLOCK);
			if (game->map[i][j] == SUPERBALL)
			{
				mlx_put_image_to_window(game->mlx, game->win, game->superball, j * SIZE_BLOCK, i * SIZE_BLOCK);
				game->objectif += 1;
			}
			if (game->map[i][j] == BOX_OK)
				mlx_put_image_to_window(game->mlx, game->win, game->box_ok, j * SIZE_BLOCK, i * SIZE_BLOCK);
			
			j++;
		}
		printf("\n");
		i++;
	}
}

void	start_game(t_game *game)
{
	game->box_ok = mlx_xpm_file_to_image(game->mlx, "./sprites/box_ok.xpm", &game->width, &game->heigth);
	game->box = mlx_xpm_file_to_image(game->mlx, "./sprites/box.xpm", &game->width, &game->heigth);
	game->superball = mlx_xpm_file_to_image(game->mlx, "./sprites/superball.xpm", &game->width, &game->heigth);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &game->width, &game->heigth);
	game->ronflex_down = mlx_xpm_file_to_image(game->mlx, "./sprites/charac/ronflex_down.xpm", &game->width, &game->heigth);
	game->ronflex_left = mlx_xpm_file_to_image(game->mlx, "./sprites/charac/ronflex_left.xpm", &game->width, &game->heigth);
	game->ronflex_right = mlx_xpm_file_to_image(game->mlx, "./sprites/charac/ronflex_right.xpm", &game->width, &game->heigth);
	game->ronflex_up = mlx_xpm_file_to_image(game->mlx, "./sprites/charac/ronflex_up.xpm", &game->width, &game->heigth);
	game->ronflex_orientation = game->ronflex_down;

	if (!load_map(game, "./levels/level0.lvl"))
		exit(EXIT_FAILURE);
	display_game(game);
	
	printf("(game) game.mlx = %p\n", game->mlx);
	mlx_hook(game->win, 2, 1L<<0, change_position, game);
	printf("player position  x: %d\n", game->x_position);
	printf("player position  y: %d\n", game->y_position);

}