#include <vector>
#include <cstdlib>
#include <time.h>

#include "right_hand_rule_robot.h"
#include "pos.h"


std::vector<Pos> right_cell = {{1,0}, {0,1}, {-1,0}, {0,-1}};
std::vector<Pos> front_cell = {{0,-1}, {1,0}, {0,1}, {-1,0}};

RightHandRuleRobot::RightHandRuleRobot (Pos p) {
    setPos(p);

    _initial_facing = -1;
    _initial_pos = {-1,-1};
}

/**
 * return 'l' se il robot entra in un loop
 * return '*' se avanti trova un muro
 * return ' ' se il robot si muove
 * return 'S' se il robot torna al punto di partenza
 * return 'E' se il robot arriva all'uscita
*/

char RightHandRuleRobot::move (Maze& m) {

    if (_initial_facing == -1) initial_move(m);

    if (m.getCell(getPos() + front_cell[_facing]) == '*') {
        if (_facing == 0) {
            _facing = 3;
        } else {
            _facing -= 1;
        }

        if (_facing == _initial_facing && getPos() == _initial_pos) return 'l';

        return '*';

    } else {
        forward();

        if (_facing == _initial_facing && getPos() == _initial_pos) return 'l';

        if (_facing == 3) {
            _facing = 0;
        } else {
            _facing += 1;
        }
        return m.getCell(getPos());
    }
}

void RightHandRuleRobot::initial_move(Maze& m) {
    for (int i = 0; i < right_cell.size(); i++) {
        if (m.getCell(getPos() + right_cell[i]) == '*') {
            _facing = i;
            _initial_facing = i;
            _initial_pos = getPos();
            return;
        }
    }

    if (_initial_facing == -1) {
        srand((unsigned) time(NULL));
        _facing = rand() % 4;
        
        while (m.getCell(getPos() + front_cell[_facing]) != '*') {
            forward();
        }

        if (_facing == 0) {
            _facing = 3;
        } else {
            _facing -= 1;
        }

        _initial_facing = _facing;
        _initial_pos = getPos();
    }
}

void RightHandRuleRobot::forward() {
    Pos new_pos = getPos() + front_cell[_facing];
    setPos(new_pos);
}

