#include <DrawableObject.hpp>

DrawableObject::DrawableObject() {
    m_size = std::pair<int, int>(0, 0);
    m_position = std::pair<int, int>(0, 0);
}

DrawableObject::DrawableObject(int width, int height, int x, int y, char drawSymbol) {
    m_size = std::pair<int, int>(width, height);
    m_position = std::pair<int, int>(x, y);
    m_drawSymbol = drawSymbol;
}

std::pair<int, int>* DrawableObject::getSize() {
    return &m_size;
}

std::pair<int, int>* DrawableObject::getPosition() {
    return &m_position;
}

char DrawableObject::getDrawSymbol() {
    return m_drawSymbol;
}

void DrawableObject::setPosition(int x, int y) {
    m_position.first = x;
    m_position.second = y;
}

void DrawableObject::setPosition(const std::pair<int, int>& position) {
    m_position.first = position.first;
    m_position.second = position.second;
}

void DrawableObject::setDrawSymbol(char drawSymbol) {
    m_drawSymbol = drawSymbol;
}
