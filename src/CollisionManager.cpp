#include "CollisionManager.hpp"

#include <algorithm>

CollisionManager::~CollisionManager() {
    m_objects.clear();
}

void CollisionManager::addCollisionObject(const std::shared_ptr<CollisionObject>& object) {
    m_objects.push_back(object);
}

void CollisionManager::removeObject(const std::shared_ptr<CollisionObject>& object) {

    auto it = std::find(m_objects.begin(), m_objects.end(), object);
    if(it != m_objects.end()) {
        m_objects.erase(it);
    }
}

void CollisionManager::checkCollisions() {

    auto begin = m_objects.cbegin();
    auto end = m_objects.cend();

    for (auto iti = begin; iti != end; iti++) {
        auto nextIt = std::next(iti);
        for (auto itj = nextIt; itj != end; itj++) {
            if ((*iti)->collidesWith(*itj)) {
                (*iti)->handleCollision(*itj);
                (*itj)->handleCollision(*iti);
            }
        }
    }
}
