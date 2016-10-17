/*
 * LinkedList header file
 * © 2016 Chandler Cain (clcain@vt.edu)
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <string>

template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList<T>& other);
    void append(T data);
    T at(size_t index);
    bool empty();
    size_t length();
    size_t indexOf(T data);
    LinkedList<T> operator=(LinkedList<T>& other);
    bool operator==(LinkedList<T>& other);
    void removeAt(int index);
    void removeOne(T data);
    std::string toString(std::string separator);
private:
    struct Node
    {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };
    Node* m_Head;
    size_t m_Length;
};

#include "linkedlist.txx"

#endif // LINKEDLIST_H
