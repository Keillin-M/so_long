/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:11:44 by kmaeda            #+#    #+#             */
/*   Updated: 2025/06/27 12:37:50 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", \
			&game->w, &game->h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", \
			&game->w, &game->h);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/fox.xpm", \
			&game->w, &game->h);
	game->obj = mlx_xpm_file_to_image(game->mlx, "textures/heart.xpm", \
			&game->w, &game->h); 
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", \
			&game->w, &game->h);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, \
			"textures/exit_open.xpm", &game->w, &game->h);
	if (!game->wall || !game->floor || !game->player || !game->obj
		|| !game->exit || !game->exit_open)
	{
		perror("Error loading image");
		ft_close(game);
	}
}

int	ft_close(t_game *game)
{
	ft_clean_map(game);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->obj)
		mlx_destroy_image(game->mlx, game->obj);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->exit_open)
		mlx_destroy_image(game->mlx, game->exit_open);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	return (exit(0), 0);
}

void	ft_init(t_game *game)
{
	game->count = 0;
	game->p = 0;
	game->e = 0;
	game->movement = 0;
	game->error = 0;
	game->total_row = 0;
}

int	ft_open(t_game *game, char **argv)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	if (map_size(game, argv))
		return (1);
	game->map = malloc(sizeof(char *) * game->total_row);
	game->map_cpy = malloc(sizeof(char *) * game->total_row);
	if (!game->map || !game->map_cpy)
		return (perror("Malloc failed"), 1);
	if (read_map(game, argv))
		return (1);
	ft_xpm(game);
	game->win = mlx_new_window(game->mlx, game->line_len * game->w, 
			game->total_row * game->h, "So Long");
	if (!game->win)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	if (map_ext(argv[1]))
		return (1);
	ft_init(&game);
	if (ft_open(&game, argv))
		game.error = 1;
	if (valid_map(&game, 0, 0))
		game.error = 1;
	if (load_map(&game, argv))
		game.error = 1;
	if (game.error)
		ft_close(&game);
	mlx_hook(game.win, 17, 0, ft_close, NULL);
	mlx_key_hook(game.win, ft_key_event, &game);
	mlx_loop(game.mlx);
	return (0);
}
