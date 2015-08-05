//
// Created by Ryan on 8/5/2015.
//

#ifndef RAINSFORD_VECMESSAGE_HPP
#define RAINSFORD_VECMESSAGE_HPP

#include <SFML/Graphics.hpp>

#include "Message.hpp"

class VecMessage : public Message {
public:
    VecMessage(Message_ID id, sf::Vector2f vec);
    sf::Vector2f getData();

private:
    sf::Vector2f data;
};

#endif //RAINSFORD_VECMESSAGE_HPP
