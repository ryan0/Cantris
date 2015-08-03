//
// Created by Ryan on 8/2/2015.
//

#include "System/GameWindow.hpp"


void GameWindow::makeLetterBox(sf::Vector2f viewSize) {
    float resRatio = (float)getSize().x / (float)getSize().y;
    float viewRatio = viewSize.x / viewSize.y;

    sf::View camera(sf::FloatRect(0, 0, viewSize.x, viewSize.y));
    if(resRatio > viewRatio) {
        camera.setViewport(sf::FloatRect((1.0f - viewRatio / resRatio) * .5f, 0.0f, viewRatio / resRatio, 1.0f));
    }
    else {
        camera.setViewport(sf::FloatRect(0.0f, (1.0f - resRatio / viewRatio) * .5f, 1.0f, resRatio / viewRatio));
    }
    setView(camera);
}
