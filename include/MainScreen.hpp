#ifndef MAINSCREEN_hpp
#define MAINSCREEN_hpp

#include "BaseObject.hpp"

#include <list>
#include <memory>
#include <string>
#include <termios.h>
#include <utility>
#include <vector>

/**
 * @brief Structure describing a single tile on the game screen.
 *
 * Contains information about the tile's color, drawable symbol, and reset sequence.
 */
struct Tile {
    char color[6]; ///< ASCII escape sequence for coloring the tile.
    char symboll; ///< Character displayed on the tile.
    char reset[5]; ///< Sequence to restore normal color after drawing.
};

/**
 * @brief Primary graphics component responsible for rendering and updating the game window.
 *
 * Maintains the visual representation of the game scene.
 */
class MainScreen {
public:
    /**
     * @brief Default constructor initializing the screen buffer and related settings.
     */
    MainScreen();

    /**
     * @brief Destructor restoring original terminal configurations.
     */
    ~MainScreen();

    /**
     * @brief Erases all content from the screen buffer.
     *
     * Prepares the canvas for redrawing.
     */
    void clear();

    /**
     * @brief Draws all objects onto the screen.
     *
     * Renders every object in the scene.
     */
    void draw();

    /**
     * @brief Refreshes the screen contents.
     *
     * Updates the screen map according to changes made since last call.
     */
    void update();

    /**
     * @brief Adds a new object to the screen for rendering purposes.
     *
     * Incorporates the object into the drawing pipeline.
     *
     * @param object Shared pointer to the object to be added.
     */
    void addBaseObject(const std::shared_ptr<BaseObject>& object);

    /**
     * @brief Removes an object from the screen.
     *
     * Excludes the object from subsequent drawing cycles.
     *
     * @param object Shared pointer to the object to be removed.
     */
    void removeBaseObject(const std::shared_ptr<BaseObject>& object);

    /**
     * @brief Queries the dimensions of the game screen.
     *
     * @return Pair of integers denoting screen width and height.
     */
    std::pair<int, int> getScreenSize();

private:
    /**
     * @brief Draws a single object onto the screen.
     *
     * Applies the object's visual properties to the internal map.
     *
     * @param object Pointer to the object being drawn.
     */
    void drawObject(BaseObject* object);

    /**
     * @brief Terminal configuration backup prior to modification.
     */
    struct termios m_oldt;

    /**
     * @brief Collection of objects present on the screen.
     */
    std::list<std::shared_ptr<BaseObject>> m_objects;

    /**
     * @brief Two-dimensional array mapping tiles to their visual representations.
     */
    std::vector<Tile> m_map;

    /**
     * @brief Size of the screen (width, height).
     */
    std::pair<int, int> m_size;
};

#endif // MAINSCREEN_hpp
