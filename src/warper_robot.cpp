#include <cstdlib>
#include <time.h>

#include "warper_robot.h"
#include "maze.h"
#include "pos.h"

/**
 * return '*' se avanti trova un muro
 * return ' ' se il robot si muove
 * return 'S' se il robot torna al punto di partenza
 * return 'E' se il robot arriva all'uscita
*/

WarperRobot::WarperRobot(Pos p) {
	setPos (p);
}

char WarperRobot::move (Maze& m) {
	srand((unsigned)time(NULL));

	Pos new_pos (rand() % m.getWidth(), rand() % m.getHeight());

	if(m.getCell(new_pos) != '*') setPos(new_pos);

	return m.getCell(new_pos);
}

