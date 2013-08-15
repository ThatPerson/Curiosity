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
#include "defines.c"



#include "map_controls.c"
#include "map_gen.c"






int main(int argc, char *argv[]) {
	char map[map_size_x*map_size_y];
	char *mapl;
	mapl = map;
	mapl[0] = '#';
	gen_map(mapl, 4010);
	char input[50];
	player.water = 500;
	player.food = 500;
	printf("Curiosity version 1, Copyright (C) 2013 Ben Tatman\nCuriosity comes with ABSOLUTELY NO WARRANTY.  This is \nfree software, and you are welcome to redistribute it under \ncertain conditions. Look in the LICENSE file for more info.\n");
	printf("You are in a field in the middle of the country side, with no food or water to bear. You see mountains, and streams. Find some water and food.\nCommands avaliable are: \n\tn = North\n\tne = North East\n\t(And so on)\n\ttake = Takes items\n\tinventory = Takes inventory.\n");
	while (1==1) {
		printf("> ");
		scanf("%49s", input);
		if (input[0] == 'n') {
			if (input[1] == 'e') {
				move(mapl, 2);
			} else if (input[1] == 'w') {
				move(mapl, 0);
			} else {
				move(mapl, 1);
			}
		} else if (input[0] == 'e') {
			move(mapl, 3);
		} else if (input[0] == 's') {
			if (input[1] == 'e') {
				move(mapl, 4);
			} else if (input[1] == 'w') {
				move(mapl, 6);
			} else {
				move(mapl, 5);
			}
		} else if (input[0] == 'w') {
			move(mapl, 7);
		} else if (input[0] == 't') {
			take(mapl, player.pos);
		} else if (input[0] == 'i') {
			inventory();
		}
		if (are_they_dead() == 1) {
			printf("You died from lack of food and water\n");
			break;
		}
	}
	take(mapl, water.pos[0]);
	check_ground(mapl, 0);
	return 1;
}