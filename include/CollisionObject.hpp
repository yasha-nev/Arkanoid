#ifndef COLLISIONOBJECT_hpp
#define COLLISIONOBJECT_hpp

#include "BaseObject.hpp"
#include <memory>

class CollisionObject: public BaseObject {
public:
    CollisionObject(int width, int height, int x, int y, char symbol);

    virtual ~CollisionObject() = default;

    virtual void handleCollision(const std::shared_ptr<CollisionObject> &object) = 0;

    bool collidesWith(const std::shared_ptr<CollisionObject> &other) const;
};

#endif
