/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:32:01 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 10:24:58 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*str_dup(char *str)
{
	char	*ret;

	ret = malloc(count_len(str));
	if (!ret)
		return (NULL);
	copy_it(ret, str);
	return (ret);
}

node	*dub_node(node *src)
{
	node	*new;

	new = NULL;
	while (src)
	{
		add_to_node(&new, str_dup(src ->content));
		src = src->next;
	}
	return (new);
}

void	put_char_map(node *map, int x, int y, char c)
{
	int	count_y;

	count_y = 0;
	while (map && ++count_y < y)
		map = map->next;
	((char *)map->content)[x] = c;
}

void	flood_fill(node *map, int x, int y)
{
	if ('1' == check_position(map, x, y)
		|| check_position(map, x, y) == 'X')
		return ;
	if(check_position(map, x, y) == 'E')
	{
		put_char_map(map, x, y, 'T');
		return;
	}
	put_char_map(map, x, y, 'X');
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
void print_node(node *map)
{
	while(map)
	{
		printf("%s",map->content);
		map = map ->next;
	}
}
int	check_path(node *map, cord *position)
{
	node	*cpy_map;
	node	*clear;
	int		p;
	int		c;
	int		t;

	cpy_map = dub_node(map);
	clear = cpy_map;
	p = 0;
	c = 0;
	t = 0;
	flood_fill(cpy_map, position->x, position->y);
	print_node(cpy_map);
	while (cpy_map)
	{
		p += count_ch('P', cpy_map->content);
		c += count_ch('C', cpy_map->content);
		t += count_ch('T', cpy_map->content);
		cpy_map = cpy_map->next;
	}
	if (c == 0 && p == 0 && t == 1)
		return (clear_it(clear), 0);
	return (clear_it(clear), 0);
}
