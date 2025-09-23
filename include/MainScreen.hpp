#ifndef MAINSCREEN_hpp
#define MAINSCREEN_hpp

#include "BaseObject.hpp"

#include <list>
#include <memory>
#include <string>
#include <termios.h>
#include <utility>
#include <vector>

struct Tile {
    char color[6];
    char symboll;
    char reset[5];
};

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

    struct termios m_oldt;

    std::list<std::shared_ptr<BaseObject>> m_objects;

    std::vector<Tile> m_map;

    std::pair<int, int> m_size;
};

#endif
