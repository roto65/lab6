#ifndef POS_H
#define POS_H

struct Pos {

    int x, y;

    Pos();
    Pos(int X, int Y);

    Pos operator+ (Pos p);

    bool operator== (Pos p);

};

#endif //POS_H