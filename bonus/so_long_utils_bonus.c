/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:42:29 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 15:16:50 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_to_node(t_node **nod, char *content)
{
	t_node	*new;
	t_node	*temp;

	if (content)
	{
		new = malloc(sizeof(t_node));
		if (!new)
			return ;
		new -> content = content;
		new -> next = NULL;
		if (!*nod)
			*nod = new;
		else
		{
			temp = *nod;
			while (temp -> next)
				temp = temp -> next;
			temp -> next = new;
		}
	}
}

void	clear_it(t_node *garbage)
{
	t_node	*clear;

	while (garbage)
	{
		clear = garbage;
		garbage = garbage ->next;
		free(clear->content);
		free(clear);
	}
}

void	get_height_width(t_info *all, t_node *map)
{
	int	height;

	height = 0;
	all->width = count_len(map->content);
	while (map)
	{
		height++;
		map = map->next;
	}
	all->height = height;
}

int	check_char(t_node *map, char c)
{
	while (map)
	{
		if (count_ch(c, map->content))
			return (1);
		map = map ->next;
	}
	return (0);
}
