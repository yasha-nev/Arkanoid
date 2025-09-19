#include "App.hpp"

#include "Wall.hpp"

App::App() {
    auto size = m_mainScreen.getScreenSize();

    m_inputHandler = std::make_unique<InputHandler>();
    m_player = std::make_shared<Player>(size.second / 2, size.first - 2);

    m_inputHandler->subscribe(m_player);
    m_mainScreen.addDrawableObject(m_player);

    m_mainScreen.addDrawableObject(std::make_shared<Wall>(size.second - 1, 1, 0, 0));
    m_mainScreen.addDrawableObject(std::make_shared<Wall>(size.second - 1, 1, 0, size.first - 1));
    m_mainScreen.addDrawableObject(std::make_shared<Wall>(1, size.first - 1, 0, 0));
    m_mainScreen.addDrawableObject(std::make_shared<Wall>(1, size.first - 1, size.second - 1, 0));

    int shipCount = (size.second - 2) / 12;
    for(int i = 5; i < size.first / 2; i += 3) {
        for(int j = 0; j < shipCount; j++) {
            auto object = std::make_shared<Enemy>(j * 12 + 3, i, 5);
            m_gameElements.push_back(object);
            m_mainScreen.addDrawableObject(object);
        }
    }
}

int App::run() {
    using namespace std::chrono_literals;

    m_inputHandler->start();

    while(m_inputHandler->isRunning.load()) {
        m_mainScreen.clear();

        std::this_thread::sleep_for(100ms);

        m_mainScreen.update();

        m_mainScreen.draw();
    }

    m_inputHandler->stop();

    return 0;
}
