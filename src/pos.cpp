#include "pos.h"

Pos::Pos() {
    
}

Pos::Pos (int X, int Y) {
    x = X;
    y = Y;
}

Pos Pos::operator+ (Pos p) {
    return Pos (x + p.x, y + p.y);
}

bool Pos::operator== (Pos p) {
    return (x == p.x) && (y == p.y);
}