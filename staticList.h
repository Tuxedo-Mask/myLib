#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <iostream>
#include <cassert>
#include <climits>

#include "staticQueue.h"

namespace myLib
{
const int default_list_size = 100; // Used for staticList
template <typename T>
class staticList
{
public:    
    staticList();
    void push_front(T value);
    void insert(T value, int pos);
    T front();
    bool empty();
    int size();
    void print();
private:
    T holder[default_list_size];
    int next[default_list_size];
    int m_head;
    int m_size;
    staticQueue<int> m_free_pos_queue;
    int free_pos();
};

template <typename T>
staticList<T>::staticList()
                           : m_head(-1)
                           , m_size(0)
{
    for(int i = 0; i < default_list_size; ++i) {
        m_free_pos_queue.push(i);
        next[i] = -1;
    }
}

template <typename T>
int staticList<T>::free_pos()
{
    assert(this->size() == default_list_size - m_free_pos_queue.size());
    if (this->size() == default_list_size) {
        return -1;
    }
    int pos = m_free_pos_queue.front();
    m_free_pos_queue.pop();
    assert(0 <= pos && default_list_size > pos);

    return pos;
}

// Inserts after pos
template <typename T>
void staticList<T>::insert(T value, int pos){
    assert(this->size() <= default_list_size);
    assert(this->size() >= 0);
    if (size() == default_list_size) {
        return;
    }
    if (pos < 0 || pos > default_list_size - 1) {
        return;
    }

    int fp = free_pos();

    if (-1 != fp) {
        holder[fp] = value;
        next[fp] = next[pos];
        next[pos] = fp;
        ++m_size;
    }
}

template <typename T>
void staticList<T>::push_front(T value)
{
    assert(this->size() <= default_list_size);
    assert(this->size() >= 0);
    if (size() == default_list_size) {
        return;
    }

    int fp = free_pos();

    if (-1 != fp) {
        holder[fp] = value;
        if(!this->empty()) {
            next[fp] = m_head;
        }
        m_head = fp;
        ++m_size;
    }
}

template <typename T>
void staticList<T>::print()
{
    int n = m_head;
    while(n != -1) {
        std::cout << "HH::n = " << holder[n] << std::endl;
        n = next[n];
    }
}

template <typename T>
int staticList<T>::size()
{
    return m_size;
}

template <typename T>
bool staticList<T>::empty()
{
    return !m_size;
}
}
#endif
