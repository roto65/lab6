#ifndef RANDOM_ROBOT_H
#define RANDOM_ROBOT_H

#include "robot.h"
#include "maze.h"

class RandomRobot : public Robot {
	public :
		RandomRobot(Pos p);
		char move (Maze& m) override;
};

#endif //RANDOM_ROBOT_H
