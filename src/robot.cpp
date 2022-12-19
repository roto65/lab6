#include "robot.h"

Robot::Robot() {
	
}

Pos Robot::getPos() const {
	return _pos;
}

void Robot::setPos(Pos new_pos) {
	_pos = new_pos;
}