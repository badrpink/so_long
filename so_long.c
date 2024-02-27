
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
int main(int ac, char **av)
{
	if(ac != 2)
		return(printf("invalid argements\n"),0);
	if( -1 == open(av[1],O_RDONLY))
		return(printf("cant find or open file\n"),0);
	if(!check_file_name(av[1]))
		return(printf("invalid file extension\n"));
	
}