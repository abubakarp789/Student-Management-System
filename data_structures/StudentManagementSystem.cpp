#include "StudentManagementSystem.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

StudentManagementSystem::StudentManagementSystem() 
    : stackTop(0), front(-1), rear(-1), root(nullptr), minHeap(MAX_STUDENTS), maxHeap(MAX_STUDENTS) {
    // Initialize linked list array
    for (int i = 0; i < MAX_STUDENTS; i++) {
        linkedList[i] = nullptr;
    }
}

// Core operations implementation
void StudentManagementSystem::addStudentToArray(const Student& newStudent) {
    // Implementation...
}

void StudentManagementSystem::addDetailsToLinkedList(int rollNumber, const string& course, float grade) {
    // Implementation...
}

void StudentManagementSystem::pushToStack(int rollNumber) {
    if (stackTop >= MAX_STUDENTS) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stack[stackTop++] = rollNumber;
}

int StudentManagementSystem::popFromStack() {
    if (stackTop <= 0) {
        cout << "Stack underflow!" << endl;
        return -1;
    }
    return stack[--stackTop];
}

void StudentManagementSystem::enqueueToQueue(int rollNumber) {
    if ((rear + 1) % MAX_STUDENTS == front) {
        cout << "Queue is full!" << endl;
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_STUDENTS;
    }
    queue[rear] = rollNumber;
}

int StudentManagementSystem::dequeueFromQueue() {
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int rollNumber = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_STUDENTS;
    }
    return rollNumber;
}

// BST operations
TreeNode* StudentManagementSystem::insertToBST(TreeNode* root, const Student& newStudent) {
    if (!root) {
        return new TreeNode(newStudent.rollNumber, newStudent.name);
    }
    if (newStudent.rollNumber < root->data.rollNumber) {
        root->left = insertToBST(root->left, newStudent);
    } else if (newStudent.rollNumber > root->data.rollNumber) {
        root->right = insertToBST(root->right, newStudent);
    }
    return root;
}

void StudentManagementSystem::insertToBST(const Student& newStudent) {
    root = insertToBST(root, newStudent);
}

TreeNode* StudentManagementSystem::deleteFromBST(TreeNode* root, int rollNumber) {
    if (!root) return root;
    
    if (rollNumber < root->data.rollNumber) {
        root->left = deleteFromBST(root->left, rollNumber);
    } else if (rollNumber > root->data.rollNumber) {
        root->right = deleteFromBST(root->right, rollNumber);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        
        TreeNode* temp = root->right;
        while (temp->left) temp = temp->left;
        root->data = temp->data;
        root->right = deleteFromBST(root->right, temp->data.rollNumber);
    }
    return root;
}

void StudentManagementSystem::deleteFromBST(int rollNumber) {
    root = deleteFromBST(root, rollNumber);
}

TreeNode* StudentManagementSystem::searchInBST(TreeNode* root, int rollNumber) {
    if (!root || root->data.rollNumber == rollNumber) {
        return root;
    }
    if (rollNumber < root->data.rollNumber) {
        return searchInBST(root->left, rollNumber);
    }
    return searchInBST(root->right, rollNumber);
}

TreeNode* StudentManagementSystem::searchInBST(int rollNumber) {
    return searchInBST(root, rollNumber);
}

// Heap operations
void StudentManagementSystem::insertToMinHeap(const Student& newStudent) {
    minHeap.insert(newStudent);
}

Student StudentManagementSystem::removeFromMinHeap() {
    return minHeap.removeMin();
}

void StudentManagementSystem::insertToMaxHeap(const Student& newStudent) {
    maxHeap.insert(newStudent);
}

Student StudentManagementSystem::removeFromMaxHeap() {
    return maxHeap.removeMax();
}

// Display methods
void StudentManagementSystem::displayBSTInOrder(TreeNode* root) {
    if (root) {
        displayBSTInOrder(root->left);
        cout << "Roll: " << root->data.rollNumber 
             << ", Name: " << root->data.name << endl;
        displayBSTInOrder(root->right);
    }
}

void StudentManagementSystem::displayHeap(Student* heapArray, int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << "Roll: " << heapArray[i].rollNumber 
             << ", Name: " << heapArray[i].name 
             << ", Grade: " << heapArray[i].grades << endl;
    }
}

void StudentManagementSystem::displayArrayDetails() {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (studentArray[i].rollNumber != 0) {
            cout << "Roll: " << studentArray[i].rollNumber 
                 << ", Name: " << studentArray[i].name << endl;
        }
    }
}

void StudentManagementSystem::displayLinkedList(int rollNumber) {
    if (rollNumber < 0 || rollNumber >= MAX_STUDENTS || !linkedList[rollNumber]) {
        cout << "No details found for roll number " << rollNumber << endl;
        return;
    }
    
    ListNode* current = linkedList[rollNumber];
    while (current) {
        cout << "Course: " << current->data.courses 
             << ", Grade: " << current->data.grades << endl;
        current = current->next;
    }
}

void StudentManagementSystem::displayStack() {
    if (stackTop == 0) {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = stackTop - 1; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}

void StudentManagementSystem::displayQueue() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    int i = front;
    while (i != rear) {
        cout << queue[i] << " ";
        i = (i + 1) % MAX_STUDENTS;
    }
    cout << queue[rear] << endl;
}

void StudentManagementSystem::displayBST() {
    if (!root) {
        cout << "BST is empty" << endl;
        return;
    }
    displayBSTInOrder(root);
}

void StudentManagementSystem::displayMinHeap() {
    if (minHeap.isEmpty()) {
        cout << "Min Heap is empty" << endl;
        return;
    }
    displayHeap(const_cast<Student*>(minHeap.getHeapArray()), minHeap.getSize());
}

void StudentManagementSystem::displayMaxHeap() {
    if (maxHeap.isEmpty()) {
        cout << "Max Heap is empty" << endl;
        return;
    }
    displayHeap(const_cast<Student*>(maxHeap.getHeapArray()), maxHeap.getSize());
}
