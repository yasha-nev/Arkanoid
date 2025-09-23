#include "MainScreen.hpp"

#include <sys/ioctl.h>

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unistd.h>

MainScreen::MainScreen() {
    struct termios newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    printf("\033[2J\033[H\033[?25l");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    m_size = std::pair<int, int>(w.ws_row - 1, w.ws_col);
    m_map.resize(m_size.first * m_size.second);

    clear();
}

MainScreen::~MainScreen() {
    printf("\033[?25h");
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\033[H");

    m_objects.clear();
}

void MainScreen::clear() {
    for(int i = 0; i < m_size.first; i++) {
        for(int j = 0; j < m_size.second; j++) {
            memcpy(m_map[i * m_size.second + j].color, WHITE, sizeof(char) * 6);
            m_map[i * m_size.second + j].symboll = ' ';
            memcpy(m_map[i * m_size.second + j].reset, RESET, sizeof(char) * 5);
        }

        memcpy(m_map[i * m_size.second + m_size.second - 1].color, WHITE, sizeof(char) * 6);
        m_map[i * m_size.second + m_size.second - 1].symboll = '\n';
        memcpy(m_map[i * m_size.second + m_size.second - 1].reset, RESET, sizeof(char) * 5);
    }
    printf("\033[H");
}

std::pair<int, int> MainScreen::getScreenSize() {
    return m_size;
}

void MainScreen::draw() {
    write(STDOUT_FILENO, m_map.data(), m_map.size() * sizeof(struct Tile));
}

void MainScreen::update() {
    for(const auto& object: m_objects) {
        drawObject(object.get());
    }
}

void MainScreen::addBaseObject(const std::shared_ptr<BaseObject>& object) {
    m_objects.push_back(object);
}

void MainScreen::removeBaseObject(const std::shared_ptr<BaseObject>& object) {
    auto it = std::find(m_objects.begin(), m_objects.end(), object);
    if(it != m_objects.end()) {
        m_objects.erase(it);
    }
}

void MainScreen::drawObject(BaseObject* object) {
    auto position = object->getPosition();
    auto size = object->getSize();
    auto drawSymbol = object->getDrawSymbol();

    for(int i = position->second; i < position->second + size->second && i < m_size.first; i++) {
        for(int j = position->first; j < (position->first + size->first) && j < m_size.second;
            j++) {
            switch(object->getColor()) {
                case Color::DEFAULT:
                    memcpy(m_map[i * m_size.second + j].color, WHITE, sizeof(char) * 6);
                    break;
                case Color::RED_COLOR:
                    memcpy(m_map[i * m_size.second + j].color, RED, sizeof(char) * 6);
                    break;
                case Color::GREEN_COLOR:
                    memcpy(m_map[i * m_size.second + j].color, GREEN, sizeof(char) * 6);
                    break;
                case Color::BLUE_COLOR:
                    memcpy(m_map[i * m_size.second + j].color, BLUE, sizeof(char) * 6);
                    break;
                case Color::YELLOW_COLOR:
                    memcpy(m_map[i * m_size.second + j].color, YELLOW, sizeof(char) * 6);
                    break;
                case Color::CYAN_COLOR:
                    memcpy(m_map[i * m_size.second + j].color, CYAN, sizeof(char) * 6);
                    break;
                case Color::PURPLE_COLOR:
                    memcpy(m_map[i * m_size.second + j].color, PURPLE, sizeof(char) * 6);
                    break;
                default:
                    memcpy(m_map[i * m_size.second + j].color, WHITE, sizeof(char) * 6);
                    break;
            }
            m_map[i * m_size.second + j].symboll = drawSymbol;
            memcpy(m_map[i * m_size.second + j].reset, RESET, sizeof(char) * 5);
        }
    }
}
