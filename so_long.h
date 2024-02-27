
#ifndef SO_LONG_H
#define SO_LONG_H

#include <libc.h>
#include "./libft/libft.h"
#include "get_next_line.h"

typedef struct node{
	void *content;
	struct node *next;
} node;

typedef struct player{
	int x;
	int y;
} player;

typedef struct info{
	node *map;
	int height;
	int width;
	player position;
	node *garbage;
}info;
int check_map(char **lines);

#endif