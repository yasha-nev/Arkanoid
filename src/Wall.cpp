#include "Wall.hpp"
#include <iostream>

Wall::Wall(int width, int height, int x, int y):
    DrawableObject(width, height, x, y, '#'),
    CollisionObject(width, height, x, y) {
}

void Wall::handleCollision(const CollisionObject * object) {
    std::cout << "Wall collision!!!" << std::endl;
}