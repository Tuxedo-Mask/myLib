#ifndef STATIC_HEAP_H
#define STATIC_HEAP_H

#include "utils.h"

namespace myLib
{
const int default_heap_size = 100;
class staticHeap
{
public :
    staticHeap();
    staticHeap(
                int array[]
              , int array_size
              );
    void buildHeap();
    void insert(int value);
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
    int m_holder[default_heap_size];
    int m_size;
};

staticHeap::staticHeap() : m_size(0)
{
}

staticHeap::staticHeap(
                        int array[]
                      , int array_size
                      )
                      : m_size(array_size)
{
    copy(m_holder, array, m_size);
    buildHeap();
}

void staticHeap::buildHeap()
{
    for(int i = m_size / 2 - 1; i >= 0; --i) {
        siftDown(i);
    }
}

void staticHeap::insert(int value)
{
    if (full()) {
        return;
    }

    int node_pos = m_size++;
    m_holder[node_pos] = value;
    siftUp(node_pos);
}

void staticHeap::extract()
{
    remove(root());
}

void staticHeap::siftUp(int node_pos)
{
    while(m_holder[node_pos] >m_holder[parent(node_pos)]) {
        swap(m_holder[node_pos], m_holder[parent(node_pos)]);
        node_pos = parent(node_pos);
    }
}

void staticHeap::remove(int node_pos)
{
    if(empty()) {
        return;
    }
    swap(m_holder[m_size - 1], m_holder[node_pos]);
    --m_size;
    siftDown(node_pos);
}

void staticHeap::siftDown(int node_pos)
{
    int sdp = siftDownPos(node_pos);
    while (node_pos != sdp) {
        swap(m_holder[node_pos], m_holder[sdp]);
        node_pos = sdp;
        sdp = siftDownPos(node_pos);
    }
}

int staticHeap::siftDownPos(int node_pos)
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

bool staticHeap::empty() const
{
    return 0 == m_size;
}

bool staticHeap::full() const
{
    return default_heap_size == m_size;
}
void staticHeap::print() const
{
    for (int i = 0; i < m_size; ++i) {
        std::cout << "m_holder[" << i << "] = " <<  m_holder[i] << std::endl;
    }
}

int staticHeap::left(int node_pos) const
{
    int l = 2 * node_pos + 1;
    return l < m_size ? l : -1;
}

int staticHeap::right(int node_pos) const
{
    int r = 2 * node_pos + 2;
    return r < m_size ? r : -1;
}

int staticHeap::parent(int node_pos) const
{
    return root() == node_pos ? root() : ((node_pos + 1) / 2) - 1;
}

int staticHeap::root() const
{
    return 0;
}

}

#endif
