#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "../utils/Constants.h"

class LinkedList
{
private:
    struct Node
    {
        std::string cardCode;
        Node *nextCard;
    };
    Node *head;
    Node *tail;
    int size;

public: 
    LinkedList();
    ~LinkedList();
    void add(std::string cardCode);
    std::string popFirst();
    void print();
    int getSize();
    std::string getCardCode(int index);
    void remove(std::string cardCode);
    void clear();
};

#endif