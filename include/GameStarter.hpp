#ifndef GAMEMANAGER_hpp
#define GAMEMANAGER_hpp

#include "IInputObserver.hpp"

class App;

/**
 * @brief Responsible for triggering the beginning of the game.
 *
 * Monitors input keywords events and acts as an entry point for initiating gameplay.
 */
class GameStarter: public IInputObserver {
public:
    /**
     * @brief Constructor injecting dependencies to the application context.
     *
     * Requires reference to the primary application controller.
     *
     * @param app Application instance driving overall game flow.
     */
    GameStarter(App& app);

    /**
     * @brief Receives notifications about key press events.
     *
     * Implements the required method from the IInputObserver interface to respond to input.
     *
     * @param keyCode Identifier of the pressed key.
     */
    void onKeyPressed(int keyCode) override;

private:
    /**
     * @brief Reference to the main application instance.
     */
    App& m_app;
};

#endif // GAMEMANAGER_hpp
