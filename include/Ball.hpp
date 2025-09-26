#ifndef BALL_hpp
#define BALL_hpp

#include "CollisionObject.hpp"
#include "IInputObserver.hpp"

#include <mutex>

#define BALL_WIDTH 1
#define BALL_HEIGHT 1

/**
 * @brief Represents the bouncing ball object in the game.
 *
 * Inheriting from CollisionObject allows participation in collision detection and provides motion behavior.
 */
class Ball: public CollisionObject {
public:
    /**
     * @brief Constructs a ball object at a specified position.
     *
     * @param x Initial horizontal top-left corner coordinate.
     * @param y Initial vertical top-left corner coordinate.
     */
    Ball(int x, int y);

    /**
     * @brief Updates the ball's movement based on direction vectors.
     *
     * Calculates new position considering speed and possible collisions.
     */
    void updateMove();

    /**
     * @brief Initiates ball movement.
     *
     * Establishes the initial velocity vector and activates motion.
     */
    void startMove();

    /**
     * @brief Halts the ball's movement.
     *
     * Brings the ball to rest and resets its position.
     */
    void stopMove();

    /**
     * @brief Restores the ball to its initial/default position.
     *
     * Useful for restarting levels or recovering from game-over scenarios.
     */
    void setDefaultPosition();

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
     * @brief Boolean flag indicating whether the ball is currently moving.
     */
    bool m_isMoved;

    /**
     * @brief Last known X-position of the ball.
     */
    int m_lastPosX;
    
    /**
     * @brief Last known Y-position of the ball.
     */
    int m_lastPosY;

    /**
     * @brief Default X-position where the ball begins or returns to.
     */
    int m_defaultPosX;
    
    /**
     * @brief Default Y-position where the ball begins or returns to.
     */
    int m_defaultPosY;

    /**
     * @brief Direction factor along the X-axis affecting ball trajectory.
     */
    float m_derectionX;

    /**
     * @brief Direction factor along the Y-axis affecting ball trajectory.
     */
    float m_derectionY;

    /**
     * @brief Mutex protecting multi-threaded access to player state.
     */
    std::mutex m_mtx;
};

#endif // BALL_hpp
