#include <cstdlib>
#include <time.h>

#include "warper_robot.h"
#include "maze.h"
#include "pos.h"

WarperRobot::WarperRobot(Pos p)
{
	setPos (p);
}
char WarperRobot::move (Maze& m) {
	srand((unsigned)time(NULL));
	Pos w(rand()%m.getLung(),rand()%m.getLarg());
	if(m.getCell(w)!='*') setPos(w);
	return m.getCell(w);
}

