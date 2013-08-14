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
	gen_map(mapl, 400);
	char input[50];
	player.water = 500;
	player.food = 500;
	while (1==1) {
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