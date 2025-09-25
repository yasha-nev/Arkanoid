#include "Wall.hpp"

Wall::Wall(int width, int height, int x, int y):
    CollisionObject(width, height, x, y, '#') {
}

void Wall::handleCollision(const std::shared_ptr<CollisionObject> &object) {
    (void) object;
}
