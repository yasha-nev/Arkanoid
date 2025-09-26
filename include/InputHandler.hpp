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

/**
 * @brief Class managing global input keyboard events and distributing them to subscribed observers.
 *
 * Collects input events and notifies subscribers when appropriate.
 */
class InputHandler {
public:
    /**
     * @brief Atomic flag determining whether the handler thread is actively listening.
     */
    std::atomic<bool> isRunning;

    /**
     * @brief Constructor initializes internal structures.
     */
    explicit InputHandler();

    /**
     * @brief Destructor ensures proper shutdown of background threads.
     */
    ~InputHandler();

    /**
     * @brief Begins listening for input events.
     *
     * Spawns a dedicated thread to monitor keyboard activity.
     */
    void start();

    /**
     * @brief Gracefully terminates input monitoring activities.
     *
     * Waits for any pending operations before finalizing.
     */
    void stop();

    /**
     * @brief Registers an observer interested in key press events.
     *
     * Ensures the observer receives notifications about key presses.
     *
     * @param observer Shared pointer to the observer instance.
     */
    void subscribe(const std::shared_ptr<IInputObserver>& observer);

    /**
     * @brief Deregisters a previously subscribed observer.
     *
     * Prevents the observer from receiving further key press notifications.
     *
     * @param observer Shared pointer to the observer instance.
     */
    void unsubscribe(const std::shared_ptr<IInputObserver>& observer);

    /**
     * @brief Detaches all currently subscribed observers.
     *
     * Completely clears the list of observers.
     */
    void unsubscribeAll();

private:
    /**
     * @brief Continually monitors input events and processes detected key presses.
     *
     * Runs inside a separate thread and calls notification methods appropriately.
     */
    void listenForEvents();

    /**
     * @brief Process an individual key press event.
     *
     * Takes action based on the specific key code received.
     *
     * @param keyCode Code identifying the pressed key.
     */
    void processKeyEvent(int keyCode);

    /**
     * @brief Notifies all subscribed observers about a key press event.
     *
     * Loops through all attached observers and invokes their callback method.
     *
     * @param keyCode Code identifying the pressed key.
     */
    void notifyObservers(int keyCode);

    /**
     * @brief Mutex guarding concurrent access to observer collection.
     */
    std::mutex m_mtx;

    /**
     * @brief Thread performing asynchronous input monitoring.
     */
    std::thread m_thread;

    /**
     * @brief Collection of subscribed observers awaiting key press notifications.
     */
    std::list<std::shared_ptr<IInputObserver>> m_observers;
};

#endif // INPUTHANDLER_hpp
