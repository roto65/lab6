#include <string>
#include <fstream>
#include <vector>

#include "maze.h"

Maze::Maze (std::vector<std::string> field, Pos s) {
	_field = field;
	_start = s;
}

std::vector<std::string> Maze::getField () {
	return _field;
}

char Maze::getCell(Pos p) {
	std::string line = getField()[p.y];
	return line[p.x];
}

Pos Maze::getStart() {
	return _start;
}

Maze read_from_file (std::string path) {
	std::vector<std::string> field;
	std::string line;
	Pos s;
	
	std::ifstream file;
	file.open(path);
	
	if (file.is_open()) {
		while (!file.eof()) {
			std::getline(file, line);
			field.push_back(line);
		}
	}

	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < line.size(); j++) {
			if (field[i][j] == 'S') {
				s = Pos (j,i);
			}
		}
	}

	file.close();

	return Maze(field, s);
}