#ifndef MAINSCREEN_hpp
#define MAINSCREEN_hpp

#include "DrawableObject.hpp"

#include <algorithm>
#include <list>
#include <memory>
#include <termios.h>
#include <utility>
#include <vector>

class MainScreen {
public:
    MainScreen();

    ~MainScreen();

    void clear();

    void draw();

    void update();

    void addDrawableObject(const std::shared_ptr<DrawableObject>& object);

    void removeDrawableObject(const std::shared_ptr<DrawableObject>& object);

    std::pair<int, int> getScreenSize();

private:
    void drawObject(DrawableObject* object);

    struct termios oldt;

    std::list<std::shared_ptr<DrawableObject>> m_objects;

    std::vector<char> m_map;

    std::pair<int, int> m_size;
};

#endif
