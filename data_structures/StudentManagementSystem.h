#pragma once
#include "Student.h"
#include "ListNode.h"
#include "TreeNode.h"
#include "MinHeap.h"
#include "MaxHeap.h"

class StudentManagementSystem {
private:
    static const int MAX_STUDENTS = 100;
    
    Student studentArray[MAX_STUDENTS];
    ListNode* linkedList[MAX_STUDENTS];
    int stack[MAX_STUDENTS];
    int stackTop;
    int queue[MAX_STUDENTS];
    int front, rear;
    TreeNode* root;
    MinHeap minHeap;
    MaxHeap maxHeap;

    // Private helper methods
    TreeNode* insertToBST(TreeNode* root, const Student& newStudent);
    TreeNode* deleteFromBST(TreeNode* root, int rollNumber);
    TreeNode* searchInBST(TreeNode* root, int rollNumber);
    void displayBSTInOrder(TreeNode* root);
    void displayHeap(Student* heapArray, int heapSize);

public:
    StudentManagementSystem();
    
    // Core operations
    void addStudentToArray(const Student& newStudent);
    void addDetailsToLinkedList(int rollNumber, const std::string& course, float grade);
    void pushToStack(int rollNumber);
    int popFromStack();
    void enqueueToQueue(int rollNumber);
    int dequeueFromQueue();
    void insertToBST(const Student& newStudent);
    void deleteFromBST(int rollNumber);
    TreeNode* searchInBST(int rollNumber);
    void insertToMinHeap(const Student& newStudent);
    Student removeFromMinHeap();
    void insertToMaxHeap(const Student& newStudent);
    Student removeFromMaxHeap();

    // Display methods
    void displayArrayDetails();
    void displayLinkedList(int rollNumber);
    void displayStack();
    void displayQueue();
    void displayBST();
    void displayMinHeap();
    void displayMaxHeap();

    // Main user interface
    void handleUserInput();
};
