#include "so_long.h"

int check_wall(char *line,int n)
{
	int i = 0;
	while(line[i] && i < n)
		if(line[i++] != '1')
			return(0);
	return(1);
}
int count_ch(char c, char *str)
{
	int count = 0;
	while(*str)
		if(*(str++) == c)
			count++;
	return(count);
}
int check_accur(char *chars,char *line)
{
	while(*line)
	{
		if(!count_ch(*(line++),chars))
			return(0);
	}
	return(1);
}

int check_chars(node *map)
{
	int P = 0;
	int C = 0;
	int E = 0;
	while(map)
	{
		P+=count_ch('P',map->content);
		C+=count_ch('C',map->content);
		E+=count_ch('E',map->content);
		map = map->next;
	}
	if(C >= 1 && P == 1 && E == 1)
		return(1);
	return(0);
}
int check_map(node *map)
{
	static int count;
	size_t size;

	if(!map)
		return(0);
	size = ft_strlen(map->content);
	if(!check_chars(map))
		return(0);
	if(!check_wall(map->content,size-1))
		return(printf("invalid walls\n"),0);
	while(map->next)
	{
		if(!check_accur("01PCE\n",map->content))
			return(printf("invalid chars\n"),0);
		if(size != ft_strlen(map->content))
			return(printf("invalid size\n"),0);
		if(*(char *)map->content != '1' || *((char *)map->content+size - 2)!= '1')
			return(printf("invalid walls\n"),0);
		map = map ->next;
		count++;
	}
	if(!check_wall(map->content,size-1) || count >= 21 || size >= 42)
		return(printf("invalid walls\n"),0);
	if(size != ft_strlen(map->content) +1)
		return(printf("invalid last line\n"),0);
	return(1);
}
