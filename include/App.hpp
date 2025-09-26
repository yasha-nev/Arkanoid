#ifndef APP_hpp
#define APP_hpp

#include "Ball.hpp"
#include "BaseObject.hpp"
#include "CollisionManager.hpp"
#include "GameStarter.hpp"
#include "InputHandler.hpp"
#include "MainScreen.hpp"
#include "Player.hpp"

#include <list>
#include <memory>
#include <unistd.h>

/**
 * @brief Main class representing the Arkanoid game application.
 *
 * Manages all core components including player input handling, collision detection,
 * game logic updates, and rendering.
 */
class App {
public:

    /**
     * @brief Default constructor initializing internal state.
     *
     * Sets up necessary components and prepares the game for execution.
     */
    App();

    /**
     * @brief Runs the main game loop until completion.
     *
     * Handles user inputs, updates game objects, detects collisions, and renders frames.
     *
     * @return Exit code indicating success or failure.
     */
    int run();

private:

    /**
     * @brief Creates enemy objects within the game world.
     *
     * Generates enemies in columns located in the play area.
     */
    void createEnemy();

    /**
     * @brief Clears all active enemy objects
     */
    void clearEnemy();

    /**
     * @brief Updates the current game state.
     * 
     * Processes movement, collision checks, removes destroyed enemies
     */
    void updateGame();

    /**
     * @brief Stop the game process
     */
    void startGame();

    /**
     * @brief Start the game process
     */
    void stopGame();

    /** Number of remaining lives available to the player. */
    int m_livesCount;

    /** Flag indicating whether the game has started */
    bool m_isStarted;

    /** Manager object handling collision detections between game entities. */
    CollisionManager m_collisionManager;

     /** Handler for processing keyboard inputs. */
    InputHandler m_inputHandler;

    /** Main graphical interface displaying the game's visual elements. */
    MainScreen m_mainScreen;

    /** The object responsible for handling the game start event. */
    std::shared_ptr<GameStarter> m_gameStarter;

    /** Player-controlled character moving around the screen. */
    std::shared_ptr<Player> m_player;

    /** Bouncing ball used to destroy enemies. */
    std::shared_ptr<Ball> m_ball;

    /** List of wall boundaries defining the game arena. */
    std::list<std::shared_ptr<CollisionObject>> m_walls;

    /** Line marking the end-of-game boundary. */
    std::shared_ptr<CollisionObject> m_gameOverLine;

    /** Collection of currently active enemy objects. */
    std::list<std::shared_ptr<CollisionObject>> m_enemy;

    /**
     * @brief Special access granted to the GameStarter class.
     *
     * Allows GameStarter to directly interact with private members of App.
     */
    friend class GameStarter;
};

#endif // APP_hpp
