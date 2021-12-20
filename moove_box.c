/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:05:20 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/15 19:16:11 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"
# include "editor.h"
# include "files_management.h"
# include "game.h"
# include "mlx/mlx.h"
#include "mlx_hook.h"
#include "next_level.h"

int	box_stuck(t_game *game, int x_change, int y_change)
{
	(void)y_change;
	
	if (x_change)
	{
		
		if (((game->map[game->y_position - x_change][game->x_position + x_change] >= WALL && game->map[game->y_position - x_change][game->x_position + x_change] <= BOX_OK)
         || (game->map[game->y_position + x_change][game->x_position + x_change] >= WALL && game->map[game->y_position + x_change][game->x_position + x_change] <= BOX_OK))
         || (game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == BOX || game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == BOX_OK))
		{
			if (x_change > 0)
			{
                if ((game->map[game->y_position + 1][game->x_position + 1] != VOID && game->map[game->y_position + 1][game->x_position + 1] != SUPERBALL)
                 && (game->map[game->y_position - 1][game->x_position + 1] != VOID && game->map[game->y_position - 1][game->x_position + 1] != SUPERBALL))
                 {
                    game->map[game->y_position][game->x_position] = BOX;
                    return (1);
                 }  
				if (game->map[game->y_position + 1][game->x_position + 1] == VOID)
				{
                    game->map[game->y_position + 1][game->x_position + 1] = BOX;
                    return (1);
                }	
                if (game->map[game->y_position + 1][game->x_position + 1] == SUPERBALL)
				{
                    game->map[game->y_position + 1][game->x_position + 1] = BOX_OK;
					game->objectif += -1;
					printf("OBJECTIF RESTANTS: %d\n", game->objectif);
					if (game->objectif == 0)
					{
						game->ronflex_orientation = game->ronflex_down;
						win_game(0, game);
					}
                    return (1);
                }	
				if (game->map[game->y_position - 1][game->x_position + 1] == VOID)
                {
                    game->map[game->y_position - 1][game->x_position + 1] = BOX;
                    return (1);
                }
                if (game->map[game->y_position - 1][game->x_position + 1] == SUPERBALL)
                {
                    game->map[game->y_position - 1][game->x_position + 1] = BOX_OK;
					game->objectif += -1;
					printf("OBJECTIF RESTANTS: %d\n", game->objectif);
					if (game->objectif == 0)
					{
						game->ronflex_orientation = game->ronflex_down;
						win_game(0, game);
					}
                    return (1);
                }
					
                return (1);
			}
			if (x_change < 0)
			{
                printf("VALEUR DE X_CHANGE : %d\n", x_change);
                if ((game->map[game->y_position + 1][game->x_position - 1] != VOID && game->map[game->y_position + 1][game->x_position - 1] != SUPERBALL)
                 && (game->map[game->y_position - 1][game->x_position - 1] != VOID && game->map[game->y_position - 1][game->x_position - 1] != SUPERBALL))
                {
                    game->map[game->y_position][game->x_position] = BOX;
                    return (1);
                }    
				if (game->map[game->y_position + 1][game->x_position - 1] == VOID)
                {
                    game->map[game->y_position + 1][game->x_position - 1] = BOX;
                    return (1);
                }	
                if (game->map[game->y_position + 1][game->x_position - 1] == SUPERBALL)
				{
                    game->map[game->y_position + 1][game->x_position - 1] = BOX_OK;
					game->objectif += -1;
					printf("OBJECTIF RESTANTS: %d\n", game->objectif);
					if (game->objectif == 0)
					{
						game->ronflex_orientation = game->ronflex_down;
						win_game(0, game);
					}
					return (1);
                }	
				if (game->map[game->y_position - 1][game->x_position - 1] == VOID)
				{
					game->map[game->y_position - 1][game->x_position - 1] = BOX;
					return (1);
				}
                if (game->map[game->y_position - 1][game->x_position - 1] == SUPERBALL)
				{
					game->map[game->y_position - 1][game->x_position - 1] = BOX_OK;	
					game->objectif += -1;
					printf("OBJECTIF RESTANTS: %d\n", game->objectif);
					if (game->objectif == 0)
					{
						game->ronflex_orientation = game->ronflex_down;
						win_game(0, game);
					}
					return (1);
				}
			}
		}
			
	}
	if (y_change)
	{
		if (((game->map[game->y_position + y_change][game->x_position + y_change] >= WALL && game->map[game->y_position + y_change][game->x_position + y_change] <= BOX_OK)
         || (game->map[game->y_position + y_change][game->x_position - y_change] >= WALL && game->map[game->y_position + y_change][game->x_position - y_change] <= BOX_OK))
		 || (game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == BOX || game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == BOX_OK))
		{
			if (y_change > 0)
			{
                if ((game->map[game->y_position + 1][game->x_position - 1] != VOID && game->map[game->y_position + 1][game->x_position - 1] != SUPERBALL)
                 && (game->map[game->y_position + 1][game->x_position + 1] != VOID && game->map[game->y_position + 1][game->x_position + 1] != SUPERBALL))
                {
					game->map[game->y_position][game->x_position] = BOX;
					return (1);
				}    
				if (game->map[game->y_position + 1][game->x_position - 1] == VOID)
				{
					game->map[game->y_position + 1][game->x_position - 1] = BOX;
					return (1);
				}  	
                if (game->map[game->y_position + 1][game->x_position - 1] == SUPERBALL)
                {
					game->map[game->y_position + 1][game->x_position - 1] = BOX_OK;
					game->objectif += -1;
					printf("OBJECTIF : %d\n", game->objectif);
					if (game->objectif == 0)
					{
						game->ronflex_orientation = game->ronflex_down;
						win_game(0, game);
					}
					return (1);
				}    
				if (game->map[game->y_position + 1][game->x_position + 1] == VOID)
				{
					game->map[game->y_position + 1][game->x_position +1] = BOX;
					return (1);
				}  	
                if (game->map[game->y_position + 1][game->x_position + 1] == SUPERBALL)
				{
					game->map[game->y_position + 1][game->x_position +1] = BOX_OK;
					game->objectif += -1;
					printf("OBJECTIF RESTANTS : %d\n", game->objectif);
					if (game->objectif == 0)
					{
						game->ronflex_orientation = game->ronflex_down;
						win_game(0, game);
					}
					return (1);
				}  	
                
			}
			if (y_change < 0)
			{
                if ((game->map[game->y_position - 1][game->x_position - 1] != VOID && game->map[game->y_position - 1][game->x_position - 1] != SUPERBALL)
                 && (game->map[game->y_position - 1][game->x_position + 1] != VOID && game->map[game->y_position - 1][game->x_position + 1] != SUPERBALL))
                {
					game->map[game->y_position][game->x_position] = BOX;
					return (1);
				}    
				if (game->map[game->y_position - 1][game->x_position - 1] == VOID)
				{
					game->map[game->y_position - 1][game->x_position - 1] = BOX;
					return (1);
				}	
                if (game->map[game->y_position - 1][game->x_position - 1] == SUPERBALL)
				{
					game->map[game->y_position - 1][game->x_position - 1] = BOX_OK;
					game->objectif += -1;
					printf("OBJECTIF RESTANTS : %d\n", game->objectif);
					if (game->objectif == 0)
					{
						game->ronflex_orientation = game->ronflex_down;
						win_game(0, game);
					}
					return (1);
				}	
				if (game->map[game->y_position - 1][game->x_position + 1] == VOID)
				{
					game->map[game->y_position - 1][game->x_position +1] = BOX;
					return (1);
				}	
                if (game->map[game->y_position - 1][game->x_position + 1] == SUPERBALL)
				{
					game->map[game->y_position - 1][game->x_position +1] = BOX_OK;
					game->objectif += -1;
					printf("OBJECTIF RESTANTS : %d\n", game->objectif);
					if (game->objectif == 0)
					{
						game->ronflex_orientation = game->ronflex_down;
						win_game(0, game);
					}
					return (1);
				}	
			}
		}
			
	}
	return (0);
}

int	box_moove(t_game *game, int x_change, int y_change)
{
	int	valid;

	valid = 1;
		if (game->map[game->y_position + y_change][game->x_position + x_change] == BOX)
		{
			if (game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == WALL 
			|| game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == BOX 
			||  game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == BOX_OK)
			{
				if (box_stuck(game, x_change, y_change))
					return (valid);
				valid = 0;
				return (valid);
			}
			if (game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == SUPERBALL)
			{
				game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] = BOX_OK;
				game->objectif += -1;
				printf("NOMBRE D'OBJECTIF\n : %d\n", game->objectif);
				if (game->objectif == 0)
				{
					game->ronflex_orientation = game->ronflex_down;
					win_game(0, game);
					return (0);
				}
					
				return (valid);
			}
			game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] = BOX;
		}
	return (valid);
}