#pragma once
#include "Student.h"

class MinHeap {
private:
    Student* heapArray;
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MinHeap(int capacity);
    ~MinHeap();

    void insert(const Student& newStudent);
    Student removeMin();
    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }
    const Student* getHeapArray() const { return heapArray; }
};
