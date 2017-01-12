#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>
#include <cassert>
#include <climits>

namespace myLib
{
const int default_stack_size = 100; // Used for staticStack
template <typename T, int stack_size = default_stack_size>
class staticStack
{
public:    
    staticStack();
    void push(T value);
    void pop();
    T top();
    bool empty();
private:
    T holder[stack_size];
    int m_head;
};

template <typename T, int stack_size>
staticStack<T, stack_size>::staticStack() : m_head(-1)
{
}

template <typename T, int stack_size>
void staticStack<T, stack_size>::push(T value)
{
    assert(m_head < stack_size);
    if (m_head != stack_size - 1) {
        holder[++m_head] = value;
    }
}

template <typename T, int stack_size>
void staticStack<T, stack_size>::pop()
{
    if (!this->empty()) {
        --m_head;
    }
}

template <typename T, int stack_size>
T staticStack<T, stack_size>::top()
{
    assert(m_head >= -1 && m_head < stack_size);
    if (this->empty()) {
        return T();
    }
    return holder[m_head];
}

template <typename T, int stack_size>
bool staticStack<T, stack_size>::empty()
{
    return m_head == -1;
}
}

#endif
