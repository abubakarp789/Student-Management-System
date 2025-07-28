#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "data_structures/StudentManagementSystem.h"

using namespace std;

// All data structure implementations have been moved to their respective files in the data_structures directory

// All method implementations have been moved to StudentManagementSystem.cpp

// handleUserInput implementation has been moved to StudentManagementSystem.cpp

int main() {
    try {
        StudentManagementSystem system;
        system.handleUserInput();
        return 0;
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "An unknown error occurred." << endl;
        return 1;
    }
}

