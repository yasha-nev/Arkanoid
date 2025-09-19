#ifndef COLLISIONOBJECT_hpp
#define COLLISIONOBJECT_hpp

class CollisionObject {
public:

    CollisionObject(int width, int height, int x, int y) : m_x(x), m_y(y), m_width(width), m_height(height) {}

    bool collidesWith(const CollisionObject *other) const {
        return (
            m_x >= other->m_x && m_x <= other->m_x + other->m_width && 
            m_y >= other->m_y && m_y <= other->m_y + other->m_height
        );
    }

    virtual void handleCollision(const CollisionObject *object) = 0;

    int m_x;
    int m_y;
    int m_width;
    int m_height;
};
#endif