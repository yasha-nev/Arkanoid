#ifndef ENEMY_hpp
#define ENEMY_hpp

#include "CollisionObject.hpp"

#define ENEMY_WIDTH 10
#define ENEMY_HEIGHT 2

class Enemy: public CollisionObject {
public:
    Enemy(int x, int y, int level);

    void makeHit();

    // CollisionObject method
    void handleCollision(CollisionObject* object) override;

private:
    int m_level;
};

#endif
