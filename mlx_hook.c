/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:29:45 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/14 00:04:04 by theophilebr      ###   ########.fr       */
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
	printf("keycode : %d\n", keycode);
	if (keycode == 18)
	{
		mlx_destroy_image(game->mlx, game->menu);
		start_game(game);
	}
		
	if (keycode == 19)
		printf("on va editer\n");
	if (keycode == 53)
		mlx_destroy_window(game->mlx, game->win);
	return (0);
}

int	change_position(int keycode, t_game *game)
{
	printf("(change_position) win->mlx: %p\n", game->mlx);
	if (keycode == 53)
		mlx_destroy_window(game->mlx, game->win);
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
	return (0);
}

int	next_level(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	int x;
	int y;

	y = 0;
	while (y < NBR_BLOCK_HEIGTH * SIZE_BLOCK)
	{
		x = 0;
		while (x < NBR_BLOCK_WIDTH * SIZE_BLOCK)
		{
			mlx_pixel_put(game->mlx, game->win, y, x, 0x00000000);
			x++;
		}
		y++;	
	}
	printf("NEXT LEVEL ?\n");
	mlx_string_put(game->mlx, game->win, 100, 100, 0x00FFFFFF, "BRAVO");
	mlx_string_put(game->mlx, game->win, 100, 100, 0x00FFFFFF, "VOUS AVEZ TERMINE CE NIVEAU");

	return (0);
}