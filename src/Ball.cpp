#include "Ball.hpp"
#include <iostream>

Ball::Ball(int x, int y) : 
    DrawableObject(BALL_WIDTH, BALL_HEIGHT, x, y, '@'),
    CollisionObject(BALL_WIDTH, BALL_HEIGHT, x, y) {
    
    m_isMoved = true;

    m_lastPosX = x;
    m_lastPosY = y - 1;

    m_defaultPosX = x;
    m_defaultPosY = y;

    m_derectionX = 1;
    m_derectionY = 1;
}

void Ball::updateMove() {
    if (!m_isMoved) {
        return;
    }
    m_position.first -= m_derectionX;
    m_position.second -= m_derectionY;

    m_x = m_position.first;
    m_y = m_position.second;
}

void Ball::startMove() {
    m_isMoved = true;
}

void Ball::setDefaultPosition() {
    m_position.first = m_defaultPosX;
    m_position.second = m_defaultPosY;

    m_lastPosX = m_defaultPosX;
    m_lastPosY = m_defaultPosY - 1;
}
void Ball::onKeyPressed(int keyCode) {
    if (keyCode == 'w') {
        startMove();
    }
}

struct Point {
    float x, y;
};


static float dotProduct(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

static Point calculateNormal(Point p1, Point p2) {
    return {p2.y - p1.y, -(p2.x - p1.x)};
}

static bool lineIntersection(Point A, Point B, Point C, Point D, Point& intersection) {
    // Уравнения линий AB и CD, проверка пересечения
    float det = (A.x - B.x)*(C.y - D.y) - (A.y - B.y)*(C.x - D.x);
    if(det == 0) return false;

    float t = ((A.x-C.x)*(C.y-D.y)-(A.y-C.y)*(C.x-D.x)) / det;
    float u = -((A.x-B.x)*(A.y-C.y)-(A.y-B.y)*(A.x-C.x)) / det;

    if(t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        intersection.x = A.x + t*(B.x-A.x);
        intersection.y = A.y + t*(B.y-A.y);
        return true;
    }
    return false;
}

static void updateVelocityAfterCollision(Point vel, Point normal, Point& newVel) {
    float proj = dotProduct(normal, vel);
    newVel.x = vel.x - 2 * proj * normal.x;
    newVel.y = vel.y - 2 * proj * normal.y;
}

void Ball::handleCollision(const CollisionObject *object) {
    setDrawSymbol('1');

    Point intersect;
    bool foundIntersection = false;
    int sideIndex = -1;

    Point ballPosition = {(float) m_position.first, (float) m_position.second};
    Point lastPosition = {(float) m_lastPosX, (float) m_lastPosY};

    Point trajectoryStart = lastPosition;
    Point trajectoryEnd = ballPosition;

    Point wallVertices[] = {{(float) object->m_x, (float) object->m_y},
                            {(float) object->m_x + (float) object->m_width, (float) object->m_y},
                            {(float) object->m_x + (float) object->m_width, (float) object->m_y + (float) object->m_height}, 
                            {(float) object->m_x, (float) object->m_y + (float) object->m_height}};

    for(int i=0; i<4; ++i) {
        Point sideStart = wallVertices[i];
        Point sideEnd = wallVertices[(i+1)%4];

        if(lineIntersection(trajectoryStart, trajectoryEnd, sideStart, sideEnd, intersect)) {
            foundIntersection = true;
            sideIndex = i;
            break;
        }
    }

    if(foundIntersection) {
        // Получаем нормаль стороны
        Point normal = calculateNormal(wallVertices[sideIndex], wallVertices[(sideIndex+1)%4]);

        // Нормализуем вектор нормали
        float len = sqrt(dotProduct(normal, normal));
        normal.x /= len;
        normal.y /= len;

        // Скорость мяча
        Point velocity = {trajectoryEnd.x-trajectoryStart.x, trajectoryEnd.y-trajectoryStart.y};

        // Новый вектор скорости после столкновения
        Point newVelocity;
        updateVelocityAfterCollision(velocity, normal, newVelocity);

        m_derectionX = velocity.x;
        m_derectionY = velocity.y;
    }
}