#ifndef ROBOT_H
#define ROBOT_H

#include "maze.h"
#include "pos.h"

class Robot {
	public:
		Pos getPos() const;
	protected:
		Robot();
		virtual char move (Maze& m) = 0;
		void setPos (Pos new_pos);
	private:
		Pos _pos;
};

#endif //ROBOT_H
