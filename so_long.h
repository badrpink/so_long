
#ifndef SO_LONG_H
#define SO_LONG_H

#include <libc.h>
#include "./libft/libft.h"
#include "get_next_line.h"

typedef struct node{
	void *content;
	struct node *next;
} node;

typedef struct cord{
	int x;
	int y;
} cord;

typedef struct info{
	node *map;
	int height;
	int width;
	cord position;
	node *garbage;
}info;
int check_map(node *map);
int check_wall(char *line, int n);

#endif