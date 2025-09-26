#ifndef ENEMY_hpp
#define ENEMY_hpp

#include "CollisionObject.hpp"

#define ENEMY_WIDTH 10
#define ENEMY_HEIGHT 2

#define MAX_LEVEL 6

/**
 * @brief Represents an adversary or obstacle within the game.
 *
 * Enemies inherit collision abilities and manage their own health or hit points.
 */
class Enemy: public CollisionObject {
public:
    /**
     * @brief Constructs an enemy object at a specified location.
     *
     * Additionally assigns difficulty level influencing enemy strength.
     *
     * @param x Initial horizontal coordinate.
     * @param y Initial vertical coordinate.
     * @param level Live level of the enemy.
     */
    Enemy(int x, int y, int level);

    /**
     * @brief Life loss after contact
     */
    void makeHit();

    /**
     * @brief Handles collision events triggered by other game objects.
     *
     * Overrides the abstract method from CollisionObject to define custom collision responses.
     *
     * @param object Reference to the colliding object.
     */
    void handleCollision(const std::shared_ptr<CollisionObject>& object) override;

private:
    /**
     * @brief Updates the enemy's visual appearance.
     *
     * Reflects current state.
     */
    void updateColor();

    /**
     * @brief Level indicator signifying enemy challenge rating.
     */
    int m_level;
};

#endif // ENEMY_hpp
