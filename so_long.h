/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:58:54 by kmaeda            #+#    #+#             */
/*   Updated: 2025/06/27 11:11:31 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAX_ENEMIES 5

# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_bonus
{
	int	i;
	int	x;
	int	y;
	int	dir;
	int	frame;
	int	sum;
	int	stop;
}	t_bonus;

typedef struct s_game
{
	int		total_row;
	int		line_len;
	int		p;
	int		e;
	int		fd;
	int		w;
	int		h;
	int		x;
	int		y;
	int		new_x;
	int		new_y;
	int		x_exit;
	int		y_exit;
	int		count;
	int		e_count;
	int		movement;
	int		error;
	int		i;
	int		mov;
	char	dir;
	void	*mlx;
	void	*win;
	void	*move;
	void	*floor;
	void	*wall;
	void	*player[12];
	void	*enemy[6];
	void	*obj;
	void	*exit;
	void	*exit_open;
	char	*line;
	char	**map;
	char	**map_cpy;
	t_bonus	enemies[MAX_ENEMIES];
}	t_game;

int		ft_key_event(int keycode, t_game *game);
int		ft_move(t_game *game, int keycode);
int		ft_close(t_game *game);
int		valid_map(t_game *game, int i, int j);
int		map_size(t_game *game, char **argv);
int		read_map(t_game *game, char **argv);
int		load_map(t_game *game, char **argv, int i, int row);
int		ft_printf(const char *format, ...);
int		draw_map(t_game *game, int row, int x);
int		render(t_game *game);
void	ft_print_mov(t_game *game);
void	bonus_check(t_game *game, int i, int j);
void	enemy(t_bonus *bonus, t_game *game, double delta_time);
void	ft_destroy_img(t_game *game);
void	ft_xpm(t_game *game);
void	ft_clean_map(t_game *game);
void	ft_image(t_game *game, void *img, int x, int y);
char	*get_next_line(int fd);

#endif
