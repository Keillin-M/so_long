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

/*static void	ft_print_mov(t_game *game)
{
	char	*s_mov;

	s_mov = ft_itoa(game->movement);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, s_mov);
}*/

static void	ft_update_p(t_game *game, int keycode)
{
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
			return (1);
		if (game->map[game->new_y][game->new_x] == 'C')
		{
			game->count--;
			game->map[game->new_y][game->new_x] = '0';
			if (game->count == 0)
				ft_image(game, game->exit_open, game->x_exit, game->y_exit);
		}
		if (game->map[game->new_y][game->new_x] == '0' ||
			game->map[game->new_y][game->new_x] == 'P')
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

static void	ft_direction(t_game *game, int keycode)
{
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
}

int	ft_key_event(int keycode, t_game *game)
{
	game->new_x = game->x;
	game->new_y = game->y;
	if (keycode == 65307)
		ft_close(game);
	ft_direction(game, keycode);
	if (game->x != game->new_x || game->y != game->new_y)
		game->mov = 1;
	else
		game->mov = 0;
	if (ft_move(game, keycode))
	{
		ft_printf("Congrats! YOU WIN!\n");
		ft_close(game);
	}
	return (0);
}
