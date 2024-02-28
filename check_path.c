#include "so_long.h"
char *str_dup(char *str)
{
	char *ret = malloc(ft_strlen(str));
	if(!ret)
		return(NULL);
	return(strcpy(ret,str));
}
node *dub_node(node *src)
{
	node *new = NULL;
	while(src)
	{
		add_to_node(&new,str_dup(src ->content));
		src= src->next;
	}
	return(new);
}
void put_char_map(node *map, int x,int y,char c)
{
	int count_y = 0;
	while(map && ++count_y < y)
		map = map ->next;
	((char *)map->content)[x] = c;
}
void flood_fill(node *map,int x,int y)
{
	if( '1' == check_position(map,x,y) || check_position(map,x,y) == 'X')
		return;
	put_char_map(map,x,y,'X');
	flood_fill(map,x+1,y);
	flood_fill(map,x-1,y);
	flood_fill(map,x,y+1);
	flood_fill(map,x,y-1);
}
int check_path(node *map,cord *position)
{
	node *cpy_map = dub_node(map);
	node *clear = cpy_map;
	flood_fill(cpy_map,position->x,position->y);
	int P = 0;
	int C = 0;
	int E = 0;
	while(cpy_map)
	{
		P+=count_ch('P',cpy_map->content);
		C+=count_ch('C',cpy_map->content);
		E+=count_ch('E',cpy_map->content);
		cpy_map = cpy_map->next;
	}
	if(C == 0 && P == 0 && E == 0)
		return(clear_it(clear),1);
	return(clear_it(clear),0);
}