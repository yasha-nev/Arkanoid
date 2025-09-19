#include <CollisionManager.hpp>

CollisionManager::~CollisionManager() {
    m_objects.clear();
}

void CollisionManager::addCollisionObject(const std::shared_ptr<CollisionObject> &object) {
    m_objects.push_back(object);
}

void CollisionManager::removeObject(const std::shared_ptr<CollisionObject> &object) {

    auto it = std::find(m_objects.begin(), m_objects.end(), object);
    if(it != m_objects.end()) {
        m_objects.erase(it);
    }
}

void CollisionManager::checkCollisions() {
    size_t n = m_objects.size();
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = i+1; j < n; ++j) {
            if(m_objects[i]->collidesWith(m_objects[j].get())) {
                m_objects[i]->handleCollision(m_objects[j].get());
                m_objects[j]->handleCollision(m_objects[i].get());
            }
        }
    }
}