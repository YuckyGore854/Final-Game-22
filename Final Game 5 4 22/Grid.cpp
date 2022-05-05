#include "Grid.h"

Grid::Grid() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 7; j++) {
			grid[i][j] = 0;
		}
	}
	grid[6][1] = 11;//11 is super generator
	grid[6][5] = 11;//1 is reserved for generator
}