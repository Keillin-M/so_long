/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:48:19 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/07 16:42:46 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bonus_check(t_game *game, int j, int i)
{
	t_bonus	*bonus;

	if (game->e_count >= MAX_ENEMIES)
	{
		ft_printf("Too many enemies!\n");
		ft_close(game);
	}
	bonus = &game->enemies[game->e_count];
	bonus->x = i;
	bonus->y = j;
	bonus->i = 0;
	bonus->dir = 1;
	bonus->frame = 0;
	bonus->stop = 0;
	bonus->sum = 0;
	game->e_count++;
}

static void	enemy_frame(t_bonus *bonus, t_game *game)
{
	if (bonus->stop)
	{
		if (bonus->dir == 1)
			bonus->i = 0;
		else
			bonus->i = 3;
	}
	else if (bonus->dir == 1)
		bonus->i = 1 + bonus->frame;
	else
		bonus->i = 4 + bonus->frame;
	ft_image(game, game->enemy[bonus->i], bonus->x, bonus->y);
}

static void	enemy_check_mov(t_bonus *bonus, t_game *game)
{
	int		next_x;

	next_x = bonus->x + bonus->dir;
	if (game->map[bonus->y][next_x] == 'P')
	{
		ft_printf("Oh, no! YOU LOSE!\n");
		ft_close(game);
	}
	if (next_x < 0 || game->map[bonus->y][next_x] != '0')
	{
		bonus->stop = 1;
		bonus->dir *= -1;
		bonus->frame = 0;
	}
	else
	{
		bonus->stop = 0;
		game->map[bonus->y][bonus->x] = '0';
		bonus->x = next_x;
		game->map[bonus->y][bonus->x] = 'R';
		bonus->frame = (bonus->frame + 1) % 2;
	}
}

void	enemy(t_bonus *bonus, t_game *game, double delta_time)
{
	bonus->sum += delta_time;
	if (bonus->sum < 300)
		return ;
	bonus->sum = 0;
	ft_image(game, game->floor, bonus->x, bonus->y);
	enemy_check_mov(bonus, game);
	enemy_frame(bonus, game);
}
