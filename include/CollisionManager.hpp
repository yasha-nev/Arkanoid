#ifndef COLLISIONMANAGER_hpp
#define COLLISIONMANAGER_hpp

#include "CollisionObject.hpp"

#include <memory>
#include <list>

/**
 * @brief Central manager for detecting and responding to collisions between game objects.
 *
 * Keeps track of all collidable objects and performs pairwise collision tests during each iteration.
 */
class CollisionManager {
public:
    /**
     * @brief Destructor cleaning up managed resources.
     */
    ~CollisionManager();

    /**
     * @brief Adds a new collision object into the tracking list.
     *
     * Registers the given object so that future collision checks will include it.
     *
     * @param object Smart pointer to the collision object to be added.
     */
    void addCollisionObject(const std::shared_ptr<CollisionObject>& object);

    /**
     * @brief Removes a previously registered collision object.
     *
     * Unregisters the given object from further collision testing.
     *
     * @param object Smart pointer to the collision object to be removed.
     */
    void removeObject(const std::shared_ptr<CollisionObject>& object);

    /**
     * @brief Executes collision detection process over all tracked objects.
     *
     * Iterates through pairs of objects, calling their respective collision handlers upon overlaps.
     */
    void checkCollisions();

private:
    /**
     * @brief Internal storage of all active collision objects.
     */
    std::list<std::shared_ptr<CollisionObject>> m_objects;
};

#endif //COLLISIONMANAGER_hpp
