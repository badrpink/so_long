#include "so_long.h"


int check_map(node *map)
{
	size_t size = ft_strlen(map->content);
	while(map->next)
	{
		if(size != ft_strlen(map->content))
			return(printf("invalid size\n"),0);
			//if(size != ft_strlen(lines[i]) +1 && !lines[i+1])
		//	return(printf("invalid last line\n"),0);
		printf("%zu\n",ft_strlen(map -> content));
		map = map ->next;
	}
	return(1);
}