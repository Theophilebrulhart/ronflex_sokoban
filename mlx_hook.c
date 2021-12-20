/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:29:45 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/15 19:16:05 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"
# include "editor.h"
# include "files_management.h"
# include "game.h"
# include "mlx/mlx.h"
#include "mlx_hook.h"
#include "moove_player.h"
#include "next_level.h"

int	choose_mode(int keycode, t_game *game)
{
	game->menu = mlx_xpm_file_to_image(game->win, "./sprites/menu.xpm", &game->width, &game->heigth);
	printf("BACK TO MENU\n");
	mlx_put_image_to_window(game->mlx, game->win, game->menu, 0, 0);
	if (keycode == 18)
	{
		mlx_destroy_image(game->mlx, game->menu);
			start_game(game);
	}
	if (keycode == 19)
	{
		printf("EDITOR_CHECK : %d\n", game->editor_check);
		if (game->editor_check)
			win_game(keycode, game);
		else
			map_editor(game);
	}
		
	return (0);
}

int	change_position(int keycode, t_game *game)
{
	//printf("(change_position) win->mlx: %p\n", game->mlx);
	if (keycode == 53)
		mlx_hook(game->win, 2, 1L<<0, choose_mode, game);
	if (keycode == 0)
	{
		game->ronflex_orientation = game->ronflex_left;
		moove_player(keycode, game);
	}
	if (keycode == 1)
	{
		game->ronflex_orientation = game->ronflex_down;
		moove_player(keycode, game);
	}
	if (keycode == 2)
	{
		
		game->ronflex_orientation = game->ronflex_right;
		moove_player(keycode, game);
	}
	if (keycode == 13)
	{
		game->ronflex_orientation = game->ronflex_up;
		moove_player(keycode, game);
	}
	if (keycode == 51)
		win_game(keycode, game);
	if (keycode == 123 && !game->ronflex_check)
		win_game(keycode, game);
	if (keycode == 124 && !game->ronflex_check)
		win_game(keycode, game);
	if (keycode == 49 && game->editor_check)
	{
		printf("ON REPASSE EN MODE EDITOR\n");
		win_game(keycode, game);
		mlx_put_image_to_window(game->mlx, game->win, game->cursor.img, game->x_position * SIZE_BLOCK, game->y_position * SIZE_BLOCK);
		mlx_hook(game->win, 2, 1L<<0, map_change, game);
	}
	return (0);
}

int	map_change(int keycode, t_game *game)
{
	int j;
	int i;
	
	game->editor_check = 1;		
	printf("cursor.x_position ; %d \n", game->cursor.x_position);
	printf("cursor.y_position ; %d \n", game->cursor.y_position);
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		mlx_hook(game->win, 2, 1L<<0, choose_mode, game);
	if (keycode == 123 && game->cursor.x_position - 1 != 0)
	{
		game->cursor.x_position += -1;
		mlx_put_image_to_window(game->mlx, game->win, game->cursor.img, game->cursor.x_position * SIZE_BLOCK, game->cursor.y_position * SIZE_BLOCK);
	}
	if (keycode == 125 && game->cursor.y_position + 1 != 11)
	{
		game->cursor.y_position += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->cursor.img, game->cursor.x_position * SIZE_BLOCK, game->cursor.y_position * SIZE_BLOCK);
	}
	if (keycode == 124 && game->cursor.x_position + 1 != 11)
	{
		game->cursor.x_position += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->cursor.img, game->cursor.x_position * SIZE_BLOCK, game->cursor.y_position * SIZE_BLOCK);
	}
	if (keycode == 126 && game->cursor.y_position - 1 != 0)
	{
		game->cursor.y_position += -1;
		mlx_put_image_to_window(game->mlx, game->win, game->cursor.img, game->cursor.x_position * SIZE_BLOCK, game->cursor.y_position * SIZE_BLOCK);
	}
	if (keycode == 51)
	{
		game->map[game->cursor.y_position][game->cursor.x_position] = VOID;
	}
	if (keycode == 18)
	{
		game->map[game->cursor.y_position][game->cursor.x_position] = WALL;
	}
	if (keycode == 19)
	{
		game->map[game->cursor.y_position][game->cursor.x_position] = BOX;
	}
	if (keycode == 20)
	{
		game->map[game->cursor.y_position][game->cursor.x_position] = SUPERBALL;
	}
	if (keycode == 21)
	{
		if (game->ronflex_check == 1)
			game->map[game->y_position][game->x_position] = VOID;
		game->map[game->cursor.y_position][game->cursor.x_position] = RONFLEX;
		j = 0;
		while (j < NBR_BLOCK_HEIGTH)
		{
			i = 0;
			printf("ligne : ");
			while (i < NBR_BLOCK_WIDTH)
			{	
				printf("%d", game->map[j][i]);
				i++;
			}
			j++;
			printf("\n");
		}
		game->ronflex_check = 1;
	}
	if (keycode == 36)
	{
		create_map(game);
		win_game(keycode, game);
		game->ronflex_check = 0;
	}
	j = 0;
	while (j < NBR_BLOCK_HEIGTH)
	{
		i = 0;
		printf("ligne : ");
		while (i < NBR_BLOCK_WIDTH)
		{	
			printf("%d", game->map[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}
	display_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->cursor.img, game->cursor.x_position * SIZE_BLOCK, game->cursor.y_position * SIZE_BLOCK);
	
	return (0);
}