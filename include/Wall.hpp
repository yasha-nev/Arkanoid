#ifndef WALL_hpp
#define WALL_hpp

#include "CollisionObject.hpp"

/**
 * @brief Represents a static barrier or wall within the game world.
 *
 * Inherits from CollisionObject to participate in collision detection and response mechanisms.
 */
class Wall: public CollisionObject {
public:
    /**
     * @brief Constructor accepting initial dimensions and position.
     *
     * @param width Width of the object.
     * @param height Height of the object.
     * @param x X-coordinate of object's top-left corner.
     * @param y Y-coordinate of object's top-left corner.
     */
    Wall(int width, int height, int x, int y);

    /**
     * @brief Handles collision events triggered by other game objects.
     *
     * Overrides the abstract method from CollisionObject to define custom collision responses.
     *
     * @param object Reference to the colliding object.
     */
    void handleCollision(const std::shared_ptr<CollisionObject>& object) override;
};

#endif // WALL_hpp
