#ifndef ENEMY_hpp
#define ENEMY_hpp

#include "DrawableObject.hpp"
#include "CollisionObject.hpp"

#define ENEMY_WIDTH 10
#define ENEMY_HEIGHT 2

class Enemy: public DrawableObject, public CollisionObject {
public:
    Enemy(int x, int y, int level);

    void makeHit();

    void destroy();

    //CollisionObject method
    void handleCollision(const CollisionObject * object) override;
private:
    int m_level;
};

#endif
