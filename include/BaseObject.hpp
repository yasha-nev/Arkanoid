#ifndef BASEOBJECT_hpp
#define BASEOBJECT_hpp

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

    void setPosition(int x, int y);

    void setPosition(const std::pair<int, int>& position);

    void setDrawSymbol(char drawSymbol);

protected:
    bool m_isDead;
    std::pair<int, int> m_size;
    std::pair<int, int> m_position;
    char m_drawSymbol;
};

#endif
