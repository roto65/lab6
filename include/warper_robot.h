#ifndef Warper_H
#define Warper_H

#include "maze.h"
#include "pos.h"
#include "robot.h"

class WarperRobot : public Robot {
	public:
		WarperRobot(Pos p);
		char move(Maze& m) override;
};

//il robot si teletrasporta a caso in celle possibili
#endif //Warper_H
