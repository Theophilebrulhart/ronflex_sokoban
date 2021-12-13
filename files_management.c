/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:47:05 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/14 00:14:37 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"
# include "editor.h"
# include "files_management.h"
# include "game.h"
# include "mlx/mlx.h"

int	load_map(t_game *game, char *level)
{
	FILE	*files = NULL;
	char files_lign[NBR_BLOCK_HEIGTH * NBR_BLOCK_WIDTH + 1] = {0};
	int	i;
	int	j;
	files = fopen(level, "r");
	if (!files)
		return (0);
	fgets(files_lign, NBR_BLOCK_WIDTH * NBR_BLOCK_HEIGTH + 1, files);
	i = 0;
	printf("files_lign : %s\n", files_lign);
	while (i < NBR_BLOCK_HEIGTH)
	{
		j = 0;
		while (j < NBR_BLOCK_WIDTH)
		{
			if (files_lign[i * NBR_BLOCK_WIDTH + j] == '0')
				game->map[i][j] = 0;
			if (files_lign[i * NBR_BLOCK_WIDTH + j] == '1')
				game->map[i][j] = 1;
			if (files_lign[i * NBR_BLOCK_WIDTH + j] == '2')
				game->map[i][j] = 2;
			if (files_lign[i * NBR_BLOCK_WIDTH + j] == '3')
				game->map[i][j] = 3;
			if (files_lign[i * NBR_BLOCK_WIDTH + j] == '4')
				game->map[i][j] = 4;
			if (files_lign[i * NBR_BLOCK_WIDTH + j] == '5')
				game->map[i][j] = 5;
			j++;
		}
		i++;
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
	fclose(files);
	return (1);
}