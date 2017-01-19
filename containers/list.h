#ifndef LIST_H
#define LIST_H

#include <iostream>

namespace myLib
{

template <typename T>
class ListNode
{
    template<typename>
    friend class List;
public:
    ListNode();
private:
    T m_value;
    ListNode<T>* next;
    ListNode<T>* prev;
};

template <typename T>
ListNode<T>::ListNode()
                      : m_value(0)
                      , next(0)
                      , prev(0)
{
}

template <typename T>
class List
{
public:
    List();
    ~List();
    void pushFront(T value);
    void removeFront();
    void pushBack(T value);
    void removeBack();
    unsigned int size() const;
    bool empty() const ;
    void print() const;
private:
    ListNode<T> * m_head;
    ListNode<T> * m_tail;
    unsigned int m_size;
};

template <typename T>
List<T>::List()
              : m_head(0)
              , m_tail(0)
              , m_size(0)
{
}

template <typename T>
List<T>::~List()
{
    ListNode<T>* start = m_head;
    while(start) {
        ListNode<T>* temp = start;
        start = start->next;
        delete temp;
    }
}

template <typename T>
void List<T>::pushFront(T value)
{
    ListNode<T>* node = new ListNode<T>();
    node->m_value = value;
    if (empty()) {
        m_tail = node;
    } else {
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
    ++m_size;
}

template <typename T>
void List<T>::removeFront()
{
    if (!empty()) {
        ListNode<T>* temp = m_head;
        m_head->next->prev = 0;
        m_head = m_head->next;
        delete temp;
        --m_size;
        if (1 == size()) {
            m_head = m_prev;
        }
    }
}

template <typename T>
unsigned int List<T>::size() const
{
    return m_size;
}

template <typename T>
bool List<T>::empty() const
{
    return this->size() == 0;
}

template <typename T>
void List<T>::print() const
{
    ListNode<T>* start = m_head;
    while(start) {
        std::cout << start->m_value << " ";
        start = start->next;
    }
    std::cout << std::endl;
}

}

#endif
