#ifndef WALL_hpp
#define WALL_hpp

#include "DrawableObject.hpp"
#include "CollisionObject.hpp"

class Wall: public DrawableObject, public CollisionObject {
public:

    Wall(int width, int height, int x, int y);

    //CollisionObject method
    void handleCollision(const CollisionObject * object) override;
};

#endif
