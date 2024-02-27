#include "so_long.h"

int check_wall(char *line,int n)
{
	int i = 0;
	while(line[i] && i < n)
		if(line[i++] != '1')
			return(0);
	return(1);
}
int check_ch(char c, char *str)
{
	while(*str)
		if(*(str++) == c)
			return(1);
	return(0);
}
int check_accur(char *chars,char *line)
{
	while(*line)
		if(!check_ch(*(line++),chars))
			return(0);
	return(1);
}
int check_chars(node *map)
{
	int P = 0;
	int C = 0;
	int E = 0;
	while(map)
	{
		P+=check_ch('P',map->content);
		C+=check_ch('C',map->content);
		E+=check_ch('E',map->content);
		map = map->next;
	}
	if(C >= 1 && P == 1 && E == 1)
		return(1);
	return(0);
}
int check_map(node *map)
{
	size_t size = ft_strlen(map->content);
	if(!check_chars(map))
		return(0);
	if(!check_wall(map->content,size-1))
		return(printf("invalid walls\n"),0);
	while(map->next)
	{
		if(!check_accur(map->content,"01PCE\n"))
			return(printf("invalid chars\n"),0);
		if(size != ft_strlen(map->content))
			return(printf("invalid size\n"),0);
		if(*(char *)map->content != '1' || *((char *)map->content+size - 2)!= '1')
			return(printf("invalid walls\n"),0);
		map = map ->next;
	}
	if(!check_wall(map->content,size-1))
		return(printf("invalid walls\n"),0);
	if(size != ft_strlen(map->content) +1)
		return(printf("invalid last line\n"),0);
	return(1);
}