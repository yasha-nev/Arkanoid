#ifndef ENEMY_hpp
#define ENEMY_hpp

#include "CollisionObject.hpp"

#define ENEMY_WIDTH 10
#define ENEMY_HEIGHT 2

#define MAX_LEVEL 6

class Enemy: public CollisionObject {
public:
    Enemy(int x, int y, int level);

    void makeHit();

    // CollisionObject method
    void handleCollision(const std::shared_ptr<CollisionObject> &object) override;

private:
    void updateColor();

    int m_level;
};

#endif
