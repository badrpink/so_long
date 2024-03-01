/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:38:59 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 12:53:01 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libc.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct t_node
{
	void			*content;
	struct t_node	*next;
}	t_node;

typedef struct t_cord
{
	int	x;
	int	y;
}	t_cord;

typedef struct t_info
{
	t_node	*map;
	int		height;
	int		width;
	void	*mlx;
	void	*mlx_win;
	t_cord	*position;
}	t_info;

typedef struct t_icons
{
	void	*wall;
	void	*background;
	void	*exit;
	void	*collect;
	void	*dir;
}	t_icons;

int		check_map(t_node *map);
int		check_wall(char *line, int n);
int		count_ch(char c, char *str);
int		check_accur(char *chars, char *line);
int		check_chars(t_node *map);
int		check_char(t_node *map, char c);
int		check_file_name(char *str);
void	add_to_node(t_node **nod, char *content);
char	check_position(t_node *map, int x, int y);
void	get_height_width(t_info *all, t_node *map);
t_cord	*get_position(t_node *map, char c);
t_node	*get_map(char *file);
t_node	*dub_node(t_node *src);
void	put_char_map(t_node *map, int x, int y, char c);
int		check_path(t_node *map, t_cord *position);
void	flood_fill(t_node *map, int x, int y);
void	draw_it(t_info all);
void	clear_it(t_node *garbage);
int		asg_ima(t_node *map, void *mlx, t_icons *img, int n);
void	put_imgs(t_icons *img, t_node *map, void *mlx, void *mlx_win);
int		put_pixels(t_node *map, void *mlx, void *mlx_win, int n);
int		move_it(t_info *all, int x, int y, int n);
#endif