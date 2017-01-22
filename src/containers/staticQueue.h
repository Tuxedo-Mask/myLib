#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <iostream>
#include <climits>
#include <cassert>

namespace myLib
{
const int default_queue_size = 100; // Used for staticQueue
template <typename T, int queue_size = default_queue_size>
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
    T holder[queue_size];
    int m_head;
    int m_tail;
    int m_size;
};

template <typename T, int queue_size>
staticQueue<T, queue_size>::staticQueue()
                           : m_head(0)
                           , m_tail(0)
                           , m_size(0)
{
}

template <typename T, int queue_size>
void staticQueue<T, queue_size>::push(T value)
{
    assert(this->size() <= queue_size);
    assert(this->size() >= 0);
    if (size() == queue_size) {
        return;
    }
    holder[m_tail++] = value;
    m_tail %= queue_size; // mod is applied to keep tail between 0 and queue_size-1;
    ++m_size;
}

template <typename T, int queue_size>
void staticQueue<T, queue_size>::pop()
{
    assert(this->size() <= queue_size);
    assert(this->size() >= 0);
    if (this->empty()) {
        return;
    }
    ++m_head;
    m_head %= queue_size;
    --m_size;
    
}

template <typename T, int queue_size>
T staticQueue<T, queue_size>::front()
{
    assert(size() <= queue_size);
    assert(size() >= 0);
    if (empty()) {
        return T();
    }
    return holder[m_head];
}

template <typename T, int queue_size>
bool staticQueue<T, queue_size>::empty()
{
    return !(this->size());
}

template <typename T, int queue_size>
int staticQueue<T, queue_size>::size()
{
    return m_size;
}
}

#endif
