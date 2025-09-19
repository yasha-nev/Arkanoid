#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int level):
    DrawableObject(ENEMY_WIDTH, ENEMY_HEIGHT, x, y, '0' + level),
    CollisionObject(ENEMY_WIDTH, ENEMY_HEIGHT, x, y),
    m_level(level) {
}

void Enemy::makeHit() {
    if(m_level <= 0) {
        return;
    }

    m_level--;

    if(m_level == 0) {
        destroy();

    } else {
        setDrawSymbol('0' + m_level);
    }
}

void Enemy::destroy() {
    setDrawSymbol(' ');
}

void Enemy::handleCollision(const CollisionObject * object) {
    makeHit();
}