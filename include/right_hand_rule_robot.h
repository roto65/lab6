#ifndef RIGTH_HAND_RULE_ROBOT_H
#define RIGTH_HAND_RULE_ROBOT_H

#include "robot.h"
#include "maze.h"

class RightHandRuleRobot : public Robot {
	public:
		RightHandRuleRobot(Pos p);
		char move (Maze& m) override;	
	private:
		void initial_move(Maze& m);
		void forward ();

		int _facing;

		int _initial_facing; // 0 -> up, rotazioni in senso orario, [0 - 3]
		Pos _initial_pos;
};

#endif //RIGTH_HAND_RULE_ROBOT_H
