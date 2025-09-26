#ifndef IINPUTOBSERVER_hpp
#define IINPUTOBSERVER_hpp

/**
 * @brief Interface for receiving notifications about key press events.
 *
 * Subscribers implement this interface to receive key-press callbacks.
 */
class IInputObserver {
public:
    /**
     * @brief Virtual destructor allowing safe deletion of derived observers.
     */
    virtual ~IInputObserver() = default;

    /**
     * @brief Callback invoked whenever a key is pressed.
     *
     * Implementations can react accordingly to specific keys.
     *
     * @param keyCode Key identifier corresponding to the pressed button.
     */
    virtual void onKeyPressed(int keyCode) = 0;
};

#endif // IINPUTOBSERVER_hpp
