/*
Curiosity. Insanely simple adventure game, written in less than 12 hours (day project, I also did other stuff in that day).
Copyright (C) 2013  Ben Tatman

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

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
#define num_woodlands 50
#define woodland_size 50
#define path_size 100
#define num_paths 60
#define cave_size 20
#define num_caves 30
#define num_mountains 20
#define mountain_size 30