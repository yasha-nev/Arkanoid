#ifndef BASEOBJECT_hpp
#define BASEOBJECT_hpp

#include "Colors.hpp"

#include <utility>

class BaseObject {
public:
    BaseObject();

    BaseObject(int width, int height, int x, int y, char drawSymbol);

    virtual ~BaseObject() = default;

    std::pair<int, int>* getSize();

    std::pair<int, int>* getPosition();

    char getDrawSymbol();

    bool getDeadStatus();

    Color getColor();

    void setPosition(int x, int y);

    void setPosition(const std::pair<int, int>& position);

    void setDrawSymbol(char drawSymbol);

    void setColor(Color color);

protected:
    Color m_color;
    bool m_isDead;
    std::pair<int, int> m_size;
    std::pair<int, int> m_position;
    char m_drawSymbol;
};

#endif
