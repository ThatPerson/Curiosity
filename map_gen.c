#include <stdio.h>
#include <stdlib.h>

int absol(int q) {
	if (q < 0) {
		q = 0-q;
	}
	return q;
}

void draw_diamond(char * map, int currpos, int radius, char put) {
	int i, l;
	if (currpos > ((radius*map_size_y)+radius)) {
		for (i = -radius; i <= radius; i++) {
			for (l = -(radius-absol(i)); l <= (radius-absol(i)); l++) {
				map[currpos+(i*map_size_y)+l] = put;
				//printf("> \t%d/%d\n", i, l);
			}
		}
	}
	return;
}

void woodlands(char * map, int currpos) {
	draw_diamond(map, currpos, 2, '#');
	
}

void path(char * map, int currpos) {
	if (currpos > 0) {
		map[currpos] = 'P';
		map[currpos+1] = 'P';
	}
}

void cave(char *map, int currpos) {
	if (currpos > (map_size_x+2)) {
		map[currpos-map_size_x+1] = 'C';
		map[currpos-map_size_x-1] = 'C';
		map[currpos+map_size_x+1] = 'C';
		map[currpos+map_size_x-1] = 'C';
		int q;
		int i;
		for (i = 0; i < 2; i++) {
			q = rand()%4;
			switch (q) {
				case 0: map[currpos-map_size_x] = 'C'; break;
				case 1: map[currpos+map_size_x] = 'C'; break;
				case 2: map[currpos+1] = 'C'; break;
				case 3: map[currpos-1] = 'C'; break;
				default: printf("Randomization error.\n"); break;
			}
		}
	} else {
		return;
	}
}

void mountain(char *map, int currpos) {
	draw_diamond(map, currpos, 1, 'M');
}

void gen_area(char * map, int size, void (*wr)(char *, int)) {

	int i;
	int currpos = (map_size_y*(rand()%map_size_y))+rand()%map_size_x;

	Position q = to_position(currpos);

	for (i = 0; i < size; i++) {
		/* The woodlands pattern is as so:
		 *  @
		 * @#@
		 *  @
		 * where the @ are replication positions
		 */
		wr(map, currpos);

		int v = rand()%4;
		switch (v) {
			case 0: currpos = currpos-1; break;
			case 1: currpos = currpos+1; break;
			case 2: currpos = currpos-map_size_x; break;
			case 3: currpos = currpos+map_size_x; break;
			default: printf("Randomization error.");break;
		}
		if (currpos < 0) {
			currpos = ((map_size_x*(map_size_y/2))+(map_size_x/2));
		}
	}
	return;
}

void gen_map(char * map, int rand) {

	//Cover it with marshland
	int i;
	srand(rand);
	for (i = 0; i < (map_size_x*map_size_y); i++) {
		map[i] = '.';
	}
	// Generate some woods
	for (i = 0; i < num_woodlands; i++) {
		gen_area(map, woodland_size, woodlands);
	}
	for (i = 0; i < num_mountains; i++) {
		gen_area(map, mountain_size, mountain);
	}
	for (i = 0; i < num_paths; i++) {
		gen_area(map, path_size, path);
	}
	for (i = 0; i < num_caves; i++) {
		gen_area(map, cave_size, cave);
	}
	return;
}