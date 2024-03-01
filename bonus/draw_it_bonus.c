/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_it_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:32:13 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 15:16:38 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	turn_it(int key, t_cord *pos, t_cord *move, int *n)
{
	move->x = pos->x;
	move->y = pos->y;
	if (key == 13 || key == 126)
	{
		move->y -= 1;
		*n = 1;
	}
	if (key == 2 || key == 124)
	{
		move->x += 1;
		*n = 4;
	}
	if (key == 0 || key == 123)
	{
		move->x -= 1;
		*n = 3;
	}
	if (key == 1 || key == 125)
	{
		move->y += 1;
		*n = 2;
	}
}

int	det_keys(int key, t_info *all)
{
	static int	moves;
	char		c;
	t_cord		move;
	int			n;

	if (key >= 0)
	{
		turn_it(key, all->position, &move, &n);
		c = check_position(all->map, move.x, move.y);
		if (c == '0' || c == 'C')
			if (move_it(all, move.x, move.y, n))
				ft_printf("moves : %d\n", ++moves);
		if (c == 'E' && !check_char(all->map, 'C'))
			return (ft_printf("GAME OVER\n"), exit(0), 0);
	}
	if (key == 53)
		return (ft_printf("GAME CLOSED\n"), exit(0), 0);
	return (0);
}

void	draw_it(t_info all)
{
	ft_printf("GAME STARTED\n");
	all.mlx = mlx_init();
	get_height_width(&all, all.map);
	all.mlx_win = mlx_new_window(all.mlx,
			all.width * 64 - 64, all.height * 64, "SO_LONG");
	put_pixels(all.map, all.mlx, all.mlx_win, 1);
	mlx_hook(all.mlx_win, 2, 0, det_keys, &all);
	mlx_loop(all.mlx);
	exit(0);
}
