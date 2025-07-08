/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:30:46 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/02 12:54:53 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, 
		game->w * x, game->h * y);
}

static void	ft_xpm_player(t_game *game)
{
	game->player[0] = mlx_xpm_file_to_image(game->mlx, "textures/D.xpm", \
			&game->w, &game->h);
	game->player[1] = mlx_xpm_file_to_image(game->mlx, "textures/D1.xpm", \
			&game->w, &game->h);
	game->player[2] = mlx_xpm_file_to_image(game->mlx, "textures/D2.xpm", \
			&game->w, &game->h);
	game->player[3] = mlx_xpm_file_to_image(game->mlx, "textures/R.xpm", \
			&game->w, &game->h);
	game->player[4] = mlx_xpm_file_to_image(game->mlx, "textures/R1.xpm", \
			&game->w, &game->h);
	game->player[5] = mlx_xpm_file_to_image(game->mlx, "textures/R2.xpm", \
			&game->w, &game->h);
	game->player[6] = mlx_xpm_file_to_image(game->mlx, "textures/L.xpm", \
			&game->w, &game->h);
	game->player[7] = mlx_xpm_file_to_image(game->mlx, "textures/L1.xpm", \
			&game->w, &game->h);
	game->player[8] = mlx_xpm_file_to_image(game->mlx, "textures/L2.xpm", \
			&game->w, &game->h);
	game->player[9] = mlx_xpm_file_to_image(game->mlx, "textures/U.xpm", \
			&game->w, &game->h);
	game->player[10] = mlx_xpm_file_to_image(game->mlx, "textures/U1.xpm", \
			&game->w, &game->h);
	game->player[11] = mlx_xpm_file_to_image(game->mlx, "textures/U2.xpm", \
			&game->w, &game->h);
}

static void	ft_xpm_map(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", \
			&game->w, &game->h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", \
			&game->w, &game->h);
	game->obj = mlx_xpm_file_to_image(game->mlx, "textures/heart.xpm", \
			&game->w, &game->h); 
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", \
			&game->w, &game->h);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, \
			"textures/exit_open.xpm", &game->w, &game->h);
	game->move = mlx_xpm_file_to_image(game->mlx, "textures/move.xpm", \
			&game->w, &game->h);
}

static void	ft_xpm_enemy(t_game *game)
{
	game->enemy[0] = mlx_xpm_file_to_image(game->mlx, "textures/ER.xpm", \
			&game->w, &game->h);
	game->enemy[1] = mlx_xpm_file_to_image(game->mlx, "textures/ER1.xpm", \
			&game->w, &game->h);
	game->enemy[2] = mlx_xpm_file_to_image(game->mlx, "textures/ER2.xpm", \
			&game->w, &game->h);
	game->enemy[3] = mlx_xpm_file_to_image(game->mlx, "textures/EL.xpm", \
			&game->w, &game->h);
	game->enemy[4] = mlx_xpm_file_to_image(game->mlx, "textures/EL1.xpm", \
			&game->w, &game->h);
	game->enemy[5] = mlx_xpm_file_to_image(game->mlx, "textures/EL2.xpm", \
			&game->w, &game->h);
}

void	ft_xpm(t_game *game)
{
	ft_xpm_map(game);
	ft_xpm_player(game);
	ft_xpm_enemy(game);
	if (!game->wall || !game->floor || !game->player[0] || !game->player[1]
		|| !game->player[2] || !game->player[3] || !game->player[4] 
		|| !game->player[5] || !game->player[6] || !game->player[7] 
		|| !game->player[8] || !game->player[9] || !game->player[10] 
		|| !game->player[11] || !game->enemy[0] || !game->enemy[1]
		|| !game->enemy[2] || !game->enemy[3] || !game->enemy[4] 
		|| !game->player[5] || !game->obj || !game->exit || !game->exit_open
		|| !game->move)
	{
		perror("Error loading image");
		ft_close(game);
	}
}
