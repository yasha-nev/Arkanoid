#ifndef APP_hpp
#define APP_hpp

#include "Ball.hpp"
#include "BaseObject.hpp"
#include "CollisionManager.hpp"
#include "InputHandler.hpp"
#include "MainScreen.hpp"
#include "Player.hpp"

#include <list>
#include <memory>
#include <unistd.h>

class App {
public:
    App();

    void updateEnemy();

    int run();

private:
    CollisionManager m_collisionManager;
    InputHandler m_inputHandler;
    MainScreen m_mainScreen;

    std::shared_ptr<Player> m_player;
    std::shared_ptr<Ball> m_ball;

    std::list<std::shared_ptr<CollisionObject>> m_walls;
    std::list<std::shared_ptr<CollisionObject>> m_enemy;
};

#endif
