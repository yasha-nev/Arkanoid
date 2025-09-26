#ifndef OBJECTFACTORY_hpp
#define OBJECTFACTORY_hpp

#include "Ball.hpp"
#include "CollisionManager.hpp"
#include "Enemy.hpp"
#include "InputHandler.hpp"
#include "MainScreen.hpp"
#include "Player.hpp"
#include "Wall.hpp"

#include <memory>

/**
 * @brief Factory class responsible for instantiating game objects.
 *
 * Facilitates creation of players, balls, walls, and enemies while registering them properly with
 * input handling, collision management, and rendering systems.
 */
class ObjectFactory {
public:
    /**
     * @brief Constructor requiring references to critical services.
     *
     * Dependencies are injected here to facilitate integration with input, collision, and rendering
     * modules.
     *
     * @param inputHandler Instance managing input events.
     * @param collisionManager Instance responsible for collision detection.
     * @param mainScreen Rendering surface for drawing objects.
     */
    ObjectFactory(
        InputHandler& inputHandler,
        CollisionManager& collisionManager,
        MainScreen& mainScreen);

    /**
     * @brief Creates a player object initialized at a specific position.
     *
     * Also registers the player with input handling and collision systems.
     *
     * @param x Initial horizontal coordinate.
     * @param y Initial vertical coordinate.
     * @return Shared pointer to the newly created player object.
     */
    std::shared_ptr<Player> createPlayer(int x, int y);

    /**
     * @brief Instantiates a ball object placed at designated coordinates.
     *
     * Integrates the ball into the collision management system.
     *
     * @param x Initial horizontal coordinate.
     * @param y Initial vertical coordinate.
     * @return Shared pointer to the freshly generated ball object.
     */
    std::shared_ptr<Ball> createBall(int x, int y);

    /**
     * @brief Produces a wall object with predefined dimensions and location.
     *
     * Registers the wall for collision detection.
     *
     * @param width Width of the wall.
     * @param height Height of the wall.
     * @param x Top-left X-coordinate.
     * @param y Top-left Y-coordinate.
     * @return Shared pointer pointing to the constructed wall object.
     */
    std::shared_ptr<Wall> createWall(int width, int height, int x, int y);

    /**
     * @brief Fabricates an enemy object situated at particular coordinates.
     *
     * Enemy is automatically integrated into the collision system.
     *
     * @param x Horizontal coordinate of enemy spawn.
     * @param y Vertical coordinate of enemy spawn.
     * @param level Difficulty level of the enemy (optional parameter).
     * @return Shared pointer referencing the newly spawned enemy.
     */
    std::shared_ptr<Enemy> createEnemy(int x, int y, int level);

private:
    /**
     * @brief Reference to the input handler service.
     */
    InputHandler& m_inputHandler;

    /**
     * @brief Reference to the collision manager service.
     */
    CollisionManager& m_collisionManager;

    /**
     * @brief Reference to the main screen renderer.
     */
    MainScreen& m_mainScreen;
};

#endif // OBJECTFACTORY_hpp
