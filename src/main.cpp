#include <iostream>

#include "maze.h"
#include "random_robot.h"
#include "right_hand_rule_robot.h"


int main(void) {

	Maze m1 = read_from_file("maps/map5.txt");

	RandomRobot r1 (m1.getStart());
	// RightHandRuleRobot r1 (m1.getStart());

	char robot_position = 'S';

	long long i = 0;

	while (true) {
		i++;
		robot_position = r1.move(m1);
		// std::cout << r1.getPos().x << " | " << r1.getPos().y << std::endl;

		switch (robot_position) {
		case 'E':
			std::cout << "Ho vinto in " << i << " mosse!" << std::endl;
			return 0;
		case 'l':
			std::cout << "Il robot é entrato in loop!" << std::endl;
			return 0;
		}
	}
}
