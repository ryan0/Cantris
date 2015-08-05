//
// Created by Ryan on 8/4/2015.
//

#include "Messages/Message.hpp"


Message::Message(Message_ID id)
        : message_id(id)
{}

Message_ID Message::getMessage_ID() {
    return message_id;
}
