/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 06:49:38 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/01 10:36:56 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_name(char *str)
{
	int	size;

	size = count_len(str);
	if (size < 5)
		return (0);
	if (str[size - 4] == '.' && str[size - 3] == 'b'
		&& str[size - 2] == 'e' && str[size - 1] == 'r')
		return (1);
	return (0);
}

char	check_position(node *map, int x, int y)
{
	int	count_y;

	count_y = 0;
	while (map && ++count_y < y)
		map = map ->next;
	return (((char *)map->content)[x]);
}

cord	*get_position(node *map, char c)
{
	int		count_y;
	char	*str;
	int		count_x;
	cord	*player;

	count_y = 0;
	player = malloc(sizeof(cord));
	if(!player)
		return(NULL);
	while (map)
	{
		str = (char *)map->content;
		count_y++;
		count_x = 0;
		while (str[count_x])
		{
			if (str[count_x++] == c)
			{
				player->x = count_x -1;
				player->y = count_y;
			}
		}
		map = map -> next;
	}
	return (player);
}

node	*get_map(char *file)
{
	int		fd;
	node	*map;
	char	*temp;
	int		n;

	n = 1;
	map = NULL;
	fd = open(file, O_RDONLY);
	while (n)
	{
		temp = get_next_line(fd);
		if (!temp)
			n = 0;
		add_to_node(&map, temp);
	}
	return (map);
}

void	f()
{
	system("leaks so_long");	
}

int	main(int ac, char **av)
{
	info	all;

	atexit(f);
	if (ac != 2)
		return (ft_printf("ERROR\ninvalid argements\n"), 0);
	if (-1 == open(av[1], O_RDONLY))
		return (ft_printf("ERROR\ncant open file\n"), 0);
	if (!check_file_name(av[1]))
		return (ft_printf("ERROR\ninvalid file extension\n"));
	all.map = get_map(av[1]);
	if (!check_map(all.map))
		return (clear_it(all.map), ft_printf("ERROR\ninvalid_map\n"), 0);
	all.position = get_position(all.map, 'P');
	if(!all.position)
		return(free(all.position),ft_printf("ERROR\n"),0);
	if (!check_path(all.map, all.position))
		return (free(all.position),clear_it(all.map), ft_printf("ERROR\ninvalid_path\n"), 0);
	draw_it(all);
	clear_it(all.map);
}
