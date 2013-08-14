#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
} Position;

typedef struct {
	Position pos;
	float water;
	float food;
} Player;

typedef struct {
	Position pos[500];
	int count;
} Item;

Item water;
Item food;

Player player;

// Do not edit anything above this line

#define map_size_x 256
#define map_size_y 256
#define min_water 5
#define min_food 7
#define water_inc 20
#define food_inc 25