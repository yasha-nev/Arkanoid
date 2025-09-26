#ifndef BASEOBJECT_hpp
#define BASEOBJECT_hpp

#include "Colors.hpp"

#include <utility>

/**
 * @brief Abstract base class representing generic game objects.
 *
 * Provides common functionality such as size, position, drawing symbol and object color.
 */
class BaseObject {
public:
    /**
     * @brief Default constructor initializing minimal object properties.
     */
    BaseObject();

    /**
     * @brief Constructor accepting initial dimensions and position.
     *
     * @param width Width of the object.
     * @param height Height of the object.
     * @param x X-coordinate of object's top-left corner.
     * @param y Y-coordinate of object's top-left corner.
     * @param drawSymbol Character used to render the object visually.
     */
    BaseObject(int width, int height, int x, int y, char drawSymbol);

    /**
     * @brief Virtual destructor to ensure proper cleanup when subclassing.
     */
    virtual ~BaseObject() = default;

    /**
     * @brief Retrieves the size of the object (width and height).
     *
     * @return Pair containing width and height.
     */
    std::pair<int, int> getSize() const;

    /**
     * @brief Obtains the current position coordinates (X,Y) top-left corner of the object.
     *
     * @return Pair holding the X and Y positions.
     */
    std::pair<int, int> getPosition() const;

    /**
     * @brief Gets the character symbol used to represent the object graphically.
     *
     * @return Symbol drawn on-screen.
     */
    char getDrawSymbol();

    /**
     * @brief Checks if the object is marked as dead/deleted.
     *
     * @return True if the object should be considered inactive/dead.
     */
    bool getDeadStatus();

    /**
     * @brief Returns the assigned color attribute of the object.
     *
     * @return Current color setting.
     */
    Color getColor();

    /**
     * @brief Resets the object's position based on provided X and Y values.
     *
     * @param x New horizontal coordinate.
     * @param y New vertical coordinate.
     */
    void setPosition(int x, int y);

    /**
     * @brief Changes the object's position via a pair of coordinates.
     *
     * @param position Pair specifying both X and Y coordinates.
     */
    void setPosition(const std::pair<int, int>& position);

    /**
     * @brief Assigns a new graphic representation symbol for the object.
     *
     * @param drawSymbol New display character.
     */
    void setDrawSymbol(char drawSymbol);

    /**
     * @brief Alters the color property of the object.
     *
     * @param color New color assignment.
     */
    void setColor(Color color);

protected:
    /**
     * @brief Stores the visual color of the object.
     */
    Color m_color;

    /**
     * @brief Indicates whether the object is logically removed ('dead').
     */
    bool m_isDead;

    /**
     * @brief Dimensions (width & height) of the object.
     */
    std::pair<int, int> m_size;

    /**
     * @brief Positional coordinates (top-left point) of the object.
     */
    std::pair<int, int> m_position;

    /**
     * @brief Graphic representation symbol used for rendering.
     */
    char m_drawSymbol;
};

#endif // BASEOBJECT_hpp
