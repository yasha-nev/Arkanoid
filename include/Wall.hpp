#ifndef WALL_hpp
#define WALL_hpp

#include "DrawableObject.hpp"

class Wall: public DrawableObject {
public:
    Wall(int width, int height, int x, int y);
};

#endif
