#include "GameStarter.hpp"

#include "App.hpp"

GameStarter ::GameStarter(App& app):
    m_app(app) {
}

void GameStarter ::onKeyPressed(int keyCode) {
    if(keyCode == 'w') {
        if(m_app.m_ball.get() != nullptr && m_app.m_gameOverLine.get() != nullptr) {
            m_app.startGame();
        }
    }
}
