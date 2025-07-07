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

static void	ft_destroy_p(t_game *game)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if (game->player[i])
			mlx_destroy_image(game->mlx, game->player[i]);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (game->enemy[i])
			mlx_destroy_image(game->mlx, game->enemy[i]);
		i++;
	}
}

void	ft_destroy_img(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->obj)
		mlx_destroy_image(game->mlx, game->obj);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->exit_open)
		mlx_destroy_image(game->mlx, game->exit_open);
	if (game->move)
		mlx_destroy_image(game->mlx, game->move);
	ft_destroy_p(game);
}
