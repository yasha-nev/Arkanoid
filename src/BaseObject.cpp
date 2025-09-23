#include <BaseObject.hpp>

BaseObject::BaseObject() {
    m_color = Color::DEFAULT;
    m_isDead = false;
    m_size = std::pair<int, int>(0, 0);
    m_position = std::pair<int, int>(0, 0);
}

BaseObject::BaseObject(int width, int height, int x, int y, char drawSymbol) {
    m_color = Color::DEFAULT;
    m_isDead = false;
    m_size = std::pair<int, int>(width, height);
    m_position = std::pair<int, int>(x, y);
    m_drawSymbol = drawSymbol;
}

std::pair<int, int> BaseObject::getSize() const {
    return m_size;
}

std::pair<int, int> BaseObject::getPosition() const {
    return m_position;
}

char BaseObject::getDrawSymbol() {
    return m_drawSymbol;
}

bool BaseObject::getDeadStatus() {
    return m_isDead;
}

Color BaseObject::getColor() {
    return m_color;
}

void BaseObject::setPosition(int x, int y) {
    m_position.first = x;
    m_position.second = y;
}

void BaseObject::setPosition(const std::pair<int, int>& position) {
    m_position.first = position.first;
    m_position.second = position.second;
}

void BaseObject::setDrawSymbol(char drawSymbol) {
    m_drawSymbol = drawSymbol;
}

void BaseObject::setColor(Color color) {
    m_color = color;
}
