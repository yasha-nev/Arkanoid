#ifndef IINPUTOBSERVER_hpp
#define IINPUTOBSERVER_hpp

class IInputObserver {
public:
    virtual ~IInputObserver() = default;

    virtual void onKeyPressed(int keyCode) = 0;
};

#endif
