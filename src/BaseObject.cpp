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

std::pair<int, int> BaseObject::getSize() const noexcept {
    return m_size;
}

std::pair<int, int> BaseObject::getPosition() const noexcept {
    return m_position;
}

char BaseObject::getDrawSymbol() const noexcept {
    return m_drawSymbol;
}

bool BaseObject::getDeadStatus() const noexcept {
    return m_isDead;
}

Color BaseObject::getColor() const noexcept {
    return m_color;
}

void BaseObject::setPosition(int x, int y) noexcept {
    m_position.first = x;
    m_position.second = y;
}

void BaseObject::setPosition(const std::pair<int, int>& position) noexcept {
    m_position.first = position.first;
    m_position.second = position.second;
}

void BaseObject::setDrawSymbol(char drawSymbol) noexcept {
    m_drawSymbol = drawSymbol;
}

void BaseObject::setColor(Color color) noexcept {
    m_color = color;
}
