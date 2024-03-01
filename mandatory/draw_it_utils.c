/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_it_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:03:27 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 13:07:56 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	asg_ima(t_node *map, void *mlx, t_icons *img, int n)
{
	int	pxl;

	pxl = 64;
	img->wall = mlx_xpm_file_to_image(mlx, "./txts/wall-1.xpm", &pxl, &pxl);
	img->background = mlx_xpm_file_to_image(mlx,
			"./txts/background.xpm", &pxl, &pxl);
	img->collect = mlx_xpm_file_to_image(mlx, "./txts/collect.xpm", &pxl, &pxl);
	if (!check_char(map, 'C'))
		img -> exit = mlx_xpm_file_to_image(mlx,
				"./txts/exit-open.xpm", &pxl, &pxl);
	else
		img -> exit = mlx_xpm_file_to_image(mlx,
				"./txts/exit-close.xpm", &pxl, &pxl);
	if (n == 1)
		img -> dir = mlx_xpm_file_to_image(mlx, "./txts/up.xpm", &pxl, &pxl);
	if (n == 2)
		img -> dir = mlx_xpm_file_to_image(mlx, "./txts/down.xpm", &pxl, &pxl);
	if (n == 3)
		img -> dir = mlx_xpm_file_to_image(mlx, "./txts/left.xpm", &pxl, &pxl);
	if (n == 4)
		img -> dir = mlx_xpm_file_to_image(mlx, "./txts/right.xpm", &pxl, &pxl);
	return (1);
}

void	put_imgs(t_icons *img, t_node *map, void *mlx, void *mlx_win)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	while (map)
	{
		i = 0;
		x = 0;
		while (((char *)map->content)[i])
		{
			mlx_put_image_to_window(mlx, mlx_win, img->background, x, y);
			if ((((char *)map ->content)[i]) == '1')
				mlx_put_image_to_window(mlx, mlx_win, img->wall, x, y);
			if ((((char *)map ->content)[i]) == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img->dir, x, y);
			if ((((char *)map ->content)[i]) == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img->exit, x, y);
			if ((((char *)map ->content)[i]) == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img->collect, x, y);
			i ++;
			x += 64;
		}
		y += 64;
		map = map->next;
	}
}

int	put_pixels(t_node *map, void *mlx, void *mlx_win, int n)
{
	int		pixel;
	t_icons	img;

	pixel = 64;
	asg_ima(map, mlx, &img, n);
	if (!img.dir || !img.collect || !img.exit || !img.background || !img.wall)
		return (ft_printf("ERROR WITH TEXTURES\n"), exit(1), 0);
	put_imgs(&img, map, mlx, mlx_win);
	return (1);
}

int	move_it(t_info *all, int x, int y, int n)
{
	static int	pos;

	if (pos != n)
	{
		if (!put_pixels(all->map, all->mlx, all->mlx_win, n))
			exit(1);
		pos = n;
		return (0);
	}
	else
	{
		put_char_map(all->map, all->position->x, all->position->y, '0');
		put_char_map(all->map, x, y, 'P');
		all->position->y = y;
		all->position->x = x;
		put_pixels(all->map, all->mlx, all->mlx_win, n);
	}
	return (1);
}
