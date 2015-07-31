//
// Created by Ryan on 7/31/2015.
//

#ifndef RAINSFORD_STARTMENU_HPP
#define RAINSFORD_STARTMENU_HPP

#include "EngineState.hpp"
#include "Engine.hpp"

class StartMenu : public EngineState {
public:
    virtual void update(float tpf) override;
    virtual void render(sf::RenderTarget &target) override;
    virtual void initialize(Engine &engine) override;
    virtual void cleanup() override;

private:

};


#endif //RAINSFORD_STARTMENU_HPP
