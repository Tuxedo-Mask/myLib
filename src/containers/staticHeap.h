#ifndef STATIC_HEAP_H
#define STATIC_HEAP_H

#include "utils.h"

namespace myLib
{
const int default_heap_size = 100;

template <typename T, int heap_size = default_heap_size>
class staticHeap
{
public :
    staticHeap();
    staticHeap(
                T array[]
              , int array_size
              );
    void buildHeap();
    void insert(T value);
    void extract();
    bool empty() const;
    bool full() const;
    void print() const;
private:
    void remove(int node_pos);
    void siftUp(int node_pos);
    void siftDown(int node_pos);
    int siftDownPos(int node_pos);
    int root() const;
    int parent(int node_pos) const;
    int left(int node_pos) const;
    int right(int node_pos) const;
    T m_holder[heap_size];
    int m_size;
};

template <typename T, int heap_size>
staticHeap<T, heap_size>::staticHeap() : m_size(0)
{
}

template <typename T, int heap_size>
staticHeap<T, heap_size>::staticHeap(
                        T array[]
                      , int array_size
                      )
                      : m_size(array_size)
{
    copy(m_holder, array, m_size);
    buildHeap();
}

template <typename T, int heap_size>
void staticHeap<T, heap_size>::buildHeap()
{
    for(int i = m_size / 2 - 1; i >= 0; --i) {
        siftDown(i);
    }
}

template <typename T, int heap_size>
void staticHeap<T, heap_size>::insert(T value)
{
    if (full()) {
        return;
    }

    int node_pos = m_size++;
    m_holder[node_pos] = value;
    siftUp(node_pos);
}

template <typename T, int heap_size>
void staticHeap<T, heap_size>::extract()
{
    remove(root());
}

template <typename T, int heap_size>
void staticHeap<T, heap_size>::siftUp(int node_pos)
{
    while(m_holder[node_pos] >m_holder[parent(node_pos)]) {
        swap(m_holder[node_pos], m_holder[parent(node_pos)]);
        node_pos = parent(node_pos);
    }
}

template <typename T, int heap_size>
void staticHeap<T, heap_size>::remove(int node_pos)
{
    if(empty()) {
        return;
    }
    swap(m_holder[m_size - 1], m_holder[node_pos]);
    --m_size;
    siftDown(node_pos);
}

template <typename T, int heap_size>
void staticHeap<T, heap_size>::siftDown(int node_pos)
{
    int sdp = siftDownPos(node_pos);
    while (node_pos != sdp) {
        swap(m_holder[node_pos], m_holder[sdp]);
        node_pos = sdp;
        sdp = siftDownPos(node_pos);
    }
}

template <typename T, int heap_size>
int staticHeap<T, heap_size>::siftDownPos(int node_pos)
{
    int max = node_pos;

    int l = left(node_pos);
    if (-1 != l && m_holder[l] > m_holder[max]) {
        max = l;
    }
    int r = right(node_pos);
    if (-1 != r && m_holder[r] > m_holder[max]) {
        max = r;
    }
    return max;
}

template <typename T, int heap_size>
bool staticHeap<T, heap_size>::empty() const
{
    return 0 == m_size;
}

template <typename T, int heap_size>
bool staticHeap<T, heap_size>::full() const
{
    return heap_size == m_size;
}

template <typename T, int heap_size>
void staticHeap<T, heap_size>::print() const
{
    for (int i = 0; i < m_size; ++i) {
        std::cout << "m_holder[" << i << "] = " <<  m_holder[i] << std::endl;
    }
}

template <typename T, int heap_size>
int staticHeap<T, heap_size>::left(int node_pos) const
{
    int l = 2 * node_pos + 1;
    return l < m_size ? l : -1;
}

template <typename T, int heap_size>
int staticHeap<T, heap_size>::right(int node_pos) const
{
    int r = 2 * node_pos + 2;
    return r < m_size ? r : -1;
}

template <typename T, int heap_size>
int staticHeap<T, heap_size>::parent(int node_pos) const
{
    return root() == node_pos ? root() : ((node_pos + 1) / 2) - 1;
}

template <typename T, int heap_size>
int staticHeap<T, heap_size>::root() const
{
    return 0;
}

}

#endif
