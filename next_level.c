/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:57:12 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/15 19:30:37 by theophilebr      ###   ########.fr       */
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

void	win_game(int keycode, t_game *game)
{
	if (game->level < 7)
		game->level += 1;
	printf("LEVEL debut de fonction win_game = %d\n", game->level);
	printf("**********YOU WIN*********\n");
	if (game->editor_check)
	{
		printf("RONFLEX_CHECK %d\n", game->ronflex_check);
		if (!load_map(game, "./levels/level_editor.lvl"))
			exit(EXIT_FAILURE);
		mlx_hook(game->win, 2, 1L<<0, change_position, game);
		display_game(game);
		if (game->level)
			game->level--;
		return;
	}
	if (keycode == 51)
	{
		printf("RESTART LEVEL \n");
		game->level--;
	}
	if (keycode == 123)
	{	
		if (game->level > 0)
			game->level += -2;
	}
	if (game->level == 0)
	{
		if (!load_map(game, "./levels/level0.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
	printf("LEVEL = %d\n", game->level);		
	if (game->level == 1)
	{
		if (!load_map(game, "./levels/level1.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
	if (game->level == 2)
	{
		if (!load_map(game, "./levels/level2.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
	if (game->level == 3)
	{
		if (!load_map(game, "./levels/level3.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
    if (game->level == 4)
	{
		if (!load_map(game, "./levels/level4.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
     if (game->level == 5)
	{
		if (!load_map(game, "./levels/level5.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
	if (game->level == 6)
	{
		if (!load_map(game, "./levels/level6.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
}