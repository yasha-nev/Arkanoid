#include "Wall.hpp"

Wall::Wall(int width, int height, int x, int y):
    CollisionObject(width, height, x, y, '#') {
}

void Wall::handleCollision(const CollisionObject* object) {
    (void) object;
}
