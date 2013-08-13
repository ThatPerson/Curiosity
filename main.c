#include <stdio.h>
#include <stdlib.h>
#include "defines.c"



#include "map_controls.c"
#include "map_gen.c"

void gen_map(char * map[map_size_x][map_size_y]) {
	*map[0][0] = '#';
	return;
}

int main(int argc, char *argv[]) {
	char map[(map_size_x*10)+map_size_y];
	char *mapl;
	mapl = map;
	mapl[0] = '#';
	printf("%c\n", mapl[0]);
	//map[0][0] = '#';
	printf("HEllo\n");
	printf("%d\n", map[0]);
	//gen_map(&map);

	printf("%d\n", sizeof(char[500]));
	return 1;
}