#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

#include "pos.h"

class Maze {
	public:
		Maze(std::vector<std::string> field, Pos s);
		std::vector<std::string> getField();
		char getCell(Pos p);
		Pos getStart();
	private:
		std::vector<std::string> _field;
		Pos _start;
};

Maze read_from_file(std::string path);
#endif //MAZE_H
