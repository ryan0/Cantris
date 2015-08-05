//
// Created by Ryan on 8/5/2015.
//

#ifndef RAINSFORD_STRINGMESSAGE_HPP
#define RAINSFORD_STRINGMESSAGE_HPP

#include <string>

#include "Message.hpp"

class StringMessage : public Message {
public:
    StringMessage(Message_ID id, std::string stringData);
    std::string getData();

private:
    std::string data;
};

#endif //RAINSFORD_STRINGMESSAGE_HPP
