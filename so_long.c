#include "so_long.h"

int main(int ac, char **av)
{
	if(ac != 2)
		return(0);
	printf("%s",av[1]);
}