#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::add(std::string cardCode)
{
    std::cout << "Adding card: " << cardCode << std::endl;
    Node *newNode = new Node;
    newNode->cardCode = cardCode;
    newNode->nextCard = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->nextCard = newNode;
        tail = newNode;
    }
    size++;
}

std::string LinkedList::popFirst()
{
    Node *current = head;
    if (current == NULL){
        std::cerr << "ERROR: LinkedList::popFirst() - NO CARDS IN DECK" << std::endl;
        return END_OF_DECK;
    }
    head = current->nextCard;
    std::string cardCode = current->cardCode;
    delete current;
    size--;
    return cardCode;
}

void LinkedList::print()
{
    Node *current = head;
    while (current != NULL)
    {
        std::cout << current->cardCode << std::endl;
        current = current->nextCard;
    }
}

int LinkedList::getSize()
{
    return size;
}

std::string LinkedList::getCardCode(int index)
{
    Node *current = head;
    int i = 0;
    while (current != NULL)
    {
        if (i == index)
        {
            return current->cardCode;
        }
        current = current->nextCard;
        i++;
    }
    std::cerr << "ERROR: LinkedList::getCardCode() - index out of range" << std::endl;
    return END_OF_DECK;
}

void LinkedList::clear()
{
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->nextCard;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}