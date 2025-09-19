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

    void updateObject();

    int run();

private:
    std::unique_ptr<CollisionManager> m_collisionManager;
    std::unique_ptr<InputHandler> m_inputHandler;
    std::shared_ptr<Player> m_player;
    std::shared_ptr<Ball> m_ball;
    MainScreen m_mainScreen;
    std::list<std::shared_ptr<CollisionObject>> m_gameElements;
};

#endif
