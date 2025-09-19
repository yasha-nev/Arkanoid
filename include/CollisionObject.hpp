#ifndef COLLISIONOBJECT_hpp
#define COLLISIONOBJECT_hpp

#include "BaseObject.hpp"

class CollisionObject: public BaseObject {
public:
    CollisionObject(int width, int height, int x, int y, char symbol);

    virtual ~CollisionObject() = default;

    bool collidesWith(const CollisionObject* other) const;

    virtual void handleCollision(CollisionObject* object) = 0;
};

#endif
