#ifndef MAINSCREEN_hpp
#define MAINSCREEN_hpp

#include "BaseObject.hpp"

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

    void addBaseObject(const std::shared_ptr<BaseObject>& object);

    void removeBaseObject(const std::shared_ptr<BaseObject>& object);

    std::pair<int, int> getScreenSize();

private:
    void drawObject(BaseObject* object);

    struct termios oldt;

    std::list<std::shared_ptr<BaseObject>> m_objects;

    std::vector<char> m_map;

    std::pair<int, int> m_size;
};

#endif
