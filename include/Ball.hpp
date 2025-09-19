#ifndef BALL_hpp
#define BALL_hpp

#include "DrawableObject.hpp"
#include "IInputObserver.hpp"
#include "CollisionObject.hpp"

#include <mutex>
#include <cmath>
#define BALL_WIDTH 1
#define BALL_HEIGHT 1


class Ball: public DrawableObject, public CollisionObject, public IInputObserver {
public:
    Ball(int x, int y);

    void updateMove();

    void startMove();

    void setDefaultPosition();

    // IInputObserver method
    void onKeyPressed(int keyCode) override;

    //CollisionObject method
    void handleCollision(const CollisionObject *object) override;

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
