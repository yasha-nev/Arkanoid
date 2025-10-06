#include <App.hpp>
#include <iostream>

int main() {
    try {
        App().run();
    } catch(const std::exception& ex) {
        std::cerr << "Error " << ex.what() << "\n";
    }
    return 0;
}
