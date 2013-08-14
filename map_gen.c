#include <stdio.h>
#include <stdlib.h>

void gen_woodlands(char * map, int size) {
	int i;
	int currpos = (map_size_y*(rand()%map_size_y))+rand()%map_size_x;
	printf("%d\n", currpos);
	Position q = to_position(currpos);
	printf("%d/%d\n", q.x, q.y);
	for (i = 0; i < size; i++) {
		/* The woodlands pattern is as so:
		 *  @
		 * @#@
		 *  @
		 * where the @ are replication positions
		 */

		 map[currpos] = '#';
		 map[currpos+1] = '#';
		 map[currpos-1] = '#';
		 map[currpos-map_size_x] = '#';
		 map[currpos+map_size_x] = '#';
		 int v = rand()%4;
		 switch (v) {
		 	case 0: currpos = currpos-1; break;
		 	case 1: currpos = currpos+1; break;
		 	case 2: currpos = currpos-map_size_x; break;
		 	case 3: currpos = currpos+map_size_x; break;
		 	default: printf("Randomization error.");break;
		 }
	}
	return;
}

void gen_map(char * map, int rand) {
	map[0] = '#';
	//Cover it with marshland
	int i;
	srand(rand);
	for (i = 0; i < (map_size_x*map_size_y); i++) {
		map[i] = '.';
	}
	// Generate some woods
	for (i = 0; i < num_woodlands; i++) {
		gen_woodlands(map, woodland_size);
	}
	return;
}