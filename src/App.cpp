#include "App.hpp"

#include "Enemy.hpp"
#include "ObjectFactory.hpp"
#include "Wall.hpp"

App::App() {
    ObjectFactory objectFactory(m_inputHandler, m_collisionManager, m_mainScreen);

    auto size = m_mainScreen.getScreenSize();

    m_ball = objectFactory.createBall(size.second / 2, size.first - 5);
    m_player = objectFactory.createPlayer(size.second / 2, size.first - 2);

    m_walls.push_back(objectFactory.createWall(size.second - 1, 1, 0, 0));              // wall Up
    m_walls.push_back(objectFactory.createWall(size.second - 1, 1, 0, size.first - 1)); // wall Down
    m_walls.push_back(objectFactory.createWall(1, size.first - 1, 0, 0)); // wall Right
    m_walls.push_back(objectFactory.createWall(1, size.first - 1, size.second - 1, 0)); // wall Left

    int shipCountInRow = (size.second - 2) / (ENEMY_WIDTH + 2);
    int shiCountInColumn = (size.first / 2);

    for(int i = 5; i < shiCountInColumn; i += 3) {
        for(int j = 0; j < shipCountInRow; j++) {
            m_enemy.push_back(objectFactory.createEnemy(j * (ENEMY_WIDTH + 2) + 3, i, 3));
        }
    }
}

void App::updateEnemy() {
    for(auto object: m_enemy) {
        if(object->getDeadStatus()) {
            m_collisionManager.removeObject(object);
            m_mainScreen.removeBaseObject(object);
        }
    }
}

int App::run() {
    using namespace std::chrono_literals;

    m_inputHandler.start();

    while(m_inputHandler.isRunning.load()) {
        m_mainScreen.clear();

        std::this_thread::sleep_for(100ms);

        m_collisionManager.checkCollisions();

        m_ball->updateMove();

        m_mainScreen.update();

        m_mainScreen.draw();

        updateEnemy();
    }

    m_inputHandler.stop();

    return 0;
}
