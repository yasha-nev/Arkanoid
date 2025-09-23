#include "ObjectFactory.hpp"

ObjectFactory::ObjectFactory(
    InputHandler& inputHandler,
    CollisionManager& collisionManager,
    MainScreen& mainScreen):
    m_inputHandler(inputHandler),
    m_collisionManager(collisionManager),
    m_mainScreen(mainScreen) {
}

std::shared_ptr<Player> ObjectFactory::createPlayer(int x, int y) {
    auto player = std::make_shared<Player>(x, y);
    m_inputHandler.subscribe(player);
    m_collisionManager.addCollisionObject(player);
    m_mainScreen.addBaseObject(player);
    return player;
}

std::shared_ptr<Ball> ObjectFactory::createBall(int x, int y) {
    auto ball = std::make_shared<Ball>(x, y);
    m_collisionManager.addCollisionObject(ball);
    m_mainScreen.addBaseObject(ball);
    return ball;
}

std::shared_ptr<Wall> ObjectFactory::createWall(int width, int height, int x, int y) {
    auto wall = std::make_shared<Wall>(width, height, x, y);
    m_collisionManager.addCollisionObject(wall);
    m_mainScreen.addBaseObject(wall);
    return wall;
}

std::shared_ptr<Enemy> ObjectFactory::createEnemy(int x, int y, int speed) {
    auto enemy = std::make_shared<Enemy>(x, y, speed);
    m_mainScreen.addBaseObject(enemy);
    m_collisionManager.addCollisionObject(enemy);
    return enemy;
}
