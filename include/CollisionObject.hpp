#ifndef COLLISIONOBJECT_hpp
#define COLLISIONOBJECT_hpp

#include "BaseObject.hpp"
#include <memory>

/**
 * @brief Represents a collidable entity within the game world.
 *
 * Extends BaseObject to provide additional functionality related to collision detection and interaction behavior.
 */
class CollisionObject: public BaseObject {
public:
    /**
     * @brief Constructs a collision-aware object with specified geometry and appearance.
     *
     * @param width Width of the object.
     * @param height Height of the object.
     * @param x X-coordinate of object's top-left corner.
     * @param y Y-coordinate of object's top-left corner.
     * @param drawSymbol Character used to render the object visually.
     */
    CollisionObject(int width, int height, int x, int y, char symbol);

    /**
     * @brief Virtual destructor to ensure proper cleanup when subclassing.
     */
    virtual ~CollisionObject() = default;

    /**
     * @brief Responds to a collision event involving another object.
     *
     * Must be overridden by subclasses to define specific collision-handling behaviors.
     *
     * @param object Pointer to the object involved in the collision.
     */
    virtual void handleCollision(const std::shared_ptr<CollisionObject> &object) = 0;

    /**
     * @brief Determines if there is overlap with another collision object.
     *
     * Performs axis-aligned bounding box intersection test.
     *
     * @param other Shared pointer to the second object being tested against.
     * @return True if overlapping, false otherwise.
     */
    bool collidesWith(const std::shared_ptr<CollisionObject> &other) const;
};

#endif // COLLISIONOBJECT_hpp
