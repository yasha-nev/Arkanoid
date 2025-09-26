#ifndef PLAYER_hpp
#define PLAYER_hpp

#include "CollisionObject.hpp"
#include "IInputObserver.hpp"

#include <mutex>

#define PLAYER_DEFAULT_WIDTH 15
#define PLAYER_DEFAULT_HEIGHT 1

/**
 * @brief Represents the player's controllable avatar in the game.
 *
 * Inherits collision capabilities and implements input observation to respond dynamically to user actions.
 */
class Player: public CollisionObject, public IInputObserver {
public:
    /**
     * @brief Constructs a player object at a specific location.
     *
     * Initializes the player's position and sets up collision-related internals.
     *
     * @param x Initial horizontal top-left corner coordinate.
     * @param y Initial vertical top left corner coordinate.
     */
    Player(int x, int y);

    /**
     * @brief Moves the player to the right along the X-axis.
     *
     * Adjusts the player's position accordingly within valid bounds.
     */
    void moveRight();

    /**
     * @brief Moves the player to the left along the X-axis.
     *
     * Adjusts the player's position accordingly within valid bounds.
     */
    void moveLeft();

    /**
     * @brief Receives notifications about key press events.
     *
     * Implements the required method from the IInputObserver interface to respond to input.
     *
     * @param keyCode Identifier of the pressed key.
     */
    void onKeyPressed(int keyCode) override;

    /**
     * @brief Handles collision events triggered by other game objects.
     *
     * Overrides the abstract method from CollisionObject to define custom collision responses.
     *
     * @param object Reference to the colliding object.
     */
    void handleCollision(const std::shared_ptr<CollisionObject> &object) override;

private:
    /**
     * @brief Mutex protecting multi-threaded access to player state.
     */
    std::mutex m_mtx;
};

#endif // PLAYER_hpp
