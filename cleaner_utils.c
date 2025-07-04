/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:18:01 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/01 12:01:13 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clean_map_cpy(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map_cpy)
		return ;
	while (i < game->total_row)
	{
		free(game->map_cpy[i]);
		game->map_cpy[i] = NULL;
		i++;
	}
	free(game->map_cpy);
	game->map_cpy = NULL;
}

void	ft_clean_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->total_row <= 0)
		return ;
	if (!game->map)
		return ;
	while (i < game->total_row)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	game->map = NULL;
	ft_clean_map_cpy(game);
	return ;
}
