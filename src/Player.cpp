#include "Player.hpp"

Player::Player(int x, int y):
    CollisionObject(PLAYER_DEFAULT_WIDTH, PLAYER_DEFAULT_HEIGHT, x, y, '-') {
}

void Player::moveRight() {
    std::lock_guard<std::mutex> lock(m_mtx);
    m_position.first += 5;
}

void Player::moveLeft() {
    std::lock_guard<std::mutex> lock(m_mtx);
    m_position.first -= 5;
}

void Player::onKeyPressed(int keyCode) {
    switch(keyCode) {
        case 'a': {
            moveLeft();
            break;
        }
        case 'd': {
            moveRight();
            break;
        }
        default: {
            break;
        }
    }
}

void Player::handleCollision(CollisionObject* object) {
    (void) object;
}
