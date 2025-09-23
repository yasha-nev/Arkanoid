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

class App {
public:
    App();

    int run();

private:
    void createEnemy();

    void clearEnemy();

    void updateGame();

    void startGame();

    void stopGame();

    int m_livesCount;

    bool m_isStarted;

    CollisionManager m_collisionManager;
    InputHandler m_inputHandler;
    MainScreen m_mainScreen;

    std::shared_ptr<GameStarter> m_gameStarter;

    std::shared_ptr<Player> m_player;
    std::shared_ptr<Ball> m_ball;

    std::list<std::shared_ptr<CollisionObject>> m_walls;
    std::shared_ptr<CollisionObject> m_gameOverLine;
    std::list<std::shared_ptr<CollisionObject>> m_enemy;

    friend class GameStarter;
};

#endif
