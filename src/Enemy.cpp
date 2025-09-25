#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int level):
    CollisionObject(ENEMY_WIDTH, ENEMY_HEIGHT, x, y, '0' + level),
    m_level(level) {
    updateColor();
}

void Enemy::makeHit() {
    if(m_level <= 0) {
        return;
    }

    m_level--;

    updateColor();

    if(m_level == 0) {
        m_isDead = true;
        setDrawSymbol(' ');
    } else {
        setDrawSymbol('0' + m_level);
    }
}

void Enemy::handleCollision(const std::shared_ptr<CollisionObject> &object) {
    (void) object;
    makeHit();
}

void Enemy::updateColor() {
    if(m_level >= MAX_LEVEL) {
        setColor(Color::RED_COLOR);
    } else if(m_level >= MAX_LEVEL - 1) {
        setColor(Color::YELLOW_COLOR);
    } else if(m_level >= MAX_LEVEL - 2) {
        setColor(Color::BLUE_COLOR);
    } else if(m_level >= MAX_LEVEL - 3) {
        setColor(Color::PURPLE_COLOR);
    } else if(m_level >= MAX_LEVEL - 4) {
        setColor(Color::GREEN_COLOR);
    } else {
        setColor(Color::CYAN_COLOR);
    }
}
