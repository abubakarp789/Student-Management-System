#include "MaxHeap.h"
#include <algorithm>

MaxHeap::MaxHeap(int capacity) : capacity(capacity), size(0) {
    heapArray = new Student[capacity];
}

MaxHeap::~MaxHeap() {
    delete[] heapArray;
}

void MaxHeap::insert(const Student& newStudent) {
    if (size == capacity) {
        throw std::out_of_range("Max Heap is full. Unable to insert a new student.");
    }

    heapArray[size] = newStudent;
    size++;
    heapifyUp(size - 1);
}

Student MaxHeap::removeMax() {
    if (size == 0) {
        throw std::out_of_range("Max Heap is empty. Unable to remove the maximum element.");
    }

    std::swap(heapArray[0], heapArray[size - 1]);
    Student maxStudent = heapArray[size - 1];
    size--;
    heapifyDown(0);

    return maxStudent;
}

void MaxHeap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heapArray[index].grades > heapArray[parent].grades) {
        std::swap(heapArray[index], heapArray[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void MaxHeap::heapifyDown(int index) {
    int leftChild, rightChild, largest;

    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largest = index;

        if (leftChild < size && heapArray[leftChild].grades > heapArray[largest].grades) {
            largest = leftChild;
        }

        if (rightChild < size && heapArray[rightChild].grades > heapArray[largest].grades) {
            largest = rightChild;
        }

        if (largest != index) {
            std::swap(heapArray[index], heapArray[largest]);
            index = largest;
        } else {
            break;
        }
    }
}
