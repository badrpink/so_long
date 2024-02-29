
#include "so_long.h"

int check_file_name(char *str)
{
	int size = count_len(str);
	if(size < 5)
		return(0);
	if(str[size-4] == '.' && str[size-3] == 'b' && str[size-2] == 'e' && str[size-1] == 'r')
		return(1);
	return(0);
}
void add_to_node(node **nod, char *content)
{
	node *new = malloc(sizeof(node));
	node *temp;
	if(!new)
		return;
	new ->content = content;
	new ->next = NULL;
	if(!*nod)	
		*nod = new;
	else
	{
		temp = *nod;
		while(temp->next)
			temp=temp->next;
		temp->next = new;
	}
}
void print_node(node *map)
{
	while(map)
	{
		printf("%s",map->content);
		map = map->next;
	}
}
char check_position(node *map,int x,int y)
{
	int count_y = 0;
	while(map && ++count_y < y)
		map = map ->next;
	return(((char *)map->content)[x]);
}
cord *get_position(node *map,char c)
{
	int count_y = 0;
	char *str;
	int count_x;
	cord *player;
	player = malloc(sizeof(cord));
	while(map)
	{
		str = (char *)map->content;
		count_y++;
		count_x = 0;
		while(str[count_x])
			if(str[count_x++] == c)
				{
					player->x = count_x -1;
					player->y = count_y;
				}
		map = map -> next;
	}
	return(player);
}
void clear_it(node *garbage)
{
	node *clear;
	while(garbage)
	{
		clear = garbage;
		garbage = garbage ->next;
		free(clear->content);
		free(clear);
	}
}
node *get_map(char *file)
{
	int fd = open(file,O_RDONLY);
	node *map = NULL;
	char *temp;
	while((temp = get_next_line(fd)))
		add_to_node(&map, temp);
	return(map);
}
void foo(void)
{
    system("leaks so_long");
}

int main(int ac, char **av)
{
	info all;
    atexit(foo);
	if(ac != 2)
		return(printf("invalid argements\n"),0);
	if( -1 == open(av[1],O_RDONLY))
		return(printf("cant open file\n"),0);
	if(!check_file_name(av[1]))
		return(printf("invalid file extension\n"));
	all.map = get_map(av[1]);
	if(!check_map(all.map))
		return(clear_it(all.map),printf("invalid_map\n"),0);
	all.position = get_position(all.map,'P');
	if(!check_path(all.map,all.position))
		return(clear_it(all.map),printf("invalid_path\n"),0);
	draw_it(all);
	clear_it(all.map);
}
