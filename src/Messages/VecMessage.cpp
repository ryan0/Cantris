//
// Created by Ryan on 8/5/2015.
//

#include "Messages/VecMessage.hpp"

VecMessage::VecMessage(Message_ID id, sf::Vector2f vec)
        : Message(id),
          data(vec)
{}

sf::Vector2f VecMessage::getData() {
    return data;
}
