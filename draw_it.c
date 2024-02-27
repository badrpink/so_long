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
int check_char(node *map,char c)
{
	while(map)
	{
		if(count_ch(c,map->content))
			return(1);
		map = map ->next;
	}
	return(0);
}
void put_pixels(node *map,void *mlx,void *mlx_win,int n)
{
	int pixel = 64;
	void *wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &pixel, &pixel);
	void *background = mlx_xpm_file_to_image(mlx, "./textures/background.xpm", &pixel, &pixel);
	void *exit = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm", &pixel, &pixel);
	void *collect = mlx_xpm_file_to_image(mlx, "./textures/collect.xpm", &pixel, &pixel);
	void *dir;
	int i = 0;
	int x = 0;
	int y = 0;
	if(n == 1)
		dir = mlx_xpm_file_to_image(mlx, "./textures/up.xpm", &pixel, &pixel);
	if(n == 2)
		dir = mlx_xpm_file_to_image(mlx, "./textures/down.xpm", &pixel, &pixel);
	if(n == 3)
		dir = mlx_xpm_file_to_image(mlx, "./textures/left.xpm", &pixel, &pixel);
	if(n == 4)
		dir = mlx_xpm_file_to_image(mlx, "./textures/right.xpm", &pixel, &pixel);
	while (map)
	{
		i = 0;
		x = 0;
		while(((char *)map->content)[i])
		{
			mlx_put_image_to_window(mlx,mlx_win,background, x, y);
			if((((char *)map ->content)[i]) == '1')
				mlx_put_image_to_window(mlx,mlx_win,wall, x, y);
			if((((char *)map ->content)[i]) == 'P')
				mlx_put_image_to_window(mlx,mlx_win,dir, x, y);
			if((((char *)map ->content)[i]) == 'E')
				mlx_put_image_to_window(mlx,mlx_win,exit, x, y);
			if((((char *)map ->content)[i]) == 'C')
				mlx_put_image_to_window(mlx,mlx_win,collect, x, y);
			i++;
			x+=64;
		}
		y+=64;
		map = map ->next;
	}
}
int move_it(int key,info *alls)
{
	printf("%d\n",key);
	char c;
	if((key == 13 || key == 126 )) // up
		{

			printf("%d %d\n",alls->position.x,alls->position.y);
			c = check_position(alls->map,alls->position.x,alls->position.y);
			if(c == '0' || c == 'C')
			{
				put_char_map(alls->map, alls->position.x,alls->position.y,'0');
				put_char_map(alls->map,alls->position.x,alls->position.y-1,'P');
				alls->position.y-=1;
				print_node(alls->map);
				put_pixels(alls->map,alls->mlx,alls->mlx_win,1);
			}
			else if(c == 'E' && !check_char(alls->map,'C'))
				exit(0);
		}
	return(0);
}
void draw_it(info all)
{
	all.mlx = mlx_init();
	get_height_width(&all,all.map);
	all.mlx_win=mlx_new_window(all.mlx,all.width*64-64,all.height*64,"SO_LONG");
	put_pixels(all.map,all.mlx,all.mlx_win,1);
	mlx_hook(all.mlx_win, 2, 0,move_it, &all);
	mlx_loop(all.mlx);
}