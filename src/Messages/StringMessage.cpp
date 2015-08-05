//
// Created by Ryan on 8/5/2015.
//

#include "Messages/StringMessage.hpp"

StringMessage::StringMessage(Message_ID id, std::string stringData)
        : Message(id),
          data(stringData)
{}

std::string StringMessage::getData() {
    return data;
}
