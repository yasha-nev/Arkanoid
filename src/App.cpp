#include "App.hpp"

#include "Enemy.hpp"
#include "ObjectFactory.hpp"
#include "Wall.hpp"

App::App():
    m_livesCount(3),
    m_isStarted(false) {
    ObjectFactory objectFactory(m_inputHandler, m_collisionManager, m_mainScreen);

    auto m_gameStarter = std::make_shared<GameStarter>(*this);
    m_inputHandler.subscribe(m_gameStarter);

    auto size = m_mainScreen.getScreenSize();

    m_ball = objectFactory.createBall(size.second / 2, size.first - 3);
    m_player = objectFactory.createPlayer(size.second / 2, size.first - 2);

    m_gameOverLine = objectFactory.createWall(size.second - 1, 1, 0, size.first - 1);

    m_walls.push_back(objectFactory.createWall(size.second - 1, 1, 0, 0)); // wall Up
    m_walls.push_back(objectFactory.createWall(1, size.first - 1, 0, 0));  // wall Right
    m_walls.push_back(objectFactory.createWall(1, size.first - 1, size.second - 1, 0)); // wall Left

    createEnemy();
}

void App::startGame() {
    if(m_isStarted) {
        return;
    }

    m_ball->stopMove();
    m_ball->setDefaultPosition();

    m_livesCount = 1;

    m_ball->startMove();

    m_isStarted = true;
}

void App::stopGame() {
    if(!m_isStarted) {
        return;
    }

    m_ball->stopMove();

    m_ball->setDefaultPosition();

    clearEnemy();

    createEnemy();

    m_isStarted = false;
}

void App::createEnemy() {
    ObjectFactory objectFactory(m_inputHandler, m_collisionManager, m_mainScreen);

    auto size = m_mainScreen.getScreenSize();

    int enemiesInRow = (size.second - 10) / ENEMY_WIDTH;

    int rowsOfEnemies = MAX_LEVEL;

    int topMargin = 10;

    int currentY = size.first - topMargin - ENEMY_HEIGHT;

    for(int level = 1; level <= rowsOfEnemies; ++level) {
        for(int col = 0; col < enemiesInRow; ++col) {
            int x = 5 + col * ENEMY_WIDTH;
            m_enemy.push_back(objectFactory.createEnemy(x, currentY, level));
        }

        currentY -= (ENEMY_HEIGHT + 1);
    }
}

void App::clearEnemy() {
    for(const auto& object: m_enemy) {
        m_collisionManager.removeObject(object);
        m_mainScreen.removeBaseObject(object);
    }

    m_enemy.clear();
}

void App::updateGame() {
    if(m_ball->collidesWith(m_gameOverLine.get())) {
        m_livesCount--;
    }

    if(m_livesCount <= 0 || m_enemy.size() == 0) {
        stopGame();
    }

    m_collisionManager.checkCollisions();

    auto it = m_enemy.begin();
    while(it != m_enemy.end()) {
        if((*it)->getDeadStatus()) {
            m_collisionManager.removeObject(*it);
            m_mainScreen.removeBaseObject(*it);

            it = m_enemy.erase(it);
        } else {
            ++it;
        }
    }

    m_ball->updateMove();
}

int App::run() {
    using namespace std::chrono_literals;

    m_inputHandler.start();

    while(m_inputHandler.isRunning.load()) {
        m_mainScreen.clear();

        std::this_thread::sleep_for(100ms);

        updateGame();

        m_mainScreen.update();

        m_mainScreen.draw();
    }

    m_inputHandler.stop();

    return 0;
}
