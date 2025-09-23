#include "InputHandler.hpp"

#include <algorithm>

InputHandler::InputHandler() {
}

InputHandler::~InputHandler() {
    stop();
    m_observers.clear();
}

void InputHandler::start() {
    isRunning.store(true);
    m_thread = std::thread([this]() { this->listenForEvents(); });
}

void InputHandler::stop() {
    isRunning.store(false);
    if(m_thread.joinable()) {
        m_thread.join();
    }
}

static bool kbhit() {
    struct timeval tv = { 0, 0 };
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    select(STDIN_FILENO + 1, &readfds, nullptr, nullptr, &tv);
    return FD_ISSET(STDIN_FILENO, &readfds);
}

void InputHandler::listenForEvents() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while(isRunning.load()) {
        if(kbhit()) {
            std::lock_guard<std::mutex> lock(m_mtx);
            int ch = getchar();
            processKeyEvent(ch);
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void InputHandler::processKeyEvent(int keyCode) {
    if(keyCode == 'q') {
        isRunning.store(false);
    }

    notifyObservers(keyCode);
}

void InputHandler::notifyObservers(int keyCode) {
    for(auto& observer: m_observers) {
        observer->onKeyPressed(keyCode);
    }
}

void InputHandler::subscribe(const std::shared_ptr<IInputObserver>& observer) {
    std::lock_guard<std::mutex> lock(m_mtx);
    m_observers.push_back(observer);
}

void InputHandler::unsubscribe(const std::shared_ptr<IInputObserver>& observer) {
    std::lock_guard<std::mutex> lock(m_mtx);
    auto it = std::find(m_observers.begin(), m_observers.end(), observer);
    if(it != m_observers.end()) {
        m_observers.erase(it);
    }
}

void InputHandler::unsubscribeAll() {
    m_observers.clear();
}
