//
// Created by Ryan on 5/26/2016.
//

#include "Gui/StringSelector.hpp"

void StringSelector::setStringList(std::vector<std::string> strings) {
    stringList = strings;
    currentStringId = 0;

    for (int i = 0; i < stringList.size(); i++) {
        sf::Text text;
        text.setString(stringList[i]);
        text.setCharacterSize(20);
        text.setColor(sf::Color::White);
        text.move(0, i * 25);
        textList.push_back(text);
    }
    textList[currentStringId].setColor(sf::Color::Blue);
}

void StringSelector::setFont(sf::Font& font) {
    for (int i = 0; i < textList.size(); i++) {
        textList[i].setFont(font);
    }
}

void StringSelector::selectedUp() {
    textList[currentStringId].setColor(sf::Color::White);
    currentStringId--;
    if(currentStringId < 0) currentStringId = stringList.size() - 1;
    textList[currentStringId].setColor(sf::Color::Blue);
}

void StringSelector::selectedDown() {
    textList[currentStringId].setColor(sf::Color::White);
    currentStringId++;
    if(currentStringId >= stringList.size()) currentStringId = 0;
    textList[currentStringId].setColor(sf::Color::Blue);
}

std::string StringSelector::getCurrentSelection() {
    return stringList[currentStringId];
}

void StringSelector::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0; i < textList.size(); i++) {
        states.transform *= getTransform();
        target.draw(textList[i], states.transform);
    }
}