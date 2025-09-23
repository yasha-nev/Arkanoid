#ifndef GAMEMANAGER_hpp
#define GAMEMANAGER_hpp

#include "IInputObserver.hpp"

class App;

class GameStarter: public IInputObserver {
public:
    GameStarter(App& app);

    // IInputObserver method
    void onKeyPressed(int keyCode) override;

private:
    App& m_app;
};

#endif
