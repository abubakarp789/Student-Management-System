#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_STUDENTS = 100;

class Student {
public:
    int rollNumber;
    string name, courses;
    float grades;

    Student() : rollNumber(0), name(""), courses(""), grades(0.0) {}

    Student(int roll, const string& n, const string& c, float g) : rollNumber(roll), name(n), courses(c), grades(g) {}
};

class ListNode {
public:
    Student data;
    ListNode* next;

    ListNode(const Student& student) : data(student), next(nullptr) {}

    ~ListNode() {
        delete next;
    }
};

class TreeNode {
public:
    Student data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int rollNumber, const string& name) : data({rollNumber, name, "", 0.0}), left(nullptr), right(nullptr) {}
};

class MinHeap {
public:
    Student* heapArray;
    int capacity;
    int size;

    MinHeap(int capacity) : capacity(capacity), size(0) {
        heapArray = new Student[capacity];
    }

    ~MinHeap() {
        delete[] heapArray;
    }

    void insert(const Student& newStudent) {
        if (size == capacity) {
            cout << "Error: Min Heap is full. Unable to insert a new student." << endl;
            return;
        }

        heapArray[size] = newStudent;
        size++;
        heapifyUp(size - 1);
    }

    Student removeMin() {
        if (size == 0) {
            cout << "Error: Min Heap is empty. Unable to remove the minimum element." << endl;
            return Student();
        }

        swap(heapArray[0], heapArray[size - 1]);
        Student minStudent = heapArray[size - 1];
        size--;
        heapifyDown(0);

        return minStudent;
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heapArray[index].grades < heapArray[parent].grades) {
            swap(heapArray[index], heapArray[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
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
                swap(heapArray[index], heapArray[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }
};

class MaxHeap {
public:
    Student* heapArray;
    int capacity;
    int size;

    MaxHeap(int capacity) : capacity(capacity), size(0) {
        heapArray = new Student[capacity];
    }

    ~MaxHeap() {
        delete[] heapArray;
    }

    void insert(const Student& newStudent) {
        if (size == capacity) {
            cout << "Error: Max Heap is full. Unable to insert a new student." << endl;
            return;
        }

        heapArray[size] = newStudent;
        size++;
        heapifyUp(size - 1);
    }

    Student removeMax() {
        if (size == 0) {
            cout << "Error: Max Heap is empty. Unable to remove the maximum element." << endl;
            return Student();
        }

        swap(heapArray[0], heapArray[size - 1]);
        Student maxStudent = heapArray[size - 1];
        size--;
        heapifyDown(0);

        return maxStudent;
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heapArray[index].grades > heapArray[parent].grades) {
            swap(heapArray[index], heapArray[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
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
                swap(heapArray[index], heapArray[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
};

class StudentManagementSystem {
private:
    Student studentArray[MAX_STUDENTS];
    ListNode* linkedList[MAX_STUDENTS];
    int stack[MAX_STUDENTS];
    int stackTop = 0;
    int queue[MAX_STUDENTS];
    int front, rear;
    TreeNode* root;
    MinHeap minHeap;
    MaxHeap maxHeap;

public:
    StudentManagementSystem() : root(nullptr), minHeap(MAX_STUDENTS), maxHeap(MAX_STUDENTS) {}

    void addStudentToArray(const Student& newStudent);
    void addDetailsToLinkedList(int rollNumber, const string& course, float grade);
    void pushToStack(int rollNumber);
    int popFromStack();
    void enqueueToQueue(int rollNumber);
    int dequeueFromQueue();
    TreeNode* insertToBST(TreeNode* root, const Student& newStudent);
    TreeNode* deleteFromBST(TreeNode* root, int rollNumber);
    TreeNode* searchInBST(TreeNode* root, int rollNumber);
    void insertToMinHeap(const Student& newStudent);
    Student removeFromMinHeap();
    void insertToMaxHeap(const Student& newStudent);
    Student removeFromMaxHeap();
    void displayBSTInOrder(TreeNode* root);
    void displayHeap(Student* heapArray, int heapSize);
    void displayArrayDetails();
    void displayLinkedList(int rollNumber);
    void displayStack();
    void displayQueue();
    void displayBST();
    void displayHeap(const MinHeap& heap);
    void displayHeap(const MaxHeap& heap);
    void handleUserInput();
    void errorHandling();
};

void StudentManagementSystem::addStudentToArray(const Student& newStudent) {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (studentArray[i].rollNumber == 0) {
            studentArray[i] = newStudent;
            cout << "Student added to the array." << endl;
            return;
        }
    }

    cout << "Error: The student array is full. Unable to add a new student." << endl;
}

void StudentManagementSystem::addDetailsToLinkedList(int rollNumber, const string& course, float grade) {
    int index = -1;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (studentArray[i].rollNumber == rollNumber) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        ListNode* newNode = new ListNode(studentArray[index]);
        // Update the name and roll number from the provided parameters
        newNode->data.name = studentArray[index].name;
        newNode->data.rollNumber = studentArray[index].rollNumber;

        newNode->data.courses = course;
        newNode->data.grades = grade;
        newNode->next = linkedList[rollNumber];
        linkedList[rollNumber] = newNode;
        cout << "Details added to the linked list." << endl;
    } else {
        cout << "Error: Student not found in the array. Unable to add details to the linked list." << endl;
    }
}

void StudentManagementSystem::pushToStack(int rollNumber) {
    if (stackTop < MAX_STUDENTS - 1) {
        stack[++stackTop] = rollNumber;
        cout << "Roll number pushed to the stack." << endl;
    } else {
        cout << "Error: Stack is full. Unable to push the roll number." << endl;
    }
}

int StudentManagementSystem::popFromStack() {
    if (stackTop >= 0) {
        int poppedRollNumber = stack[stackTop--];
        cout << "Roll number popped from the stack." << endl;
        return poppedRollNumber;
    } else {
        cout << "Error: Stack is empty. Unable to pop the roll number." << endl;
        return -1;
    }
}

void StudentManagementSystem::enqueueToQueue(int rollNumber) {
    if (rear < MAX_STUDENTS - 1) {
        queue[++rear] = rollNumber;
        cout << "Roll number enqueued to the queue." << endl;
    } else {
        cout << "Error: Queue is full. Unable to enqueue the roll number." << endl;
    }
}

int StudentManagementSystem::dequeueFromQueue() {
    if (front <= rear) {
        int dequeuedRollNumber = queue[front++];
        cout << "Roll number dequeued from the queue." << endl;
        return dequeuedRollNumber;
    } else {
        cout << "Error: Queue is empty. Unable to dequeue the roll number." << endl;
        return -1;
    }
}

TreeNode* StudentManagementSystem::insertToBST(TreeNode* root, const Student& newStudent) {
    if (root == nullptr) {
        cout << "Student added to BST" << endl;
        return new TreeNode(newStudent.rollNumber, newStudent.name);
    }

    if (newStudent.rollNumber < root->data.rollNumber) {
        root->left = insertToBST(root->left, newStudent);
    } else if (newStudent.rollNumber > root->data.rollNumber) {
        root->right = insertToBST(root->right, newStudent);
    }
    return root;
}

TreeNode* StudentManagementSystem::deleteFromBST(TreeNode* root, int rollNumber) {
    if (root == nullptr) {
        cout << "Error: Student not found in the BST. Unable to delete." << endl;
        return root;
    }

    if (rollNumber < root->data.rollNumber) {
        root->left = deleteFromBST(root->left, rollNumber);
    } else if (rollNumber > root->data.rollNumber) {
        root->right = deleteFromBST(root->right, rollNumber);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            cout << "Student deleted from BST" << endl;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            cout << "Student deleted from BST" << endl;
            delete root;
            return temp;
        }

        // Node with two children
        TreeNode* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        // Copy the in-order successor's content to this node
        root->data.rollNumber = temp->data.rollNumber;
        root->data.name = temp->data.name;

        // Delete the in-order successor
        root->right = deleteFromBST(root->right, temp->data.rollNumber);
    }

    return root;
}

TreeNode* StudentManagementSystem::searchInBST(TreeNode* root, int rollNumber) {
    if (root == nullptr || root->data.rollNumber == rollNumber) {
        return root;
    }

    if (rollNumber < root->data.rollNumber) {
        return searchInBST(root->left, rollNumber);
    }

    return searchInBST(root->right, rollNumber);
}

void StudentManagementSystem::insertToMinHeap(const Student& newStudent) {
    minHeap.insert(newStudent);
    cout << "Student inserted into Min Heap" << endl;
}

Student StudentManagementSystem::removeFromMinHeap() {
    Student removedStudent = minHeap.removeMin();
    cout << "Student removed from Min Heap" << endl;
    return removedStudent;
}

void StudentManagementSystem::insertToMaxHeap(const Student& newStudent) {
    maxHeap.insert(newStudent);
    cout << "Student inserted into Max Heap" << endl;
}

Student StudentManagementSystem::removeFromMaxHeap() {
    Student removedStudent = maxHeap.removeMax();
    cout << "Student removed from Max Heap" << endl;
    return removedStudent;
}

void StudentManagementSystem::displayBSTInOrder(TreeNode* root) {
    if (root != nullptr) {
        displayBSTInOrder(root->left);
        cout << "Roll Number: " << root->data.rollNumber << ", Name: " << root->data.name << endl;
        displayBSTInOrder(root->right);
    }
}

void StudentManagementSystem::displayHeap(Student* heapArray, int heapSize) {
    for (int i = 0; i < heapSize; ++i) {
        cout << "Roll Number: " << heapArray[i].rollNumber << ", Name: " << heapArray[i].name << ", Grades: " << heapArray[i].grades << endl;
    }
}

void StudentManagementSystem::displayArrayDetails() {
    cout << "Array Details:\n";
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        cout << "Index: " << i << ", Roll Number: " << studentArray[i].rollNumber << ", Name: " << studentArray[i].name << ", Courses: " << studentArray[i].courses << ", Grades: " << studentArray[i].grades << endl;
    }
}

void StudentManagementSystem::displayLinkedList(int rollNumber) {
    if (rollNumber >= 0 && rollNumber < MAX_STUDENTS) {
        ListNode* current = linkedList[rollNumber];
        cout << "Linked List for Roll Number " << rollNumber << ":\n";

        while (current != nullptr) {
            cout << "Course: " << current->data.courses << ", Grade: " << current->data.grades << endl;
            current = current->next;
        }
    } else {
        cout << "Invalid Roll Number for linked list display." << endl;
    }
}

void StudentManagementSystem::displayStack() {
    cout << "Stack Contents:\n";
    for (int i = stackTop; i >= 0; --i) {
        cout << stack[i] << endl;
    }
}

void StudentManagementSystem::displayQueue() {
    cout << "Queue Contents:\n";
    for (int i = front; i <= rear; ++i) {
        cout << queue[i] << endl;
    }
}

void StudentManagementSystem::displayBST() {
    cout << "Binary Search Tree (BST) Contents (In-order traversal):\n";
    displayBSTInOrder(root);
}

void StudentManagementSystem::displayHeap(const MinHeap& heap) {
    cout << "Min Heap Contents:\n";
    Student* minHeapArray = heap.heapArray;
    int minHeapSize = heap.size;
    displayHeap(minHeapArray, minHeapSize);
}

void StudentManagementSystem::displayHeap(const MaxHeap& heap) {
    cout << "Max Heap Contents:\n";
    Student* maxHeapArray = heap.heapArray;
    int maxHeapSize = heap.size;
    displayHeap(maxHeapArray, maxHeapSize);
}

void StudentManagementSystem::handleUserInput() {
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add student to array\n";
        cout << "2. Add details to linked list\n";
        cout << "3. Push to stack\n";
        cout << "4. Pop from stack\n";
        cout << "5. Enqueue to queue\n";
        cout << "6. Dequeue from queue\n";
        cout << "7. Insert to BST\n";
        cout << "8. Delete from BST\n";
        cout << "9. Search in BST\n";
        cout << "10. Insert to Min Heap\n";
        cout << "11. Remove from Min Heap\n";
        cout << "12. Insert to Max Heap\n";
        cout << "13. Remove from Max Heap\n";
        cout << "14. Display Array\n";
        cout << "15. Display linked list\n";
        cout << "16. Display stack\n";
        cout << "17. Display queue\n";
        cout << "18. Display BST\n";
        cout << "19. Display Min Heap\n";
        cout << "20. Display Max Heap\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add student to array
                int roll;
                string name, courses;
                float grades;

                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Courses: ";
                getline(cin, courses);
                cout << "Enter Grades: ";
                cin >> grades;
                Student newStudent(roll, name, courses, grades);
                addStudentToArray(newStudent);
                break;
            }
            case 2: {
                // Add details to linked list
                int roll;
                string course;
                float grade;

                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Course: ";
                cin.ignore();
                getline(cin, course);
                cout << "Enter Grade: ";
                cin >> grade;

                addDetailsToLinkedList(roll, course, grade);
                break;
            }
            case 3: {
                // Push to stack
                int roll;
                cout << "Enter Roll Number: ";
                cin >> roll;
                pushToStack(roll);
                break;
            }
            case 4: {
                // Pop from stack
                int poppedRoll = popFromStack();
                if (poppedRoll != -1) {
                    cout << "Popped Roll Number: " << poppedRoll << endl;
                }
                break;
            }
            case 5: {
                // Enqueue to queue
                int roll;
                cout << "Enter Roll Number: ";
                cin >> roll;
                enqueueToQueue(roll);
                break;
            }
            case 6: {
                // Dequeue from queue
                int dequeuedRoll = dequeueFromQueue();
                if (dequeuedRoll != -1) {
                    cout << "Dequeued Roll Number: " << dequeuedRoll << endl;
                }
                break;
            }
            case 7: {
                // Insert to BST
                int roll;
                string name;

                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);

                Student newStudent(roll, name, "", 0.0);
                root = insertToBST(root, newStudent);
                break;
            }
            case 8: {
                // Delete from BST
                int roll;
                cout << "Enter Roll Number to delete: ";
                cin >> roll;
                root = deleteFromBST(root, roll);
                break;
            }
            case 9: {
                // Search in BST
                int roll;
                cout << "Enter Roll Number to search: ";
                cin >> roll;
                TreeNode* result = searchInBST(root, roll);
                if (result != nullptr) {
                    cout << "Student found in BST: Roll Number - " << result->data.rollNumber << ", Name - " << result->data.name << endl;
                } else {
                    cout << "Student not found in BST." << endl;
                }
                break;
            }
            case 10: {
                // Insert to Min Heap
                int roll;
                string name;
                float grades;

                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Grades: ";
                cin >> grades;

                Student newStudent(roll, name, "", grades);
                insertToMinHeap(newStudent);
                break;
            }
            case 11: {
                // Remove from Min Heap
                Student removedStudent = removeFromMinHeap();
                cout << "Removed Student from Min Heap: Roll Number - " << removedStudent.rollNumber << ", Name - " << removedStudent.name << ", Grades - " << removedStudent.grades << endl;
                break;
            }
            case 12: {
                // Insert to Max Heap
                int roll;
                string name;
                float grades;

                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Grades: ";
                cin >> grades;

                Student newStudent(roll, name, "", grades);
                insertToMaxHeap(newStudent);
                break;
            }
            case 13: {
                // Remove from Max Heap
                Student removedStudent = removeFromMaxHeap();
                cout << "Removed Student from Max Heap: Roll Number - " << removedStudent.rollNumber << ", Name - " << removedStudent.name << ", Grades - " << removedStudent.grades << endl;
                break;
            }
            case 14: {
                // Display array
                displayArrayDetails();
                break;
            }
            case 15: {
                // Display linked list
                int roll;
                cout << "Enter Roll Number: ";
                cin >> roll;
                displayLinkedList(roll);
                break;
            }
            case 16: {
                // Display stack
                displayStack();
                break;
            }
            case 17: {
                // Display queue
                displayQueue();
                break;
            }
            case 18: {
                // Display BST
                displayBST();
                break;
            }
            case 19: {
                // Display Min Heap
                displayHeap(minHeap);
                break;
            }
            case 20: {
                // Display Max Heap
                displayHeap(maxHeap);
                break;
            }
            case 0: {
                // Exit
                cout << "Exiting Student Management System. Goodbye!\n";
                break;
            }
            default: {
                // Invalid choice
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }
        }
    } while (choice != 0);
}

int main() {
    StudentManagementSystem system;
    system.handleUserInput();
    return 0;
}

