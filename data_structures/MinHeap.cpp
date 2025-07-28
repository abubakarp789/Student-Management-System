#include "MinHeap.h"
#include <algorithm>

MinHeap::MinHeap(int capacity) : capacity(capacity), size(0) {
    heapArray = new Student[capacity];
}

MinHeap::~MinHeap() {
    delete[] heapArray;
}

void MinHeap::insert(const Student& newStudent) {
    if (size == capacity) {
        throw std::out_of_range("Min Heap is full. Unable to insert a new student.");
    }

    heapArray[size] = newStudent;
    size++;
    heapifyUp(size - 1);
}

Student MinHeap::removeMin() {
    if (size == 0) {
        throw std::out_of_range("Min Heap is empty. Unable to remove the minimum element.");
    }

    std::swap(heapArray[0], heapArray[size - 1]);
    Student minStudent = heapArray[size - 1];
    size--;
    heapifyDown(0);

    return minStudent;
}

void MinHeap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heapArray[index].grades < heapArray[parent].grades) {
        std::swap(heapArray[index], heapArray[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void MinHeap::heapifyDown(int index) {
    int leftChild, rightChild, smallest;

    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        smallest = index;

        if (leftChild < size && heapArray[leftChild].grades < heapArray[smallest].grades) {
            smallest = leftChild;
        }

        if (rightChild < size && heapArray[rightChild].grades < heapArray[smallest].grades) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heapArray[index], heapArray[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}
