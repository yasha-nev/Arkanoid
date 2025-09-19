#ifndef COLLISIONMANAGER_hpp
#define COLLISIONMANAGER_hpp

#include "CollisionObject.hpp"

#include <memory>
#include <vector>

class CollisionManager {
public:
    ~CollisionManager();

    void addCollisionObject(const std::shared_ptr<CollisionObject>& object);
    void removeObject(const std::shared_ptr<CollisionObject>& object);
    void checkCollisions();

private:
    std::vector<std::shared_ptr<CollisionObject>> m_objects;
};

#endif
