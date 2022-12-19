#include <string>
#include <fstream>
#include <vector>

#include "maze.h"

Maze::Maze (std::vector<std::string> field, Pos s,int lun, int lar) {
	_field = field;
	_start = s;
	_lung = lun;
	_larg = lar;
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

int Maze::getLung() {
	return _lung;
}
int Maze::getLarg() {
	return _larg;
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

	return Maze(field, s,line.size(),field.size());
}
