#ifndef ENEMY_hpp
#define ENEMY_hpp

#include "DrawableObject.hpp"

#define ENEMY_WIDTH 10
#define ENEMY_HEIGHT 2

class Enemy: public DrawableObject {
public:
    Enemy(int x, int y, int level);

    void makeHit();

    void destroy();

private:
    int m_level;
};

#endif
