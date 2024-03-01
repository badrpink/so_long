
#ifndef SO_LONG_H
#define SO_LONG_H

#include <libc.h>
#include <mlx.h>
#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"

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
	void *mlx;
	void *mlx_win;
	cord *position;
}info;

typedef struct icons{
	void *wall;
	void *background;
	void *exit;
	void *collect;
	void *dir;
}icons;


int check_map(node *map);
int check_wall(char *line, int n);
int count_ch(char c, char *str);
int check_accur(char *chars,char *line);
int check_chars(node *map);
int check_char(node *map,char c);
int check_file_name(char *str);
void destroy_img(void *mlx,node *del);
void add_to_node(node **nod, char *content);
char check_position(node *map,int x,int y);
void get_height_width(info *all, node *map);
cord *get_position(node *map,char c);
node *get_map(char *file);
node *dub_node(node *src);
void put_char_map(node *map, int x,int y,char c);
int check_path(node *map,cord *position);
void flood_fill(node *map,int x,int y);
void draw_it(info all);
void clear_it(node *garbage);
#endif