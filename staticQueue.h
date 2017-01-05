#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <iostream>
#include <cassert>
#include <climits>

namespace myLib
{
const int default_queue_size = 100; // Used for staticQueue
template <typename T>
class staticQueue
{
public:    
    staticQueue();
    void push(T value);
    void pop();
    T front();
    bool empty();
    int size();
private:
    T holder[default_queue_size];
    int m_head;
    int m_tail;
    int m_size;
};

template <typename T>
staticQueue<T>::staticQueue()
                           : m_head(0)
                           , m_tail(0)
                           , m_size(0)
{
}

template <typename T>
void staticQueue<T>::push(T value)
{
    assert(this->size() <= default_queue_size);
    assert(this->size() >= 0);
    if (size() == default_queue_size) {
        return;
    }
    holder[m_tail++] = value;
    m_tail %= default_queue_size - 1; // mod is applied to keep tail between 0 and default_queue_size-1;
    ++m_size;
}

template <typename T>
void staticQueue<T>::pop()
{
    assert(this->size() <= default_queue_size);
    assert(this->size() >= 0);
    if (this->empty()) {
        return;
    }
    ++m_head;
    m_head %= default_queue_size - 1;
    --m_size;
    
}

template <typename T>
T staticQueue<T>::front()
{
    assert(size() <= default_queue_size);
    assert(size() >= 0);
    if (empty()) {
        return T();
    }
    return holder[m_head];
}

template <typename T>
bool staticQueue<T>::empty()
{
    return !(this->size());
}

template <typename T>
int staticQueue<T>::size()
{
    return m_size;
}
}

#endif
