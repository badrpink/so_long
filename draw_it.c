#include "so_long.h"
void get_height_width(info *all, node *map)
{
	int height = 0;
	all->width = ft_strlen(map->content);
	while(map)
	{
		height++;
		map = map->next;
	}
	all->height = height;
}

void draw_it(info all)
{
	all.mlx = mlx_init();
	get_height_width(&all,all.map);
	all.mlx_win=mlx_new_window(all.mlx,all.width*64,all.height*64,"SO_LONG");
	mlx_loop(all.mlx);
}