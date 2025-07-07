/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:47:11 by kmaeda            #+#    #+#             */
/*   Updated: 2025/07/04 11:00:51 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_anim(t_game *game, int *base)
{
	if (game->dir == 'd')
		*base = 3;
	else if (game->dir == 'a')
		*base = 6;
	else if (game->dir == 'w')
		*base = 9;
	else
		*base = 0;
}

static int	animate(t_game *game, double delta_time)
{
	int			base;
	static int	sum;
	static int	frame;
	static char	old_dir;

	if (!game->win || !game->player[0] || !game->player[1])
		return (0);
	sum += delta_time;
	set_anim(game, &base);
	if (old_dir != game->dir)
	{
		frame = 0;
		sum = 0;
		old_dir = game->dir;
	}
	if (sum >= 150)
	{
		sum = 0;
		if (game->mov)
			frame = (frame + 1) % 2;
		else
			frame = 0;
	}
	game->i = base + 1 + frame;
	return (0);
}

static double	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000.0) + (time.tv_usec / 1000.0));
}

int	render(t_game *game)
{
	int				i;
	double			delta_time;
	double			current_time;
	static double	last_time;

	current_time = get_time();
	if (last_time == 0)
		last_time = current_time;
	delta_time = current_time - last_time;
	last_time = current_time;
	if (delta_time > 50)
		delta_time = 50;
	ft_image(game, game->floor, game->x, game->y);
	animate(game, delta_time);
	ft_image(game, game->player[game->i], game->x, game->y);
	i = 0;
	while (i < game->e_count)
	{
		enemy(&game->enemies[i], game, delta_time);
		i++;
	}
	usleep(16000);
	ft_print_mov(game);
	return (0);
}
