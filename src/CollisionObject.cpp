#include "CollisionObject.hpp"

CollisionObject::CollisionObject(int width, int height, int x, int y, char symbol):
    BaseObject(width, height, x, y, symbol) {
}

bool CollisionObject::collidesWith(const std::shared_ptr<CollisionObject>& other) const {
    return (
        m_position.first > other->m_position.first - 1 &&
        m_position.first < other->m_position.first + other->m_size.first + 1 &&
        m_position.second > other->m_position.second - 1 &&
        m_position.second < other->m_position.second + other->m_size.second + 1);
}
