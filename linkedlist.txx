/*
 * LinkedList templated implementation file
 * © 2016 Chandler Cain (clcain@vt.edu)
 */

#include "linkedlist.h"
#include <sstream>

template <typename T>
LinkedList<T>::LinkedList() : m_Head(nullptr), m_Length(0) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node* current = m_Head;
    while (current != nullptr)
    {
        delete current;
        current = current->next;
    }
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>& other)
{
    Node* current = other.m_Head;
    while (current != nullptr)
    {
        append(current->data);
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::append(T data)
{
    Node* node = new Node(data);
    if (m_Head == nullptr)
    {
        m_Head = node;

    }
    else
    {
        Node* current = m_Head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node;
    }
    m_Length++;
}

template <typename T>
T LinkedList<T>::at(size_t index)
{
    Node* current = m_Head;
    size_t i = 0;
    while (i <= index && current != nullptr)
    {
        if (i == index)
        {
            return current->data;
        }
        i++;
        current = current->next;
    }
    return T();
}

template <typename T>
bool LinkedList<T>::empty()
{
    return m_Length == 0;
}

template <typename T>
size_t LinkedList<T>::length()
{
    return m_Length;
}

template <typename T>
size_t LinkedList<T>::indexOf(T data)
{
    if (m_Length == 1 && m_Head->data == data)
    {
        return 0;
    }
    else if (m_Length > 1)
    {
        Node* current = m_Head;
        size_t i = 0;
        while (current->next != nullptr)
        {
            if (current->next->data == data)
            {
                return i;
            }
            i++;
            current = current->next;
        }
    }
}

template <typename T>
LinkedList<T> LinkedList<T>::operator=(LinkedList<T>& other)
{
    *this = LinkedList(other);
    return *this;
}

template <typename T>
bool LinkedList<T>::operator==(LinkedList<T>& other)
{
    Node* thisCurrent = m_Head;
    Node* otherCurrent = other.m_Head;
    while (thisCurrent != nullptr)
    {
        if (otherCurrent == nullptr || thisCurrent->data != otherCurrent->data)
        {
            return false;
        }
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }
}

template <typename T>
void LinkedList<T>::removeAt(int index)
{
    if (m_Length > 0)
    {
        if (index == 0)
        {
            if (m_Length == 1)
            {
                delete m_Head;
                m_Head = nullptr;
            }
            else
            {
                Node* next = m_Head->next;
                delete m_Head;
                m_Head = next;
            }
        }
        else if (m_Length > 1)
        {
            Node* current = m_Head;
            size_t i = 0;
            while (current->next != nullptr)
            {
                if (i == index - 1)
                {
                    Node* next = current->next->next;
                    delete current->next;
                    current->next = next;
                    break;
                }
                i++;
                current = current->next;
            }
        }
        m_Length--;
    }
}

template <typename T>
void LinkedList<T>::removeOne(T data)
{
    if (m_Length == 1 && m_Head->data == data)
    {
        delete m_Head;
        m_Head = nullptr;
    }
    else if (m_Length > 1)
    {
        Node* current = m_Head;
        while (current->next != nullptr)
        {
            if (current->next->data == data)
            {
                Node* next = current->next->next;
                delete current->next;
                current->next = next;
                break;
            }
            current = current->next;
        }
    }
    m_Length--;
}

template <typename T>
std::string LinkedList<T>::toString(std::string separator)
{
    std::stringstream stream;
    Node* current = m_Head;
    while (current != nullptr)
    {
        stream << current->data;
        if (current->next != nullptr)
        {
             stream << separator;
        }
        current = current->next;
    }
    return stream.str();
}
