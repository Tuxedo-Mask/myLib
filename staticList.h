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
    void push_back(T value);
    bool insert(T value, int pos);
    T front() const;
    bool empty() const;
    int size() const;
    void print() const;
    void back_print() const;
private:
    T holder[default_list_size];
    int next[default_list_size];
    int prev[default_list_size];
    int m_head;
    int m_tail;
    int m_size;
    staticQueue<int> m_free_pos_queue;
    int free_pos();
};

template <typename T>
staticList<T>::staticList()
                           : m_head(0)
                           , m_tail(0)
                           , m_size(0)
{
    for(int i = 0; i < default_list_size; ++i) {
        m_free_pos_queue.push(i);
        next[i] = prev[i] = i;
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
bool staticList<T>::insert(T value, int pos){
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
        next[fp] = m_head;
        prev[m_head] = fp;
        m_head = fp;
        ++m_size;
    }
}

template <typename T>
void staticList<T>::push_back(T value)
{
    assert(this->size() <= default_list_size);
    assert(this->size() >= 0);
    if (size() == default_list_size) {
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

template <typename T>
void staticList<T>::print() const
{
    if (!empty()) {
        int n = m_head;
        for(; n != next[n]; n = next[n]) {
            std::cout << "HH::n = " << holder[n] << std::endl;
        }
        std::cout << "HH::n = " << holder[n] << std::endl;
    }
}

template <typename T>
void staticList<T>::back_print() const
{
    if (!empty()) {
        int n = m_tail;
        for(; n != prev[n]; n = prev[n]) {
            std::cout << "HH::n = " << holder[n] << std::endl;
        }
        std::cout << "HH::n = " << holder[n] << std::endl;
    }
}

template <typename T>
int staticList<T>::size() const
{
    return m_size;
}

template <typename T>
bool staticList<T>::empty() const
{
    return !m_size;
}
}
#endif
