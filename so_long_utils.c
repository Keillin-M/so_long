/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:38:35 by kmaeda            #+#    #+#             */
/*   Updated: 2025/06/27 12:39:58 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, 
		game->w * x, game->h * y);
}

void	ft_update_p(t_game *game, int keycode)
{
	if (game->map[game->y][game->x] == 'E')
		ft_image(game, game->exit, game->x, game->y);
	else
		ft_image(game, game->floor, game->x, game->y);
	if (keycode == 'w' || keycode == 65362)
	{
		ft_image(game, game->player[9], game->x, game->y);
		game->i = 10;
	}
	else if (keycode == 's' || keycode == 65364)
	{
		ft_image(game, game->player[0], game->x, game->y);
		game->i = 1;
	}
	else if (keycode == 'a' || keycode == 65361)
	{
		ft_image(game, game->player[6], game->x, game->y);
		game->i = 7;
	}
	else if (keycode == 'd' || keycode == 65363)
	{
		ft_image(game, game->player[3], game->x, game->y);
		game->i = 4;
	}
}

int	ft_move(t_game *game, int keycode)
{
	if (game->x == game->new_x && game->y == game->new_y)
		return (0);
	if (game->map[game->new_y][game->new_x] != '1')
	{
		if (game->map[game->new_y][game->new_x] == 'E' && game->count == 0)
			ft_close(game);
		if (game->map[game->new_y][game->new_x] == 'C')
		{
			game->count--;
			game->map[game->new_y][game->new_x] = '0';
			if (game->count == 0)
				ft_image(game, game->exit_open, game->x_exit, game->y_exit);
		}
		if (game->map[game->new_y][game->new_x] == '0' ||
			game->map[game->new_y][game->new_x] == 'E')
		{
			ft_image(game, game->floor, game->x, game->y);
			game->x = game->new_x;
			game->y = game->new_y;
			ft_update_p(game, keycode);
			game->movement++;
			ft_printf("Movement: %d\n", game->movement);
		}
	}
	return (0);
}

int	ft_key_event(int keycode, t_game *game)
{
	game->new_x = game->x;
	game->new_y = game->y;
	if (keycode == 65307)
		ft_close(game);
	if (keycode == 'w' || keycode == 65362)
	{
		game->new_y -= 1;
		game->dir = 'w';
	}
	if (keycode == 's' || keycode == 65364)
	{
		game->new_y += 1;
		game->dir = 's';
	}
	if (keycode == 'a' || keycode == 65361)
	{
		game->new_x -= 1;
		game->dir = 'a';
	}
	if (keycode == 'd' || keycode == 65363)
	{
		game->new_x += 1;
		game->dir = 'd';
	}
	if (game->x != game->new_x || game->y != game->new_y)
	{
		game->mov = 1;
	}
	else
		game->mov = 0;
	ft_move(game, keycode);
	return (0);
}
