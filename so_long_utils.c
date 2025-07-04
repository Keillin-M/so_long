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

void	ft_update_p(t_game *game)
{
	if (game->map[game->y][game->x] == 'E')
		ft_image(game, game->exit, game->x, game->y);
	else
		ft_image(game, game->floor, game->x, game->y);
	game->x = game->new_x;
	game->y = game->new_y;
	game->movement++;
	ft_printf("Movement: %d\n", game->movement);
	ft_image(game, game->player, game->x, game->y);
}

int	ft_move(t_game *game)
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
			ft_update_p(game);
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
		game->new_y -= 1;
	if (keycode == 's' || keycode == 65364)
		game->new_y += 1;
	if (keycode == 'a' || keycode == 65361)
		game->new_x -= 1;
	if (keycode == 'd' || keycode == 65363)
		game->new_x += 1;
	ft_move(game);
	return (0);
}

int	map_ext(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len < 4)
	{
		ft_printf("File extension invalid\n");
		return (1);
	}
	if (ft_strncmp(argv + len - 4, ".ber", 4) == 0)
		return (0);
	ft_printf("File extension invalid\n");	
	return (1);
}
