#ifndef BALL_hpp
#define BALL_hpp

#include "CollisionObject.hpp"
#include "IInputObserver.hpp"

#include <mutex>

#define BALL_WIDTH 1
#define BALL_HEIGHT 1

class Ball: public CollisionObject {
public:
    Ball(int x, int y);

    void updateMove();

    void startMove();

    void stopMove();

    void setDefaultPosition();

    // CollisionObject method
    void handleCollision(CollisionObject* object) override;

private:
    bool m_isMoved;

    int m_lastPosX;
    int m_lastPosY;

    int m_defaultPosX;
    int m_defaultPosY;

    float m_derectionX;
    float m_derectionY;

    std::mutex m_mtx;
};

#endif
