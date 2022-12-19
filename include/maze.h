#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

#include "pos.h"

class Maze {
	public:
		Maze(std::vector<std::string> field, Pos s,int lun, int lar);
		std::vector<std::string> getField();
		char getCell(Pos p);
		Pos getStart();
		int getWidth();
		int getHeight();
	private:
		std::vector<std::string> _field;
		Pos _start;
		int _width,_height; //larghezza(orizontale), altezza(verticale)
};

Maze read_from_file(std::string path);
#endif //MAZE_H
