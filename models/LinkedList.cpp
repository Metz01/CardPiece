#include "LinkedList.h"


/// @brief constructor for the linked list, create a new empty linked list
LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

/// @brief remove all the cards from the linked list
LinkedList::~LinkedList()
{
    clear();
}

/// @brief add a card(cardCode) to the linked list
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

/// @brief remove the firs card(cardCode) from the linked list
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

/// @brief print the linked list
void LinkedList::print()
{
    Node *current = head;
    while (current != NULL)
    {
        std::cout << current->cardCode << std::endl;
        current = current->nextCard;
    }
}

/// @brief get the size of the linked list
int LinkedList::getSize()
{
    return size;
}

/// @brief get the card code of the card in the index position
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

/// @brief remove all the cards from the linked list
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

/// @brief remove the card(cardCode) from the linked list
void LinkedList::remove(std::string cardCode)
{
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL)
    {
        if (current->cardCode == cardCode)
        {
            if (previous == NULL)
            {
                head = current->nextCard;
            }
            else
            {
                previous->nextCard = current->nextCard;
            }
            delete current;
            size--;
            return;
        }
        previous = current;
        current = current->nextCard;
    }
}