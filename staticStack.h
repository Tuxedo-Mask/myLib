#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>
#include <cassert>
#include <climits>

namespace myLib
{
const int default_stack_size = 100; // Used for staticStack
template <typename T>
class staticStack
{
public:    
    staticStack();
    void push(T value);
    void pop();
    T top();
    bool empty();
private:
    T holder[default_stack_size];
    int head;
};

template <typename T>
staticStack<T>::staticStack() : head(-1)
{
}

template <typename T>
void staticStack<T>::push(T value)
{
    assert(head < default_stack_size);
    if (head == default_stack_size - 1) {
        std::cout << "stack is full, could not push." << value << std::endl;
    } else {
        holder[++head] = value;
    }
}

template <typename T>
void staticStack<T>::pop()
{
    if (this->empty()) {
        std::cout << "stack is empty, could not pop." << std::endl;
    } else {
        --head;
    }
}

template <typename T>
T staticStack<T>::top()
{
    assert(head >= -1 && head < default_stack_size);
    if (this->empty()) {
        std::cout << "stack is empty, default value is returned as danger number" << std::endl;
        return T();
    }
    return holder[head];
}

template <typename T>
bool staticStack<T>::empty()
{
    return head == -1;
}
}

#endif
