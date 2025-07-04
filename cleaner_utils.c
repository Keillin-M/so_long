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

/*static void	ft_destroy_p(t_game *game)
{
	if (game->player[0])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[1])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[2])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[3])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[4])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[5])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[6])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[7])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[8])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[9])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[10])
		mlx_destroy_image(game->mlx, game->player);
	if (game->player[11])
		mlx_destroy_image(game->mlx, game->player);
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
	ft_destroy_p(game);
}*/

int	animate(t_game *game)
{
	int		base;
	static int	frame_count;
	static int	frame;
	static char	old_dir;

	if (!game->win || !game->player[0] || !game->player[1])
		return(0);
	frame_count++;
	if (frame_count <= 20000)
		return (0);
	frame_count = 0;
	if (game->dir == 'd')
		base = 3;
	else if (game->dir == 'a')
		base = 6;
	else if (game->dir == 'w')
		base = 9;
	else
		base = 0;
	if (old_dir != game->dir)
	{
		frame = 0;
		old_dir = game->dir;
	}
	if (game->mov)
		frame = (frame + 1) % 2;
	else
		frame = 0;
	game->i = base + 1 + frame;
	ft_image(game, game->floor, game->x, game->y);
	ft_image(game, game->player[game->i], game->x, game->y);
	return (0);
}
