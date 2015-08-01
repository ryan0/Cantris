#include "System/Engine.hpp"
#include "GUI/StartMenu.hpp"

int main() {
    Engine engine;
    engine.setState(engineState_ptr(new StartMenu));
    engine.run();
    return 0;
}