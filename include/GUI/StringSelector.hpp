//
// Created by Ryan on 5/26/2016.
//

#ifndef RAINSFORD_STRINGSELECTOR_HPP
#define RAINSFORD_STRINGSELECTOR_HPP

#include <SFML/Graphics.hpp>

class StringSelector : public sf::Drawable, public sf::Transformable {
public:
    void setStringList(std::vector<std::string> strings);
    void setFont(sf::Font& font);
    std::string getCurrentSelection();
    void selectedUp();
    void selectedDown();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::vector<std::string> stringList;
    int currentStringId;

    std::vector<sf::Text> textList;
    sf::Font font;

};

#endif //RAINSFORD_STRINGSELECTOR_HPP
