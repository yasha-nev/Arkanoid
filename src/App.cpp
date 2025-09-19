#include "App.hpp"

#include "Wall.hpp"

App::App() {
    auto size = m_mainScreen.getScreenSize();

    m_inputHandler = std::make_unique<InputHandler>();
    m_collisionManager = std::make_unique<CollisionManager>();
    m_player = std::make_shared<Player>(size.second / 2, size.first - 2);
    m_ball = std::make_shared<Ball>(size.second / 2, size.first - 5);

    m_inputHandler->subscribe(m_player);
    m_collisionManager->addCollisionObject(m_player);
    m_mainScreen.addDrawableObject(m_player);

    m_inputHandler->subscribe(m_ball);
    m_collisionManager->addCollisionObject(m_ball);
    m_mainScreen.addDrawableObject(m_ball);

    auto wallUp = std::make_shared<Wall>(size.second - 1, 1, 0, 0);
    auto wallDown = std::make_shared<Wall>(size.second - 1, 1, 0, size.first - 1);
    auto wallRight = std::make_shared<Wall>(1, size.first - 1, 0, 0);
    auto wallLeft = std::make_shared<Wall>(1, size.first - 1, size.second - 1, 0);

    m_mainScreen.addDrawableObject(wallUp);
    m_mainScreen.addDrawableObject(wallDown);
    m_mainScreen.addDrawableObject(wallRight);
    m_mainScreen.addDrawableObject(wallLeft);

    m_collisionManager->addCollisionObject(wallUp);
    m_collisionManager->addCollisionObject(wallDown);
    m_collisionManager->addCollisionObject(wallRight);
    m_collisionManager->addCollisionObject(wallLeft);

    int shipCount = (size.second - 2) / 12;
    for(int i = 5; i < size.first / 2; i += 3) {
        for(int j = 0; j < shipCount; j++) {
            auto object = std::make_shared<Enemy>(j * 12 + 3, i, 5);
            m_gameElements.push_back(object);
            m_mainScreen.addDrawableObject(object);
            m_collisionManager->addCollisionObject(object);
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
    }

    m_inputHandler->stop();

    return 0;
}
