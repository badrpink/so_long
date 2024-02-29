#include "so_long.h"
void get_height_width(info *all, node *map)
{
	int height = 0;
		all->width = count_len(map->content);
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
void destroy_img(void *mlx,node *del)
{
	node *clear;
	while(del)
	{
		mlx_destroy_image(mlx,del->content);
		clear = del;
		del = del->next;
		free(clear);
	}
}
int asg_ima(node *del,node *map,void *mlx,icons *img,int n)
{
	int pixel;

	pixel = 64;
	img -> wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &pixel, &pixel);
	img -> background = mlx_xpm_file_to_image(mlx, "./textures/background.xpm", &pixel, &pixel);
	img -> collect = mlx_xpm_file_to_image(mlx, "./textures/collect.xpm", &pixel, &pixel);
	if(!check_char(map,'C'))
		img -> exit = mlx_xpm_file_to_image(mlx, "./textures/exit-open.xpm", &pixel, &pixel);
	else
		img -> exit = mlx_xpm_file_to_image(mlx, "./textures/exit-close.xpm", &pixel, &pixel);
	if(n == 1)
		img -> dir = mlx_xpm_file_to_image(mlx, "./textures/up.xpm", &pixel, &pixel);
	if(n == 2)
		img -> dir = mlx_xpm_file_to_image(mlx, "./textures/down.xpm", &pixel, &pixel);
	if(n == 3)
		img -> dir = mlx_xpm_file_to_image(mlx, "./textures/left.xpm", &pixel, &pixel);
	if(n == 4)
		img -> dir = mlx_xpm_file_to_image(mlx, "./textures/right.xpm", &pixel, &pixel);
	add_to_node(&del,img -> wall);
	add_to_node(&del,img -> background);
	add_to_node(&del,img -> exit);
	add_to_node(&del,img -> collect);
	add_to_node(&del,img -> dir);
	return(1);
}

void put_imgs(icons *img,node *map,void *mlx,void *mlx_win, int pixel)
{
	int i;
	int x;
	int y;

	y = 0;
	while (map)
	{
		i = 0;
		x = 0;
		while(((char *)map->content)[i])
		{
			mlx_put_image_to_window(mlx,mlx_win,img->background, x, y);
			if((((char *)map ->content)[i]) == '1')
				mlx_put_image_to_window(mlx,mlx_win,img->wall, x, y);
			if((((char *)map ->content)[i]) == 'P')
				mlx_put_image_to_window(mlx,mlx_win,img->dir, x, y);
			if((((char *)map ->content)[i]) == 'E')
				mlx_put_image_to_window(mlx,mlx_win,img->exit, x, y);
			if((((char *)map ->content)[i]) == 'C')
				mlx_put_image_to_window(mlx,mlx_win,img->collect, x, y);
			i++;
			x+=pixel;
		}
		y+=pixel;
		map = map ->next;
	}
}
int put_pixels(node *map,void *mlx,void *mlx_win,int n)
{
	int pixel = 64;
	static node *del;
	icons img;

	if(del)
	{
		destroy_img(mlx,del);
		del = NULL;
	}
	asg_ima(del,map,mlx,&img, n);
	if(!img.dir || !img.collect || !img.exit || !img.background || !img.wall)
		return(0);
	put_imgs(&img,map,mlx,mlx_win,pixel);
	return(1);
}

int move_it(info *all,int x, int y,int n)
{
	static int pos;
	if(pos != n)
	{
		if(!put_pixels(all->map,all->mlx,all->mlx_win,n))
			exit(1);
		pos = n;
		return(0);
	}
	else
	{
	put_char_map(all->map,all->position->x,all->position->y,'0');
	put_char_map(all->map,x,y,'P');
	all->position->y=y;
	all->position->x=x;
	put_pixels(all->map,all->mlx,all->mlx_win,n);
	}
	return(1);
}
void turn_it(int key, cord *pos,int *x, int *y, int *n)
{
	*x = pos->x;
	*y = pos->y;
	if((key == 13 || key == 126 ))
	{
		*y-=1;
		*n = 1;
	}
	if((key == 2 || key == 124 ))
	{
		*x += 1;
		*n = 4;
	}
	if((key == 0 || key == 123 ))
	{
		*x -= 1;
		*n = 3;
	}
	if((key == 1 || key == 125))
	{
		*y += 1;
		*n =2;
	}
}
int det_keys(int key,info *all)
{
	char c;
	static int moves;
	int x;
	int y;
	int n;

	if(key >= 0)
	{
		turn_it(key,all->position,&x,&y,&n);
		c = check_position(all->map,x,y);
		if(c == '0' || c == 'C')
			if(move_it(all,x,y,n))
				printf("moves : %d\n",++moves);
		if(c == 'E' && !check_char(all->map,'C'))
			return(printf("GAME OVER\n"),exit(0),0);
	}
	if(key == 53)
		return(printf("GAME CLOSED\n"),exit(0),0);
	return(0);
}

void draw_it(info all)
{
	printf("GAME STARTED\n");
	all.mlx = mlx_init();
	get_height_width(&all,all.map);
	all.mlx_win=mlx_new_window(all.mlx,all.width*64-64,all.height*64,"SO_LONG");
	put_pixels(all.map,all.mlx,all.mlx_win,1);
	mlx_hook(all.mlx_win, 2, 0,det_keys, &all);
	mlx_loop(all.mlx);
	exit(0);
}