#ifndef PLAYER_hpp
#define PLAYER_hpp

#include "CollisionObject.hpp"
#include "IInputObserver.hpp"

#include <mutex>

#define PLAYER_DEFAULT_WIDTH 20
#define PLAYER_DEFAULT_HEIGHT 1

class Player: public CollisionObject, public IInputObserver {
public:
    Player(int x, int y);

    void moveRight();

    void moveLeft();

    // IInputObserver method
    void onKeyPressed(int keyCode) override;

    // CollisionObject method
    void handleCollision(const CollisionObject* object) override;

private:
    std::mutex m_mtx;
};

#endif
