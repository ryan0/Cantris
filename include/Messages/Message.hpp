//
// Created by Ryan on 8/4/2015.
//

#ifndef RAINSFORD_MESSAGE_HPP
#define RAINSFORD_MESSAGE_HPP

enum Message_ID {

};

class Message {
public:
    Message(Message_ID id);
    Message_ID getMessage_ID();

private:
    Message_ID message_id;
};

#endif //RAINSFORD_MESSAGE_HPP
