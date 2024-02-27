
#include "so_long.h"

int check_file_name(char *str)
{
	int size = ft_strlen(str);
	if(size < 5 || str[0] == '.')
		return(0);
	if(str[size-4] == '.' && str[size-3] == 'b' && str[size-2] == 'e' && str[size-1] == 'r')
		return(1);
	return(0);
}
void add_to_node(node *old, char *str)
{
	node *new;
	if(!old)
		old = new;
	else
		old->next = new;
	old->content = str;
	old ->next = NULL;
}
node *get_map(char *file)
{
	int fd = open(file,O_RDONLY);
	node *map = NULL;
	char *temp;
	while((temp = get_next_line(fd)))
		add_to_node(map, temp);
	return(map);
}

int main(int ac, char **av)
{
	info all;
	if(ac != 2)
		return(printf("invalid argements\n"),0);
	if( -1 == open(av[1],O_RDONLY))
		return(printf("cant find or open file\n"),0);
	if(!check_file_name(av[1]))
		return(printf("invalid file extension\n"));
	all.map = get_map(av[1]);
	if(!check_map(all.map))
		return(printf("invalid_map\n"),0);

	
}