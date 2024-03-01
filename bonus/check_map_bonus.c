/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:32:24 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 15:16:25 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_wall(char *line, int n)
{
	int	i;

	i = 0;
	while (line[i] && i < n)
		if (line[i++] != '1')
			return (0);
	return (1);
}

int	count_ch(char c, char *str)
{
	int	count;

	count = 0;
	while (*str)
		if (*(str++) == c)
			count++;
	return (count);
}

int	check_accur(char *chars, char *line)
{
	while (*line)
	{
		if (!count_ch(*(line++), chars))
			return (0);
	}
	return (1);
}

int	check_chars(t_node *map)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	while (map)
	{
		p += count_ch('P', map->content);
		c += count_ch('C', map->content);
		e += count_ch('E', map->content);
		map = map->next;
	}
	if (p >= 1 && c == 1 && e == 1)
		return (1);
	return (0);
}

int	check_map(t_node *map)
{
	static int	count;
	size_t		size;

	if (!map)
		return (0);
	size = count_len(map -> content);
	if (!check_chars(map))
		return (0);
	if (!check_wall(map -> content, size - 1))
		return (0);
	while (map->next)
	{
		if (*(char *)map->content != '1'
			|| *((char *)map->content + size - 2) != '1'
			|| !check_accur("01PCE\n", map->content)
			|| size != count_len(map->content))
			return (0);
		map = map -> next;
		count++;
	}
	if (!check_wall(map->content, size - 1) || count >= 21 || size >= 42)
		return (0);
	if (size != count_len(map->content) + 1)
		return (0);
	return (1);
}
