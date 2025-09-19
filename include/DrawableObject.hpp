#ifndef DRAWABLEOBJECT_hpp
#define DRAWABLEOBJECT_hpp

#include <utility>

class DrawableObject {
public:
    DrawableObject();

    DrawableObject(int width, int height, int x, int y, char drawSymbol);

    std::pair<int, int>* getSize();

    std::pair<int, int>* getPosition();

    char getDrawSymbol();

    void setPosition(int x, int y);

    void setPosition(const std::pair<int, int>& position);

    void setDrawSymbol(char drawSymbol);

protected:
    std::pair<int, int> m_size;
    std::pair<int, int> m_position;
    char m_drawSymbol;
};

#endif
