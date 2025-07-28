# Student Management System

A comprehensive C++ implementation of a Student Management System developed as part of the Data Structures and Algorithms course. This project demonstrates practical implementation of various data structures for efficient student data management.

## 📚 Course Information

**Student:** Abu Bakar  
**Instructor:** Sheraz Anjum, Ammar Ahmad Khan  
**Course:** CS-230 - Data Structure and Algorithm  
**Semester:** 3rd Semester - Fall 2023  
**Institution:** Namal University, Department of Computer Science

## 📋 Features

- **Student Data Management**: Add, update, delete, and view student records
- **Efficient Searching**: Quick lookup of student information
- **Data Organization**: Utilizes multiple data structures for optimal performance
- **GPA Calculation**: Automatic GPA calculation and management
- **Course Management**: Track student enrollment in different courses

## 🏗️ Data Structures Implemented

- **Binary Search Tree (BST)**: For efficient searching and sorting of student records
- **Max Heap**: For managing student records with highest GPAs
- **Min Heap**: For managing student records with lowest GPAs
- **Linked List**: For maintaining student records and other sequential data
- **Custom Node Implementations**: For building the above data structures

## 🚀 Getting Started

### Prerequisites

- C++ Compiler (GCC, Clang, or MSVC)
- CMake (version 3.10 or higher)
- Git (for cloning the repository)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Student-Management-System.git
   cd Student-Management-System
   ```

2. Build the project:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

3. Run the program:
   ```bash
   ./StudentManagementSystem
   ```

## 📂 Project Structure

```
Student-Management-System/
├── data_structures/
│   ├── MaxHeap.h/.cpp    # Max Heap implementation
│   ├── MinHeap.h/.cpp    # Min Heap implementation
│   ├── TreeNode.h/.cpp   # Tree Node implementation
│   ├── ListNode.h/.cpp   # Linked List Node implementation
│   ├── Student.h/.cpp    # Student class definition
│   └── StudentManagementSystem.h/.cpp  # Main system class
├── main.cpp             # Application entry point
├── DSA_Project.cbp      # Code::Blocks project file
└── README.md            # Project documentation
```

## 🛠️ Features & Usage

### Core Features
- Student record management (CRUD operations)
- Efficient search and retrieval
- GPA-based ranking using heaps
- Data persistence
- Clean console interface

### How to Use
1. Launch the program
2. Use the interactive menu to:
   - Add new students with their details
   - Search for students by ID or name
   - Update existing student information
   - Remove student records
   - View all students in sorted order
   - View top/bottom performing students using heaps

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Developed as part of the Data Structures and Algorithms course curriculum
- Special thanks to our instructors for their guidance
- Inspired by real-world student information systems

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.