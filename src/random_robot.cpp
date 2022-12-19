#include <vector>
#include <cstdlib>
#include <time.h>

#include "random_robot.h"
#include "pos.h"

std::vector<Pos> possible_move = {{0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}};

RandomRobot::RandomRobot (Pos p) {
	setPos(p);
}

/**
 * return '*' se avanti trova un muro
 * return ' ' se il robot si muove
 * return 'S' se il robot torna al punto di partenza
 * return 'E' se il robot arriva all'uscita
*/

char RandomRobot::move (Maze& m) {

	srand((unsigned) time(NULL));
	int rand_i = rand() % 8;

	Pos next_move = getPos() + possible_move[rand_i];

	char next_cell = m.getCell(next_move);
	if (next_cell != '*') {
		if (rand_i % 2 == 0) {
			setPos(next_move);
		} else {
			Pos move_vect = possible_move[rand_i];
			Pos half_move_x = getPos() + Pos (move_vect.x, 0);
			Pos half_move_y = getPos() + Pos (0, move_vect.y);

			char half_move_cell_x = m.getCell(half_move_x);
			char half_move_cell_y = m.getCell(half_move_y);

			if (half_move_cell_x != '*' || half_move_cell_y != '*') setPos(next_move);
		}
	}

	return next_cell;
}

