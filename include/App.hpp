#ifndef APP_hpp
#define APP_hpp

#include "CollisionManager.hpp"
#include "DrawableObject.hpp"
#include "Enemy.hpp"
#include "InputHandler.hpp"
#include "MainScreen.hpp"
#include "Player.hpp"
#include "Wall.hpp"
#include "Ball.hpp"

#include <chrono>
#include <list>
#include <memory>
#include <thread>
#include <unistd.h>

class App {
public:
    App();

    int run();

private:
    std::unique_ptr<CollisionManager> m_collisionManager;
    std::unique_ptr<InputHandler> m_inputHandler;
    std::shared_ptr<Player> m_player;
    std::shared_ptr<Ball> m_ball;
    MainScreen m_mainScreen;
    std::list<std::shared_ptr<DrawableObject>> m_gameElements;
};

#endif
