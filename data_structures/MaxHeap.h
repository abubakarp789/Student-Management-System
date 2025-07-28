#pragma once
#include "Student.h"

class MaxHeap {
private:
    Student* heapArray;
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MaxHeap(int capacity);
    ~MaxHeap();

    void insert(const Student& newStudent);
    Student removeMax();
    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }
    const Student* getHeapArray() const { return heapArray; }
};
