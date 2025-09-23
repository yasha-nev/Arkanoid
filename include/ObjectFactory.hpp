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

class ObjectFactory {
public:
    ObjectFactory(
        InputHandler& inputHandler,
        CollisionManager& collisionManager,
        MainScreen& mainScreen);

    std::shared_ptr<Player> createPlayer(int x, int y);

    std::shared_ptr<Ball> createBall(int x, int y);

    std::shared_ptr<Wall> createWall(int width, int height, int x, int y);

    std::shared_ptr<Enemy> createEnemy(int x, int y, int speed);

private:
    InputHandler& m_inputHandler;
    CollisionManager& m_collisionManager;
    MainScreen& m_mainScreen;
};

#endif
