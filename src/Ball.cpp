#include "Ball.hpp"

#include <algorithm>
#include <cmath>

Ball::Ball(int x, int y):
    CollisionObject(BALL_WIDTH, BALL_HEIGHT, x, y, '@') {

    m_isMoved = false;

    m_lastPosX = x;
    m_lastPosY = y - 1;

    m_defaultPosX = x;
    m_defaultPosY = y;

    m_derectionX = -1;
    m_derectionY = -1;
}

void Ball::updateMove() {
    if(!m_isMoved) {
        return;
    }

    m_lastPosX = m_position.first;
    m_lastPosY = m_position.second;

    m_position.first += m_derectionX;
    m_position.second += m_derectionY;
}

void Ball::startMove() {
    m_isMoved = true;
}

void Ball::stopMove() {
    m_isMoved = false;
}

void Ball::setDefaultPosition() {
    m_position.first = m_defaultPosX;
    m_position.second = m_defaultPosY;

    m_lastPosX = m_defaultPosX;
    m_lastPosY = m_defaultPosY - 1;
}

void Ball::handleCollision(const std::shared_ptr<CollisionObject>& obj) {
    auto [ox, oy] = obj->getPosition();
    auto [ow, oh] = obj->getSize();

    if(m_position.first >= ox && m_position.first <= ox + ow && m_position.second >= oy &&
       m_position.second <= oy + oh) {

        double overlapLeft = (m_position.first - ox);
        double overlapRight = (ox + ow - m_position.first);
        double overlapTop = (m_position.second - oy);
        double overlapBottom = (oy + oh - m_position.second);

        double minOverlap = std::min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

        if(minOverlap == overlapLeft) {
            m_derectionX = -fabs(m_derectionX);
        } else if(minOverlap == overlapRight) {
            m_derectionX = fabs(m_derectionX);
        } else if(minOverlap == overlapTop) {
            m_derectionY = -fabs(m_derectionY);
        } else if(minOverlap == overlapBottom) {
            m_derectionY = fabs(m_derectionY);
        }

        if(minOverlap == overlapLeft) {
            m_position.first = ox - 1e-6;
        } else if(minOverlap == overlapRight) {
            m_position.first = ox + ow + 1e-6;
        } else if(minOverlap == overlapTop) {
            m_position.second = oy - 1e-6;
        } else if(minOverlap == overlapBottom) {
            m_position.second = oy + oh + 1e-6;
        }
    }
}
