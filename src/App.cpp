#include "App.hpp"

#include "Enemy.hpp"
#include "Wall.hpp"

App::App() {
    auto size = m_mainScreen.getScreenSize();

    m_inputHandler = std::make_unique<InputHandler>();
    m_collisionManager = std::make_unique<CollisionManager>();
    m_player = std::make_shared<Player>(size.second / 2, size.first - 2);
    m_ball = std::make_shared<Ball>(size.second / 2, size.first - 5);

    m_inputHandler->subscribe(m_ball);
    m_collisionManager->addCollisionObject(m_ball);
    m_mainScreen.addBaseObject(m_ball);

    m_inputHandler->subscribe(m_player);
    m_collisionManager->addCollisionObject(m_player);
    m_mainScreen.addBaseObject(m_player);

    auto wallUp = std::make_shared<Wall>(size.second - 1, 1, 0, 0);
    auto wallDown = std::make_shared<Wall>(size.second - 1, 1, 0, size.first - 1);
    auto wallRight = std::make_shared<Wall>(1, size.first - 1, 0, 0);
    auto wallLeft = std::make_shared<Wall>(1, size.first - 1, size.second - 1, 0);

    m_mainScreen.addBaseObject(wallUp);
    m_mainScreen.addBaseObject(wallDown);
    m_mainScreen.addBaseObject(wallRight);
    m_mainScreen.addBaseObject(wallLeft);

    m_collisionManager->addCollisionObject(wallUp);
    m_collisionManager->addCollisionObject(wallDown);
    m_collisionManager->addCollisionObject(wallRight);
    m_collisionManager->addCollisionObject(wallLeft);

    int shipCountInRow = (size.second - 2) / (ENEMY_WIDTH + 2);
    int shiCountInColumn = (size.first / 2);

    for(int i = 5; i < shiCountInColumn; i += 3) {
        for(int j = 0; j < shipCountInRow; j++) {
            auto object = std::make_shared<Enemy>(j * (ENEMY_WIDTH + 2) + 3, i, 3);
            m_gameElements.push_back(object);
            m_mainScreen.addBaseObject(object);
            m_collisionManager->addCollisionObject(object);
        }
    }
}

void App::updateObject() {
    for(auto object: m_gameElements) {
        if(object->getDeadStatus()) {
            m_collisionManager->removeObject(object);
            m_mainScreen.removeBaseObject(object);
        }
    }
}

int App::run() {
    using namespace std::chrono_literals;

    m_inputHandler->start();

    while(m_inputHandler->isRunning.load()) {
        m_mainScreen.clear();

        std::this_thread::sleep_for(100ms);

        m_collisionManager->checkCollisions();

        m_ball->updateMove();

        m_mainScreen.update();

        m_mainScreen.draw();

        updateObject();
    }

    m_inputHandler->stop();

    return 0;
}
