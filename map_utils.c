/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:51:24 by kmaeda            #+#    #+#             */
/*   Updated: 2025/06/30 13:52:25 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	end_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len--;
	}
	return (len);
}

int	map_size(t_game *game, char **argv)
{
	int	len;

	len = 0;
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (perror("Error opening file"), 1);
	game->line = get_next_line(game->fd);
	if (!game->line)
		return (close(game->fd), perror("Empty map"), 1);
	game->line_len = end_line(game->line);
	while (game->line)
	{
		len = end_line(game->line);
		if (len != game->line_len)
			return (free(game->line), close(game->fd), 
				perror("Different size line in map"), 1);
		game->total_row++;
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	close(game->fd);
	return (0);
}

int	read_map(t_game *game, char **argv)
{
	int	row;

	row = 0;
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (perror("Error opening file"), 1);
	game->line = get_next_line(game->fd);
	while (game->line)
	{
		game->map[row] = ft_strdup(game->line);
		game->map_cpy[row] = ft_strdup(game->line);
		if (!game->map[row] || !game->map_cpy[row])
		{
			close(game->fd);
			return (free(game->line), perror("ft_strdup failed"), 1);
		}
		free(game->line);
		row++;
		game->line = get_next_line(game->fd);
	}
	return (close(game->fd), 0);
}

int	load_map(t_game *game, char **argv)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (i < game->total_row)
	{
		if (game->map[i])
			free(game->map[i]);
		if (game->map_cpy[i])
			free(game->map_cpy[i]);
		game->map[i] = NULL;
		game->map_cpy[i] = NULL;
		i++;
	}
	if (read_map (game, argv))
		return (1);
	mlx_clear_window(game->mlx, game->win);
	while (row < game->total_row)
	{
		draw_map(game, row, 0);
		row++;
	}
	return (0);
}

void	draw_map(t_game *game, int row, int x)
{
	while (game->map[row][x] != '\0' && game->map[row][x] != '\n')
	{
		ft_image(game, game->floor, x, row);
		if (game->map[row][x] == '1')
			ft_image(game, game->wall, x, row);
		if (game->map[row][x] == 'C')
			ft_image(game, game->obj, x, row);
		if (game->map[row][x] == 'E')
		{
			ft_image(game, game->exit, x, row); 
			game->y_exit = row;
			game->x_exit = x;
		}
		if (game->map[row][x] == 'P')
			ft_image(game, game->player, x, row); 
		x++;
	}
}
