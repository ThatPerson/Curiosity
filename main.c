#include <stdio.h>
#include <stdlib.h>
#include "defines.c"



#include "map_controls.c"
#include "map_gen.c"

typedef struct {
	int x, y;
} Position;

void gen_map(char * map) {
	map[0] = '~';
	return;
}

Position to_position(int loc) {
	Position pos;
	while (loc >= map_size_x) {
		pos.x++;
		loc -= map_size_x;
	}
	pos.y = loc;
	return pos;
}
int main(int argc, char *argv[]) {
	char map[(map_size_x*10)+map_size_y];
	char *mapl;
	mapl = map;
	mapl[0] = '#';
	gen_map(mapl);
	printf("%c\n", mapl[0]);
	//map[0][0] = '#';
	printf("HEllo\n");
	printf("%d\n", map[0]);
	//gen_map(&map);

	printf("%d\n", sizeof(char[500]));
	
	Position q = to_position(260);
	printf("%d\\%d \n", q.x, q.y);
	
	return 1;
}