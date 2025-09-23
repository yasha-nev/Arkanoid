#ifndef INPUTHANDLER_hpp
#define INPUTHANDLER_hpp

#include "IInputObserver.hpp"

#include <atomic>
#include <cstdlib>
#include <list>
#include <memory>
#include <mutex>
#include <termios.h>
#include <thread>
#include <unistd.h>

class InputHandler {
public:
    std::atomic<bool> isRunning;

    explicit InputHandler();

    ~InputHandler();

    void start();

    void stop();

    void subscribe(const std::shared_ptr<IInputObserver>& observer);

    void unsubscribe(const std::shared_ptr<IInputObserver>& observer);

    void unsubscribeAll();

private:
    void listenForEvents();

    void processKeyEvent(int keyCode);

    void notifyObservers(int keyCode);

    std::mutex m_mtx;

    std::thread m_thread;

    std::list<std::shared_ptr<IInputObserver>> m_observers;
};

#endif
