#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <iostream>
#include <cassert>
#include <climits>

#include "staticQueue.h"

namespace myLib
{
const int default_list_size = 100; // Used for staticList
template <typename T, int list_size = default_list_size>
class staticList
{
public:    
    staticList();
    void push_front(T value);
    void push_back(T value);
    bool insert(T value, int pos);
    T front() const;
    bool empty() const;
    int size() const;
    void print() const;
    void back_print() const;
private:
    T holder[list_size];
    int next[list_size];
    int prev[list_size];
    int m_head;
    int m_tail;
    int m_size;
    staticQueue<int, list_size> m_free_pos_queue;
    int free_pos();
};

template <typename T, int list_size>
staticList<T, list_size>::staticList()
                           : m_head(0)
                           , m_tail(0)
                           , m_size(0)
{
    for(int i = 0; i < list_size; ++i) {
        m_free_pos_queue.push(i);
        next[i] = prev[i] = i;
    }
}

template <typename T, int list_size>
int staticList<T, list_size>::free_pos()
{
    assert(this->size() == list_size - m_free_pos_queue.size());
    if (this->size() == list_size) {
        return -1;
    }
    int pos = m_free_pos_queue.front();
    m_free_pos_queue.pop();
    assert(0 <= pos && list_size > pos);

    return pos;
}

// Inserts after pos
template <typename T, int list_size>
bool staticList<T, list_size>::insert(T value, int pos){
    assert(this->size() <= list_size);
    assert(this->size() >= 0);
    if (size() == list_size) {
        return;
    }
    if (pos < 0 || pos > list_size - 1) {
        return;
    }

    int fp = free_pos();

    if (-1 != fp) {
    }
}

template <typename T, int list_size>
void staticList<T, list_size>::push_front(T value)
{
    assert(this->size() <= list_size);
    assert(this->size() >= 0);

    if (this->size() == list_size) {
        return;
    }

    int fp = free_pos();

    if (-1 != fp) {
        holder[fp] = value;

        if (this->empty()) {
            m_head = m_tail = next[fp] = prev[fp] = fp;
        } else {
            next[fp] = m_head;
            prev[m_head] = fp;
            m_head = fp;
        }
        ++m_size;
    }
}

template <typename T, int list_size>
void staticList<T, list_size>::push_back(T value)
{
    assert(this->size() <= list_size);
    assert(this->size() >= 0);
    if (size() == list_size) {
        return;
    }

    int fp = free_pos();

    if (-1 != fp) {
        holder[fp] = value;
        next[m_tail] = fp;
        prev[fp] = m_tail;
        m_tail = fp;
        ++m_size;
    }
}

template <typename T, int list_size>
void staticList<T, list_size>::print() const
{
    if (!empty()) {
        int n = m_head;
        for(; n != next[n]; n = next[n]) {
            std::cout << "HH::n = " << holder[n] << std::endl;
        }
        std::cout << "HH::n = " << holder[n] << std::endl;
    }
}

template <typename T, int list_size>
void staticList<T, list_size>::back_print() const
{
    if (!empty()) {
        int n = m_tail;
        for(; n != prev[n]; n = prev[n]) {
            std::cout << "HH::n = " << holder[n] << std::endl;
        }
        std::cout << "HH::n = " << holder[n] << std::endl;
    }
}

template <typename T, int list_size>
int staticList<T, list_size>::size() const
{
    return m_size;
}

template <typename T, int list_size>
bool staticList<T, list_size>::empty() const
{
    return !m_size;
}
}
#endif
