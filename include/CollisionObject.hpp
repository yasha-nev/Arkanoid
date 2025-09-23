#ifndef COLLISIONOBJECT_hpp
#define COLLISIONOBJECT_hpp

#include "BaseObject.hpp"

class CollisionObject: public BaseObject {
public:
    CollisionObject(int width, int height, int x, int y, char symbol);

    virtual ~CollisionObject() = default;

    virtual void handleCollision(const CollisionObject* object) = 0;

    bool collidesWith(const CollisionObject* other) const;
};

#endif
