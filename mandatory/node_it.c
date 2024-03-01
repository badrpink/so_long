/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:42:29 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 09:48:59 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_to_node(node **nod, char *content)
{
	node	*new;
	node	*temp;

	if (content)
	{
		new = malloc(sizeof(node));
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

void	clear_it(node *garbage)
{
	node	*clear;

	while (garbage)
	{
		clear = garbage;
		garbage = garbage ->next;
		free(clear->content);
		free(clear);
	}
}

void	get_height_width(info *all, node *map)
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

int	check_char(node *map, char c)
{
	while (map)
	{
		if (count_ch(c, map->content))
			return (1);
		map = map ->next;
	}
	return (0);
}

void	destroy_img(void *mlx, node *del)
{
	node	*clear;

	while (del)
	{
		mlx_destroy_image(mlx, del->content);
		clear = del;
		del = del->next;
		free(clear);
	}
}
