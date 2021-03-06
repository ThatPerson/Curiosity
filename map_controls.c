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

Position to_position(int loc) {
	Position pos;
	pos.x = 0;
	pos.y = 0;
	while (loc >= map_size_x) {
		pos.x++;
		loc -= map_size_x;
	}
	pos.y = loc;
	return pos;
}

int to_locations(Position x) {
	return (x.x*256)+x.y;
}

int inventory(void) {
	printf("You have %.0f water\nAnd %.0f food.\n", player.water, player.food);
	return 1;
}

int are_they_dead(void) {
	if ((player.water < min_water) && (player.food < min_food)) {
		return 1;
	}
	return 0;
}

int take(char * map, Position p) {
	int i, q = 0;
	for (i = 0; i < water.count; i++) {
		if ((p.y == water.pos[i].y) && (p.y == water.pos[i].y)) {
			player.water += water_inc;
			q = 1;
			printf("You take some water\n");
		}
	}
	for (i = 0; i < food.count; i++) {
		if ((p.y == food.pos[i].y) && (p.x == food.pos[i].x)) {
			player.food += food_inc;
			q = 1;
			printf("You take some food\n");
		}
	}
	if (q == 0) {
		printf("There is nothing here.\n");
	}
	return 1;
}
	
int check_ground(char * map, int loc) {


	Position ql = to_position(loc);

	int i;
	for (i = 0; i < food.count; i++) {
		if ((ql.x == food.pos[i].x) && (ql.y == food.pos[i].y)) {
			printf("You see food on the ground.\n");
		}
	}
	for (i = 0; i < water.count; i++) {
		if ((ql.x == water.pos[i].x) && (ql.y == water.pos[i].y)) {
			printf("You see water on the floor, nicely packed into a very portable bottle.\n");
		}
	}
	switch (map[loc]) {
		case '#': printf("You wander in the woodland\n"); return 1;
		case 'L': printf("A lake blocks your path\n"); return 0;
		case 'C': printf("A bland cave wall bears down on you\n"); return 0;
		case 'c': printf("You walk in the cave\n"); return 1;
		case 'P': printf("You go along the path\n"); return 1;
		case 'H': printf("There is a wall to a house\n"); return 0;
		case 'M': printf("There is a mountain\n"); return 0;
		case 'o': printf("There is a pit. You fall down it, and loose water and food.\n"); player.water = player.water/2; player.food = player.food - 30; return 1;
		case '.': printf("You walk over the marshland\n"); return 1;
		default: return 1;
	}
	
	return 1;
}

void move(char * map, int direction) {
	/* 0 is NW,
	 * 1 is N
	 * 2 is NE
	 * 3 is E
	 * 4 is SE
	 * 5 is S
	 * 6 is SW
	 * 7 is W
	 */
	 Position pl = player.pos;
	 switch (direction) {
	 	case 0:
	 		pl.x -= 1;
	 		pl.y -= 1;
	 		break;
	 	case 1:
	 		pl.y -= 1;
	 		break;
	 	case 2:
	 		pl.y -= 1;
	 		pl.x += 1;
	 		break;
	 	case 3:
	 		pl.x += 1;
	 		break;
	 	case 4:
	 		pl.x += 1;
	 		pl.y += 1;
	 		break;
	 	case 5:
	 		pl.y += 1;
	 		break;
	 	case 6:
	 		pl.y += 1;
	 		pl.x -= 1;
	 		break;
	 	case 7:
	 		pl.x -= 1;
	 		break;
	 }
	int l = to_locations(pl);
	if (check_ground(map, l) == 1) {
		player.pos.x = pl.x;
		player.pos.y = pl.y;
	}
	player.water -= 5;
	player.food -= 5;
	return; 		
}

