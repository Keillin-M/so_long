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

static int	map_ext(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len < 9)
	{
		ft_printf("File extension invalid\n");
		return (1);
	}
	if (argv[len - 5] == '/')
	{
		ft_printf("File extension invalid\n");
		return (1);
	}
	if (ft_strncmp(argv + len - 4, ".ber", 4) == 0)
		return (0);
	ft_printf("File extension invalid\n");	
	return (1);
}

int	ft_close(t_game *game)
{
	ft_clean_map(game);
//	ft_destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	return (exit(0), 0);
}

static void	ft_init(t_game *game, t_bonus *bonus)
{
	game->count = 0;
	game->p = 0;
	game->e = 0;
	game->movement = 0;
	game->error = 0;
	game->total_row = 0;
	game->i = 0;
	game->mov = 1;
	game->dir = 's';
	bonus->i = 0;
	bonus->dir = 1;
	bonus->stop = 1;
	bonus->frame = 0;
	bonus->sum = 0;
	bonus->count = 0;
/*	while (game->i < 12)
	{
		game->player[game->i] = NULL;
		game->i++;
	}
	game->wall = NULL;
	game->floor = NULL;
	game->exit = NULL;
	game->exit_open = NULL;
	game->i = 0;*/
}

static int	ft_open(t_game *game, char **argv)
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
	t_bonus	bonus;

	if (argc != 2)
		return (1);
	if (map_ext(argv[1]))
		return (1);
	ft_init(&game, &bonus);
	if (ft_open(&game, argv))
		game.error = 1;
	if (valid_map(&game, 0, 0))
		game.error = 1;
	if (load_map(&game, &bonus, argv))
		game.error = 1;
	if (game.error)
		ft_close(&game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
//	mlx_loop_hook(game.mlx, animate, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_event, &game);
	mlx_loop(game.mlx);
	return (0);
}
